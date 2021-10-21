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

// recursive
//unordered_map<int, int> ind;
//
//TreeNode *build(const vector<int> &preOrder, const vector<int> &inorder,
//                int preLeft, int preRight, int inLeft, int inRight) {
//    if (preLeft > preRight)
//        return nullptr;
//
//    int rootIndexInOrder = ind[preOrder[preLeft]];
//    int inOrderLeft = rootIndexInOrder - inLeft;
//
//    TreeNode *root = new TreeNode(preOrder[preLeft]);
//
//
//    root->left = build(preOrder, inorder, preLeft + 1, preLeft + inOrderLeft, inLeft,
//                       rootIndexInOrder - 1);
//    root->right = build(preOrder, inorder, preLeft + inOrderLeft + 1, preRight,
//                        rootIndexInOrder + 1, inRight);
//
//    return root;
//}
//
//TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
//    int n = preorder.size();
//    for (int i = 0; i < inorder.size(); i++)
//        ind[inorder[i]] = i;
//    return build(preorder, inorder, 0, n - 1, 0, n - 1);
//}

/*
 * iteration
 * */
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    stack<TreeNode *> preStack;
    int pre = 0, in = 0;
    TreeNode *root = new TreeNode(preorder[0]);
    TreeNode *cur = root;
    preStack.push(root);
    pre++;
    while (pre < preorder.size()) {
        if (cur->val == inorder[in]) {
            while (!preStack.empty() && preStack.top()->val == inorder[in]) {
                cur = preStack.top();
                preStack.pop();
                in++;
            }
            cur->right = new TreeNode(preorder[pre]);
            cur = cur->right;
            preStack.push(cur);
            pre++;
        } else {
            cur->left = new TreeNode(preorder[pre]);
            cur = cur->left;
            preStack.push(cur);
            pre++;
        }
    }
    return root;
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7}, inorder = {9, 3, 15, 20, 7};

    TreeNode *root = buildTree(preorder, inorder);
    printTree(root);
}