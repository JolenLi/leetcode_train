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

unordered_map<int,int> ind;
TreeNode *build(const vector<int> &inOrder, const vector<int> &postOrder, int inStart, int inEnd, int postStart, int postEnd) {
    if(inStart>inEnd) return nullptr;
    TreeNode *root = new TreeNode(postOrder[postEnd]);
    int inRootIndex = ind[postOrder[postEnd]];
    int leftSize = inRootIndex-inStart;

    root->left = build(inOrder,postOrder,inStart,inStart+leftSize-1,postStart,postStart+leftSize-1);
    root->right = build(inOrder,postOrder,inStart+leftSize+1,inEnd,postStart+leftSize,postEnd-1);
    return root;

}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.size() == 0)
        return nullptr;
    for(int i=0;i<inorder.size();i++)
        ind[inorder[i]] = i;
    return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}

int main() {
    vector<int> inorder = {9,3,15,20,7}, postorder = {9,15,7,20,3};
    TreeNode *root = buildTree(inorder, postorder);
    printTree(root);
}