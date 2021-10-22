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
int findMax(TreeNode* root){
    if(root->right)
        return findMax(root->right);
    return root->val;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root)return root;

    if(root->val==key){
        if(!root->left||!root->right)
            return root->left?root->left:root->right;
        root->val  = findMax(root->left);
        root->left = deleteNode(root->left,root->val);
        return root;
    }
    else if(root->val>key)
        root->left=deleteNode(root->left,key);
    else if(root->val<key)
        root->right = deleteNode(root->right,key);
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