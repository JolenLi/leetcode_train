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
/*
 * recursivce
*/
//int minIndex = 0;
//int ans;
//
//void find(TreeNode *root, int k) {
//    if (root == nullptr)return;
//    find(root->left, k);
//    if (++minIndex == k)
//        ans = root->val;
//    find(root->right, k);
//}
//
//int kthSmallest(TreeNode *root, int k) {
//    find(root, k);
//    return ans;
//}

/*
 * interate
*/

int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> tree;
    tree.push(root);
    TreeNode *cur = root;
    while (!tree.empty()) {
        while (cur) {
            tree.push(cur);
            cur = cur->left;
        }
        cur = tree.top();
        tree.pop();
        if (--k == 0)return cur->val;
        cur = cur->right;
    }
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
    int ans = kthSmallest(head, 4);
    cout << ans << endl;
}