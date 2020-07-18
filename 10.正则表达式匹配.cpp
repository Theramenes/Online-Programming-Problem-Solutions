/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include<vector>
#include<string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        string str = ' ' + s;
        string pattern =  ' ' + p;
        vector<vector<bool>> dp(str.size() + 1, vector<bool>(pattern.size() + 1, false));

        regularExpressionDP(str, pattern, dp);
        return dp[str.size()][pattern.size()];
    }

    void regularExpressionDP(string& str, string& pattern, vector<vector<bool>>& dp){
        // initialization
        // 在初始换的时候遇到的问题 如果str是空字符串
        // 一种方法是在字符前加上空格**
        // 如果不加空格就不能用int i = 1开始（因为str.size() == 0）
        dp[0][0] = true;

        for(int i = 1; i <= str.size(); i++){
            for(int j = 1; j <= pattern.size(); j++){
                if(pattern[j-1] == '*'){
                    if(str[i-1] == pattern[j-2] || pattern[j-2] == '.')
                        dp[i][j] = dp[i][j-2] || dp[i][j-1] || dp[i-1][j];
                    else
                        dp[i][j] = dp[i][j-2];
                }
                else{
                    dp[i][j] = ((str[i-1] == pattern[j-1]) || pattern[j-1] == '.') ? dp[i-1][j-1] : false; 

                }
            }
        }


    }
};
// @lc code=end

