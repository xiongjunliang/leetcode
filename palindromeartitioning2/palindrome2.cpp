
//  Palindrome Partition II
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int>  palindrome;
        int length = s.length();
        vector< vector<bool> > map;
        prepalindromic(s, map, palindrome);
        for (int i = 1; i < s.length(); ++i) {
            int count = palindrome[i - 1] + 1; 
            for (int j = i - 1; j >= 0; j--) {
                if (map[j][i]) {
                    if (j == 0) {
                        count = 0;
                    } else {
                        int cnt = 0;
                        if (j > 0) {
                            cnt = palindrome[j - 1] + 1;
                        } else {
                            cnt = 1;
                        }
                        if (cnt < count) {
                            count = cnt;
                        }
                    }
                }
            }
            palindrome[i] = count;
        }
        return palindrome[s.length() - 1];

    }
private:
    void prepalindromic(const string& s, vector< vector<bool> >& map, vector<int>& palindrome) {
        int length = s.length();
        for (int i = 0; i < s.length(); ++i) {
            map.push_back(vector<bool>(s.length(), false));
            palindrome.push_back(0);
        }
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0;(i - j) >=0 && (i + j) < length; ++j) {
                if (s[i - j] == s[i + j]) {
                    map[i - j][i + j] = true;
                } else {
                    break;
                }
            }
            for (int left = i, right = i + 1; left >= 0 && right < length; left--, right++) {
                if (s[left] == s[right]) {
                    map[left][right] = true;
                } else {
                    break;
                }
            }
        }
    
    }

};

int main() 
{
    Solution s;
    string str;
    while (cin >> str) {
        cout << s.minCut(str) << endl;
    }

    return 0;
}

