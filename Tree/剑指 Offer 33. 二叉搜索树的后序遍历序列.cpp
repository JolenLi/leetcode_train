//
// Created by Jolen on 2022/3/16.
//
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


void flatten(TreeNode *root) {
    if (root == nullptr)
        return;
    flatten(root->left);
    flatten(root->right);

    TreeNode *left = root->left;
    TreeNode *right = root->right;

    root->right = left;
    root->left = nullptr;

    TreeNode *cur = root;
    while (cur->right) {
        cur = cur->right;
    }
    cur->right = right;

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


bool check(vector<int> &nums, int left, int right, int mini, int maxi) {
    if (left > right)
        return true;
    int rootVal = nums[right];
    if (rootVal >= maxi || rootVal <= mini)
        return false;
    int idx = left;
    for (idx = left; idx < right; idx++) {
        if (nums[idx]>rootVal)
            break;
    }
    return check(nums,left,idx-1,mini,rootVal) && check(nums,idx,right-1,rootVal,maxi);
}


bool verifyPostorder(vector<int> &postorder) {
    return check(postorder,0,postorder.size()-1,INT_MIN,INT_MAX);
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
    flatten(head);
    printTree(head);
}





