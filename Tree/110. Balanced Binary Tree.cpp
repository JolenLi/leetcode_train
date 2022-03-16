/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getLength(TreeNode* root){
        if(!root) return 0;
        int left = getLength(root->left);
        int right = getLength(root->right);
        if(left==-1||right==-1||abs(right-left)>1)
            return -1;
        else
            return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        return getLength(root)>=0?1:0;
    }
};//
// Created by Jolen on 2022/3/15.
//

