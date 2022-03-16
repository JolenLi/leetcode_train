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

pair<int, int> getNextMoney(TreeNode *root) {
    if (!root)return {0, 0};
    pair<int, int> leftMoney = getNextMoney(root->left);
    pair<int, int> rightMoney = getNextMoney(root->right);
    int robMoney = leftMoney.second + rightMoney.second + root->val;
    int noRob = max(leftMoney.first, leftMoney.second)+ max(rightMoney.first, rightMoney.second);
    return {robMoney, noRob};
}

int rob(TreeNode *root) {
    pair<int, int> robMoney = getNextMoney(root);
    return max(robMoney.first, robMoney.second);
}

int main() {
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *A = new TreeNode(10, a, b);
    TreeNode *B = new TreeNode(20, c, d);
    TreeNode *head = new TreeNode(100, A, B);

}
