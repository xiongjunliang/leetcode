class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (obstacleGrid.empty()) {
            return 0;
        }
        int height = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        vector<vector<int> > result;
        vector<int> v;
        for (int i = 0; i <= width; ++i) {
            v.push_back(0);
        }
        for (int i = 0; i <= height; ++i) {
            result.push_back(v);
        }
        if (obstacleGrid[0][0] == 0) {
            result[1][1] = 1;
        }
        for (int j = 2; j <= width; ++j) {
            if (obstacleGrid[0][j-1] == 1) {
                    result[1][j] = 0;
                } else {
                    result[1][j] = result[1][j-1];
                }
                
        }
        
        for (int i = 2; i <= height; ++i) {
            for (int j = 1; j <= width; ++j) {
                if (obstacleGrid[i-1][j-1] == 1) {
                    result[i][j] = 0;
                } else {
                    result[i][j] = result[i][j-1] + result[i-1][j];
                }
                
            }
        }
        
        return result[height][width];
    }
};
