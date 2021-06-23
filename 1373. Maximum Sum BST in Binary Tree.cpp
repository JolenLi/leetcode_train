//
// Created by Jolen on 2021/6/22.
//


////  后序遍历，二叉树


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

//int maxSumNum = 0;
//
//// [a,b,c,d] = [BST,minVal,maxVal,sum]
//int *traverse(TreeNode *root) {
//    if (root == nullptr)
//        return new int[]{1, INT_MAX, INT_MIN, 0};
//    int *left = traverse(root->left);
//    int *right = traverse(root->right);
//    int *res = new int[4];
//    if (left[0] && right[0] && left[2] < root->val && right[1] > root->val) {
//        res[0]=1;
//        res[1]=min(left[1],root->val);
//        res[2] = max(right[2],root->val);
//        res[3] = left[3]+right[3]+root->val;
//        maxSumNum = max(res[3],maxSumNum);
//    } else {
//        res[0]=0;
//    }
//    return res;
//
//}

int maxSum = 0;

int *traverse(TreeNode *root) {
// base case
    if (root == nullptr) {
        return new int[]{
                1, INT_MAX, INT_MIN, 0
        };
    }

// 递归计算左右子树
    int *left = traverse(root->left);
    int *right = traverse(root->right);

/******* 后序遍历位置 *******/
    int *res = new int[4];
// 这个 if 在判断以 root 为根的二叉树是不是 BST
    if (left[0] == 1 && right[0] == 1 &&
        root->val > left[2] && root->val < right[1]) {
// 以 root 为根的二叉树是 BST
        res[0] = 1;
// 计算以 root 为根的这棵 BST 的最小值
        res[1] = min(left[1], root->val);
// 计算以 root 为根的这棵 BST 的最大值
        res[2] = max(right[2], root->val);
// 计算以 root 为根的这棵 BST 所有节点之和
        res[3] = left[3] + right[3] + root->val;
// 更新全局变量
        maxSum = max(maxSum, res[3]);
    } else {
// 以 root 为根的二叉树不是 BST
        res[0] = 0;
// 其他的值都没必要计算了，因为用不到
    }
/**************************/

    return res;
}


int maxSumBST(TreeNode *root) {
    traverse(root);
    return maxSum;
}


int main() {
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(11);
    TreeNode *c = new TreeNode(15);
    TreeNode *d = new TreeNode(300);
    TreeNode *A = new TreeNode(10, a, b);
//    TreeNode *B = new TreeNode(200, c, d);
//    TreeNode *head = new TreeNode(10000, A, B);
    printTree(A);
    maxSumBST(A);
    cout << maxSum;
//    printTree(head);
}

