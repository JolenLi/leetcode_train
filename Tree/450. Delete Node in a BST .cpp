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

TreeNode *maxNode(TreeNode *root)
{
    root = root->left;
    while(root->right)
        root = root->right;
    return root;
}
TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr)
        return nullptr;
    if (root->val > key)
        root->left = deleteNode(root->left, key);
    else if (root->val < key)
        root->right = deleteNode(root->right, key);
    else if (root->val == key) {
        if(root->left== nullptr)
            return root->right;
        else if(root->right== nullptr)
            return root->left;
        else{
            TreeNode *temp = maxNode(root);
            swap(temp->val,root->val);
            root->left = deleteNode(root->left,key);
        }
    }
    return root;
}


int main() {
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(11);
    TreeNode *c = new TreeNode(15);
    TreeNode *d = new TreeNode(300);
    TreeNode *A = new TreeNode(10, a, b);
    TreeNode *B = new TreeNode(200, c, d);
    TreeNode *head = new TreeNode(100, A, B);
    printTree(head);
    head = deleteNode(head,100);
    printTree(head);
}