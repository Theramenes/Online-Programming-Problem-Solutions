/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include<stdio.h>
#include<vector>

using namespace std;

// DFS 
// 记录 currentMinPath 

// DFS超时

// 用动规？

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int * dp = new int[triangle.size() + 1]();
        minPathSumDP(triangle, dp);

        return dp[0];
    }

    void minPathSumDP(vector<vector<int>>& triangle, int *dp){
        int triangle_size = triangle.size();
        for(int i = triangle_size - 1; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[j] = (dp[j] < dp[j + 1] ? dp[j] : dp[j + 1]) + triangle[i][j];
            }
        } 
    }
};

// @lc code=end
