class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result;
        if (strs.empty()) {
            return result;
        }
        string b = strs[0];
        for (int i = 0; i < b.length(); ++i) {
            char c = b[i];
            int j;
            for (j = 0; j < strs.size(); ++j) {
                if (c != strs[j][i]) {
                    break;
                }
            }
            if (j == strs.size()) {
                result.push_back(c);
            } else {
                break;
            }
        }
        return result;
        
    }
};
