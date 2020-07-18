/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// 最初的思路 动规
// 由于负数的存在 用一个pair来保存绝对值最大的 和正值最大的
// dp[i] -> 以nums[i]为结尾的子数组的乘积最大值对
// 绝对值最大 可以保存负数 但必须绝对值最大
// 正值则保证是最大 且为正
// 方法错误
// 错误用例 [2,-5,-2,-4,3]

// 不用动规 记录包括nums[i]的子数组的 
// 最大正数乘积max_positive 和最大负乘积max_negative
// 
// 如果该位 == 0 则设置为1
// 
#include<vector>
#include<utility>

// @lc code=start
class Solution {
public:
    int maxProduct(std::vector<int>& nums) {

        int result = 0x80000000;
        maxProductDP(nums, result);

        return result; 
    }

    void maxProductDP(std::vector<int>& nums, int& result){
        int temp1, temp2;
        int max_positive = 1, max_negative = 1;
        for(int i = 0; i < nums.size(); i++){
            
            temp1 = max_positive * nums[i];
            temp2 = max_negative * nums[i];

            int temp_max = temp1 > temp2 ? temp1 : temp2;
            result = result > temp_max ? result : temp_max;

            max_positive = getMaxPositive(temp1, temp2);
            max_negative = getMaxNegative(temp1, temp2);

        }

    }

private:
    int getMaxPositive(int a, int b){
        if(a > 0 || b > 0)
            return a > b ? a : b;
        return 1;
    }

    int getMaxNegative(int a, int b){
        if(a < 0 || b < 0)
            return a < b ? a : b;
        return 1;
    }
};
// @lc code=end

