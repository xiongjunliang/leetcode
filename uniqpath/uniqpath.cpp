class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        for (int i = 0; i < m; ++i) {
            result.push_back(1);
        }
        for (int j = 2; j <= n; ++j) {
            for (int i = 1; i < m; ++i) {
                result[i] += result[i-1];
            }
        }
        return result[m-1];
    }
};
