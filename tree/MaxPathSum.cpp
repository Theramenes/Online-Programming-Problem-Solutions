/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
 *给定一个非空二叉树，返回其最大路径和。
 *
 *本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 *
 *示例 1:
 *
 *输入: [1,2,3]
 *
 *       1
 *      / \
 *     2   3
 *
 *输出: 6
 *
 *示例 2:
 *
 *输入: [-10,9,20,null,null,15,7]
 *
 *   -10
 *   / \
 *  9  20
 *    /  \
 *   15   7
 *
 *输出: 42
 *
 */


#include <string>
#include <iostream>
#include <queue>
#include <sstream>
#include <algorithm> 

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 后序遍历节点，分别得到节点左子树最大路径+自身left_mid, 
// 节点右子树最大路径+自身 right_mid, 
// 以及包括了左中右的路径的最大值 left_mid_right;
// 
// 记录最大值 其中只返回left_mid, right_mid中最大的给递归调用者
// 因为只有这两个路径还能连上上一层节点。
// 修正：还有mid本身也有可能！
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int final_max = numeric_limits<int>::min(), current_max = numeric_limits<int>::min();
        postOrderTravers(root, current_max, final_max);
        return final_max;
    }

    void postOrderTravers(TreeNode* root, int& current_max, int& final_max){
        if(root == NULL)
            return;

        int left_max = 0, right_max = 0;
        
        // get max sum from left sub tree
        postOrderTravers(root->left, left_max, final_max);
        // get max sum from right sub tree
        postOrderTravers(root->right, right_max, final_max);
        
        int left_mid = root->val + left_max, right_mid = root->val + right_max, 
            left_mid_right = root->val + left_max + right_max; 
            
        // 比较节点左子树最大路径
        current_max = maxAmongThree(left_mid, right_mid, root->val);

        final_max = maxAmongThree(final_max, left_mid_right, current_max);
        return;
    }

    int maxAmongThree(int& a, int& b, int& c){
        int temp = a > b ? a : b;
        return temp > c ? temp : c;
    }
};


/* *************************** */

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().maxPathSum(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}