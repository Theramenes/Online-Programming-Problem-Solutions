/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start

// DFS 不做优化会超时
// 采用：剪枝/BFS/动规
// 
// 

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // flag indicates the final result
        // passing into DFS()
        bool flag = false;
        int* memo = new int [s.size()]();
        flag = wordBreakDFSCuttingLeaves(s, wordDict, 0, memo);
        
        delete [] memo;
        return flag;
    }
    
    // find(begin(), end(), xxx)

    // DFS剪枝
    // int[s.size()] memo : 记录从i开始到结尾是否能拆分
    // memo 0表示没有拆分过 1表示有拆分方式 -1表示无法拆分
    bool wordBreakDFSCuttingLeaves(string& s, vector<string>& wordDict, int start, int * memo){
        if(start == s.size())
            return true;

        // 如果已经拆分过返回结果
        if(memo[start] != 0)
            return memo[start] > 0 ? true : false;

        vector<string>::iterator it;
        for(int partition_end = start; partition_end < s.size(); partition_end++){
            it = find(wordDict.begin(), wordDict.end(), s.substr(start, partition_end - start + 1));
            
            if(it == wordDict.end())
                continue;

            if(wordBreakDFSCuttingLeaves(s, wordDict, partition_end + 1, memo)){
                memo[start] = 1;
                return true;
            }
        }
        memo[start] = -1;
        return false; 
    }

    void wordBreakBFS(){

    }

    void wordBreakDP(){

    }

};
// @lc code=end

