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
    int *res = new int[]{1, INT_MAX, INT_MIN, 1};
    //res[0] 是否是BST
    //res[1] 最小值
    //res[2] 最大值
    //res[3] sum
    if (!root) return res;
    int *left = traverse(root->left);
    int *right = traverse(root->right);
    if (left[0] && right[0] && left[2] < root->val && right[1] > root->val) {
        res[1] = min( left[1],root->val);
        res[2] = max(right[2],root->val);
        res[3] = root->val+left[3]+right[3];
        maxSum = max(res[3], maxSum);
    } else
        res[0] = 0;
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
    TreeNode *B = new TreeNode(200, c, d);
    TreeNode *head = new TreeNode(100, A, B);
    printTree(head);
    maxSumBST(head);
    cout << maxSum;
//    printTree(head);
}

