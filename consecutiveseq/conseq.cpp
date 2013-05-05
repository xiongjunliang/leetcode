

//  Palindrome Partition I
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int longest = 1;
        map<int, node> node_map;
        set<int> num_set;
        for (int i = 0; i < num.size(); ++i) {
            if (num_set.find(num[i]) != num_set.end()) {
                continue;
            }
            num_set.insert(num[i]);
            node x(num[i]);
            map<int, node>::iterator lower_iter = node_map.find(num[i] - 1);
            map<int, node>::iterator high_iter = node_map.find(num[i] + 1);
            if (lower_iter != node_map.end()) {
                x.begin = lower_iter->second.begin;
            }
            if (high_iter != node_map.end()) {
                x.end = high_iter->second.end;
            }
            map<int, node>::iterator begin_iter = node_map.find(x.begin);
            if (begin_iter == node_map.end()) {
                node_map.insert(pair<int, node>(x.begin, x));
            } else {
                begin_iter->second.end = x.end;
            }
            map<int, node>::iterator end_iter = node_map.find(x.end);
            if (end_iter == node_map.end()) {
                node_map.insert(pair<int, node>(x.end, x));
            } else {
                end_iter->second.begin = x.begin;
            }
            int length = x.end - x.begin + 1;
            if (length > longest) {
                longest = length;
            }
        }
        return longest;
    }
private:
    struct node {
        int begin;
        int end;
        node(int num) : begin(num), end(num) {}
    };
};


int main() 
{
    Solution s;
    int x;
    vector<int> num;
    while(cin >> x) {
        num.push_back(x);
    }
    int longest = s.longestConsecutive(num);
    
    cout << longest << endl;
    return 0;
}


