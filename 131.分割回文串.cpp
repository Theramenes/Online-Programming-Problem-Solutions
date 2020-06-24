/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start

#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.size() == 0)
            return partition_result;
        
        DFS(s, 0, s.size());
        return partition_result;
    }
    
    void DFS(string& s, int start, int end){
        // 如果达到末尾，分割完毕，返回结果
        if(start == end){
            partition_result.push_back(temp_partition_result);
            return;
        }
        
        for(int partition_end = start; partition_end < end; partition_end++ ){
            if(!isPalindrome(s, start, partition_end))
                continue;
            
            temp_partition_result.push_back(s.substr(start, partition_end - start + 1));
            DFS(s, partition_end + 1, end);
            temp_partition_result.pop_back();
            
        }
    }
    
    bool isPalindrome(string& s, int left, int right){
        while((left < right) && s[left] == s[right]){
            left++;
            right--;
        }
        return left >= right;
    }
    
private:
    vector<string> temp_partition_result;
    vector<vector<string>> partition_result;

};