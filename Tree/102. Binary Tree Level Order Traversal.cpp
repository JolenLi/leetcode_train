//
// Created by Jolen on 2021/6/21.
//

#include<vector>
#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    vector<int> levelAns;
    queue<TreeNode *> list;
    if(!root)
        return res;
    list.push(root);
    while (!list.empty()) {
        int n = list.size();
        for (int i = 0; i < n; i++) {
            TreeNode *cur = list.front();
            list.pop();
            levelAns.push_back(cur->val);
            if (cur->left) list.push(cur->left);
            if (cur->right) list.push(cur->right);
        }
        res.push_back(levelAns);
        levelAns.clear();
    }
}

void printTree(TreeNode *root) {
    queue<TreeNode *> list;
    vector<int> vec;
    list.push(root);

    while (!list.empty()) {
        auto head = list.front();
        list.pop();
        if (head == nullptr)
            continue;
        vec.push_back(head->val);
        list.push(head->left);
        list.push(head->right);
    }
    for (auto i:vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *A = new TreeNode(10, a, b);
    TreeNode *B = new TreeNode(20, c, d);
    TreeNode *head = new TreeNode(100, A, B);
    printTree(head);
    levelOrder(nullptr);
    printTree(head);
}

