
//  Two Sum 
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        map<int, int> indexer;
        for (int i = 0; i < numbers.size(); ++i) {
            map<int, int>::iterator iter = indexer.find(numbers[i]);
            if (iter == indexer.end()) {
                indexer.insert(pair<int, int>(numbers[i], i));
            } else {
                iter->second = i;
            }
        }
        for (int i = 0; i < numbers.size(); ++i) {
            map<int, int>::const_iterator iter = indexer.find(target - numbers[i]);
            if (iter != indexer.end()) {
                result.push_back(i + 1);
                result.push_back(iter->second + 1);
                break;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
