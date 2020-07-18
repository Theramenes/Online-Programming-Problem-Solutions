/*
 * @lc app=leetcode.cn id=1139 lang=cpp
 *
 * [1139] 最大的以 1 为边界的正方形
 */

#include<vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int *right = new int[grid.size() * grid[0].size()]();
        int *down = new int[grid.size() * grid[0].size()]();
        int *up = new int[grid.size() * grid[0].size()]();
        int *left = new int[grid.size() * grid[0].size()]();

        buildRightMaxOne(grid, right);
        buildDownMaxOne(grid, down);
        buildUpMaxOne(grid, up);
        buildLeftMaxOne(grid, left);

        return getLargest1BorderSquare(grid, right, down, up, left);
    }

    int getLargest1BorderSquare(vector<vector<int>>& grid, int* right, int* down, int* up, int* left){
        int max_len = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    int max_len_right = right[i * grid[0].size() + j];
                    int max_len_down = down[i * grid[0].size() + j];
                    int max_len_right_down = max_len_right < max_len_down ? max_len_right : max_len_down;
                    for(;max_len_right_down > 0; max_len_right_down--){
                        int opposite_i = i - 1 + max_len_right_down;
                        int opposite_j = j - 1 + max_len_right_down;
                        
                        int max_len_left = left[opposite_i * grid[0].size() + opposite_j];
                        int max_len_up = up[opposite_i * grid[0].size() + opposite_j];

                        int max_len_left_up = max_len_left < max_len_up ? max_len_left : max_len_up;
                        if(max_len_left_up >= max_len_right_down){
                            max_len = max_len > max_len_right_down ? max_len : max_len_right_down;
                            break;
                        }
                    }
                }

                if(i + max_len > grid.size() && j + max_len > grid[0].size())
                    return max_len * max_len;
            }
        }

        return max_len * max_len;
    }

    void buildRightMaxOne(vector<vector<int>>& grid, int * dp){
        for(int i = 0; i < grid.size(); i++){
            for (int j = grid[0].size() - 1; j >= 0; j--){
                if(j == grid[0].size() - 1){
                    dp[i * grid[0].size() + j] = grid[i][j];
                    continue;
                }
                if(!grid[i][j])
                    dp[i * grid[0].size() + j] = 0;
                else
                    dp[i * grid[0].size() + j] = 1 + dp[i * grid[0].size() + j + 1];
            }
        }
    }

    void buildDownMaxOne(vector<vector<int>>& grid, int * dp){
        for(int i = grid.size() - 1; i >= 0; i--){
            for (int j = 0; j < grid[0].size(); j++){
                if(i == grid.size() - 1){
                    dp[i * grid[0].size() + j] = grid[i][j];
                    continue;
                }
                if(!grid[i][j])
                    dp[i * grid[0].size() + j] = 0;
                else
                    dp[i * grid[0].size() + j] = 1 + dp[(i + 1) * grid[0].size() + j];
            }
        }
    }

    void buildLeftMaxOne(vector<vector<int>>& grid, int * dp){
        for(int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if(j == 0){
                    dp[i * grid[0].size() + j] = grid[i][j];
                    continue;
                }
                if(!grid[i][j])
                    dp[i * grid[0].size() + j] = 0;
                else
                    dp[i * grid[0].size() + j] = 1 + dp[i * grid[0].size() + j - 1];
            }
        }
    }

    void buildUpMaxOne(vector<vector<int>>& grid, int * dp){
        for(int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if(i == 0){
                    dp[i * grid[0].size() + j] = grid[i][j];
                    continue;
                }
                if(!grid[i][j])
                    dp[i * grid[0].size() + j] = 0;
                else
                    dp[i * grid[0].size() + j] = 1 + dp[(i - 1) * grid[0].size() + j];
            }
        }
    }


};
// @lc code=end

