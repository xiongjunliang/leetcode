
//  Substring with Concatenation of All Words
//  http://leetcode.com/onlinejudge#question_30
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, int> index;
        vector<int> count1(L.size(), 0);
        int id = 0;
        for (int i = 0; i < L.size(); ++i) {
            map<string, int>::iterator iter = index.find(L[i]);
            if (iter != index.end()) {
                count1[iter->second] ++; 
            } else {
                index.insert(make_pair(L[i], id));
                count1[id] = 1;
                id ++;
            }
        }
        vector<int> ret;
        int step = L[0].length();
        for (int i = 0; i < step; ++i) {
            int start = i;
            int uniq_cnt = 0;
            vector<int> count(L.size(), 0); 
            for (int j = start; (j + step) <= S.length(); j += step) {
                string str = S.substr(j, step);
                map<string, int>::iterator iter = index.find(str);
                /*
                cout << j << " " << str << endl;
                for (int k = 0; k < L.size(); ++k) {
                    cout << count[k] << " ";
                }
                cout << endl;
                cout << "ret:";
                for (int k = 0; k < ret.size(); ++k) {
                    cout << ret[k] << " ";
                }
                cout << endl;
                */
                if (iter != index.end()) {
                    count[iter->second] ++;
                    if (count[iter->second] <= count1[iter->second]) {
                        uniq_cnt += 1;
                        if (uniq_cnt == L.size()) {
                            for (;start <= j; start += step) {
                                string t = S.substr(start, step);
                                count[index[t]] --;
                                if (count[index[t]] < count1[index[t]]) {
                                    if ((((j+step)-start)/step) == uniq_cnt) {
                                        ret.push_back(start); 
                                    }
                                    uniq_cnt --;
                                    start += step;
                                    break;
                                }
                            } 
                        
                        }
                    }
                } else {
                    for (int k = 0; k < L.size(); ++k) {
                        count[k] = 0;
                    }
                    uniq_cnt = 0;
                    start = j + step;
                }
            } 
        }
        return ret;
    }
};

int main() {
    string s = "aaa";
    vector<string> l;
    l.push_back("a");
    l.push_back("a");
    Solution sl;
    vector<int> ret = sl.findSubstring(s, l);
    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}

