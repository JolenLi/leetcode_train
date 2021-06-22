//
// Created by Jolen on 2021/6/22.
//


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printTree(TreeNode *root) {
    queue<TreeNode *> list;
    list.push(root);
    while (!list.empty()) {
        int numLevel = list.size();
        for (int i = 0; i < numLevel; i++) {
            auto head = list.front();
            list.pop();
            if (head == nullptr)
                continue;
            cout << head->val << " ";
            list.push(head->left);
            list.push(head->right);
        }
        cout << endl;
    }
}

bool check(TreeNode *root, int64_t min, int64_t max) {
    if (root == nullptr)
        return true;
    if (root->val >= max || root->val <= min)
        return false;
    return check(root->left, min, root->val) && check(root->right, root->val, max);
}

bool isValidBST(TreeNode *root) {
    return check(root, INT64_MIN, INT64_MAX);
}

int main() {
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(11);
    TreeNode *c = new TreeNode(150);
    TreeNode *d = new TreeNode(300);
    TreeNode *A = new TreeNode(10, a, b);
    TreeNode *B = new TreeNode(200, c, d);
    TreeNode *head = new TreeNode(100, A, B);
    printTree(head);
    cout<<isValidBST(head);

}