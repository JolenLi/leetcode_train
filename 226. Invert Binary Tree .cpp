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

TreeNode *invertTree(TreeNode *root) {
    if(root== nullptr)
        return root;
    TreeNode *temp = root->left;
    root->left=root->right;
    root->right=temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
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
    cout<<endl;
}

int main() {

    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *A = new TreeNode(10);
    TreeNode *B = new TreeNode(20, c, d);
    TreeNode *head = new TreeNode(100, A, B);
    printTree(head);
    invertTree(head);
    printTree(head);
}
