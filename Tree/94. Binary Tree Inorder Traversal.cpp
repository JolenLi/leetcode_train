//
// Created by Jolen on 2021/6/21.
//

#include<vector>
#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> vec;
vector<int> inorderTraversal(TreeNode* root) {
    if(root==nullptr) return vec;
    inorderTraversal(root->left);
    vec.push_back(root->val);
    inorderTraversal(root->right);
    return vec;
}