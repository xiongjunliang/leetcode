
//  Word Ladder II
//  http://leetcode.com/onlinejudge#question_126
//  unordered_map is Different from MAP 
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <tr1/unordered_map>
#include <deque>
#include <tr1/unordered_set>

using namespace std;
using std::tr1::unordered_set;
using std::tr1::unordered_map;

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, 
            unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (dict.find(start) == dict.end()) {
            dict.insert(start);
        }
        if (dict.find(end) == dict.end()) {
            dict.insert(end);
        }
        unordered_map<string, int> dict_map;
        vector<string> strs;
        int n = 0;
        unordered_set<string>::iterator iter = dict.begin();
        for (; iter != dict.end(); ++iter, ++n) {
            dict_map.insert(make_pair(*iter, n));
            strs.push_back(*iter);
        }
        vector<vector<int> > graph(n, vector<int>());
        vector<set<int> > path(n, set<int>());
        vector<bool> visited(n, false);
        vector<int> cost(n, INT_MAX);
        for (iter = dict.begin(); iter != dict.end(); ++iter) {
            string s = *iter;
            for (int l = 0; l < s.length(); ++l) {
                char c = s[l];
                for (char x = 'a'; x <= 'z'; ++x) {
                    if (x != c) {
                        s[l] = x;
                        unordered_map<string, int>::iterator miter = dict_map.find(s);
                        if (miter != dict_map.end()) {
                            int idx = dict_map.find(*iter)->second;
                            graph[idx].push_back(miter->second);
                        }
                    }
                }
                s[l] = c;
            }
        }
        int start_idx = dict_map.find(start)->second;  
        int end_idx = dict_map.find(end)->second;  
        deque<int> queue;
        cost[start_idx] = 0;
        queue.push_back(start_idx);
        while (!queue.empty()) {
            int x = queue.front();
            visited[x] = true;
            if (x == end_idx) {
                break;
            }
            for (int i = 0; i < graph[x].size(); ++i) {
                if ((cost[x] + 1) < cost[graph[x][i]]) {
                    cost[graph[x][i]] = cost[x] + 1;
                    path[graph[x][i]].clear();
                    path[graph[x][i]].insert(x);
                    queue.push_back(graph[x][i]);
                } else if ((cost[x] + 1) == cost[graph[x][i]]){
                   path[graph[x][i]].insert(x);
                }
            }
            queue.pop_front();
        }
        vector<vector<string> > ret;
        if (visited[end_idx]) {
            vector<string> rpath(cost[end_idx] + 2);
            build_path(ret, path, rpath, strs, start_idx, end_idx, 0); 
        }
        return ret;
    }
    void build_path(vector<vector<string> >& result, 
            vector<set<int> >& path, vector<string>& rpath,
            vector<string>& strs, int start, int current, int idx) {
        rpath[idx] = strs[current];
        if (current == start) {
            vector<string> p;
            for (int i = idx; i >= 0; --i) {
                p.push_back(rpath[i]);
            }
            result.push_back(p);
            return;
        }
        set<int>::iterator iter = path[current].begin();
        for (; iter != path[current].end(); ++iter) {
            build_path(result, path, rpath, strs, start, *iter, idx + 1);
        }
    }
};
int main() {
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    Solution s;
    vector<vector<string> > ret = s.findLadders("hit", "cog", dict);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] <<  " ";
        }
        cout << endl;
    }
    return 0;
}

