
//  Word Ladder  
//  Author: Xiongjun Liang
//  http://leetcode.com/onlinejudge#question_127
//
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;
using std::tr1::unordered_set;
using std::tr1::unordered_map;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string>& dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> words;
        vector<set<int> > paths;
        unordered_map<string, int> dict_map;
        dict.insert(start);
        dict.insert(end);
        int i = 0;
        for (unordered_set<string>::iterator iter = dict.begin(); 
                iter != dict.end(); iter ++, i ++) {
            words.push_back(*iter);
            dict_map.insert(pair<string, int>(*iter, i));
            paths.push_back(set<int>());
        }
        vector<vector<int> > map;
        vector<int> distance;
        deque<int> queue;
        prepare_map(dict, dict_map, words, map, distance);

        int start_index = dict_map.find(start)->second;
        int end_index = dict_map.find(end)->second;
        distance[start_index] = 1;
        queue.push_back(start_index);
        
        while (!queue.empty()) {
            int n = queue.front();
            for (int i = 0; i < map[n].size(); ++i) {
                if ((distance[n] + 1) < distance[map[n][i]]) {
                    distance[map[n][i]] = distance[n] + 1;
                    paths[map[n][i]].clear();

                    paths[map[n][i]].insert(n);
                    queue.push_back(map[n][i]);
                } else if ((distance[n] + 1) == distance[map[n][i]]) {
                    paths[map[n][i]].insert(n);
                }
            }
            queue.pop_front();
        }
        if (distance[end_index] == INT_MAX) {
            return 0;
        }
        return distance[end_index]; 
    }
private:
    void prepare_map(unordered_set<string>& dict_set, unordered_map<string, int> dict_map, 
            vector<string>& dict, vector<vector<int> >& map,
            vector<int>& distance) {
        for (int i = 0; i < dict.size(); ++i)  {
            map.push_back(vector<int>());
            distance.push_back(INT_MAX);
        }
        for (int i = 0; i < dict.size(); ++i) {
            for (int j = 0; j < dict[i].length(); ++j) {
                string word = dict[i];
                char ch = word[j];
                for (char c = 'a'; c <= 'z'; c ++) {
                    if (c != ch) {
                        word[j] = c;
                        unordered_set<string>::const_iterator iter = 
                            dict_set.find(word);
                        if (iter != dict_set.end()) {
                            int index = dict_map.find(*iter)->second;
                            map[i].push_back(index);
                        }
                    }
                }
            }
        }
    }
};


int main() {
    int x;
    string s;
    unordered_set<string> dict;
    cin >> x;
    while (x--) {
        cin >> s;
        dict.insert(s);
    }
    
    string start;
    string end;
    cin >> start >> end;
    cout << "read finish" << endl;
    Solution solution;
    cout << solution.ladderLength(start, end, dict) << endl;
    
    return 0;
}
