
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
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        dict.insert(start);
        dict.insert(end);
        unordered_set<string>::iterator iter;
        unordered_map<string, int> index;
        int id = 0;
        for (iter = dict.begin(); iter != dict.end(); ++iter) {
            index.insert(make_pair(*iter, id));
            id ++;
        }
        vector<unordered_set<int> > dict_map(id, unordered_set<int>());
        init(index, dict_map);

        vector<int> cost(id, INT_MAX);
        deque<int> q;
        q.push_back(index[start]);
        cost[index[start]] = 1;
        while (!q.empty()) {
            int x = q.front();
            unordered_set<int>::iterator iter = dict_map[x].begin();
            while (iter != dict_map[x].end()) {
                if ((cost[x] + 1) < cost[*iter]) {
                    cost[*iter] = cost[x] + 1;
                    q.push_back(*iter);
                }
                iter ++;
            }
            q.pop_front();
        }
        if (cost[index[end]] == INT_MAX) {
            return 0;
        } else {
            return cost[index[end]];
        }
    }
    void init(unordered_map<string, int>& index, vector<unordered_set<int> >& map) {
        unordered_map<string, int>::iterator iter = index.begin();
        while (iter != index.end()) {
            string s = iter->first;
            for (int i = 0; i < s.length(); ++i) {
                char ch = s[i];
                for (char x = 'a'; x <= 'z'; ++x) {
                    if (x != ch) {
                        s[i] = x;
                    }
                    if (index.find(s) != index.end()) {
                        map[iter->second].insert(index[s]);
                    }
                }
                s[i] = ch;
            }
            iter ++;
        }
    }

};

int main() {
    return 0;
}

