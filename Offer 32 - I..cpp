//
// Created by Jolen on 2021/6/21.
//


#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> levelOrder(TreeNode* root) {
    queue<TreeNode *> list;
    vector<int> vec;
    list.push(root);

    while(!list.empty())
    {
        auto head = list.front();
        list.pop();
        if(head == nullptr)
            continue;
        vec.push_back(head->val);
        list.push(head->left);
        list.push(head->right);
    }
    return vec;
}

