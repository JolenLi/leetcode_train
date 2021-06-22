//
// Created by Jolen on 2021/6/22.
//


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>

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

int sum = 0;
void dfs(TreeNode *root) {
    if (!root)
        return;
    dfs(root->right);
    sum += root->val ;
    root->val = sum;
    dfs(root->left);
}

TreeNode *convertBST(TreeNode *root) {
    dfs(root);
    return root;
}

int main() {
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(11);
    TreeNode *c = new TreeNode(15);
    TreeNode *d = new TreeNode(300);
    TreeNode *A = new TreeNode(10,a,b);
    TreeNode *B = new TreeNode(200,c,d);
    TreeNode *head = new TreeNode(100, A, B);
    printTree(head);
    convertBST(head);
    printTree(head);
}