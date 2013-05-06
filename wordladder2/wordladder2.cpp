
//  Word Ladder II 
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <tr1/unordered_set>

using namespace std;
using std::tr1::unordered_set;

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, 
            unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> words;
        words.push_back(start);
        words.push_back(end);
        for (unordered_set<string>::iterator iter = dict.begin(); 
                iter != dict.end(); iter ++) {
            words.push_back(*iter);
        }
        vector<vector<bool> > map;
        vector<int> distance;
        deque<int> queue;
        prepare_map(words, map, distance);
        distance[0] = 0;
        queue.push_back(0);
        
        while (!queue.empty()) {
            int n = queue.front();
            for (int i = 0; i < words.size(); ++i) {
                if (map[n][i]) {
                    if ((distance[n] + 1) < distance[i]) {
                        distance[i] = distance[n] + 1;
                        queue.push_back(i);
                    }
                }
            }
            queue.pop_front();
        }
        
        vector<vector<string> > result;
        vector<string> path;
        path.resize(words.size());
        find_path(words, result, distance, map, path, 0, 0);
        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        return result;


    }
private:
    void find_path(const vector<string>& dict, vector<vector<string> >& result, const vector<int> & distance,
            const vector<vector<bool> >& map, vector<string>& path, int index, int dest) {
        path[index] = dict[dest];
        if (dest == 1) {
            vector<string> p;
            for (int i = 0; i <= index; ++i) {
                p.push_back(path[i]);
            }
            result.push_back(p);
        }
        for (int i = 1; i < dict.size(); i ++) {
            if (map[dest][i] && distance[i] == (distance[dest] + 1)) {
                find_path(dict, result, distance, map, path, index + 1, i);
            }
        }
    }
    void prepare_map(vector<string>& dict, vector<vector<bool> >& map,
            vector<int>& distance) {
        for (int i = 0; i < dict.size(); ++i)  {
            map.push_back(vector<bool>(dict.size(), false));
            distance.push_back(INT_MAX);
        }
        for (int i = 0; i < dict.size(); ++i) {
            for (int j = i + 1; j < dict.size(); ++j) {
                if (transferable(dict[i], dict[j])) {
                    map[i][j] = true;
                    map[j][i] = true;
                }
            }
        }
    }
    bool transferable(const string& left, const string& right) {
        if (left.length() != right.length()) {
            return false;
        }
        int diff_cnt = 0;
        for (int i = 0; i < left.length(); ++i) {
            if (left[i] != right[i]) {
                if (diff_cnt == 1) {
                    return false;
                }
                diff_cnt ++;
            }
        }
        return (diff_cnt == 1);
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
    solution.findLadders(start, end, dict);
    
    return 0;
}
