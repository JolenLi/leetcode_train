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

// BFS
//int countNodes(TreeNode* root) {
//    queue<TreeNode*> list;
//    if(!root)return 0;
//    list.push(root);
//    int ans = 0;
//    while(!list.empty())
//    {
//        TreeNode *cur = list.front();
//        list.pop();
//        ans+=1;
//        if(cur->left) list.push(cur->left);
//        if(cur->right) list.push(cur->right);
//    }
//    return ans;
//}


//二分查找
//int ans, height;
//
//int getHeight(TreeNode *root) {
//    if (!root)return 0;
//    return getHeight(root->left) + 1;
//}
//
//bool exist(TreeNode *root, int level, int num) {
//    int bits = 1 << (level - 2);
//
//    for (int i = 1; i < level; i++) {
//        if (bits & num)
//            root = root->right;
//        else if (root)
//            root = root->left;
//        bits = bits >> 1;
//    }
//    return root != nullptr;
//}
//
//int countNodes(TreeNode *root) {
//    height = getHeight(root);
//    if(height<2)return height;
//
//    int lo = (1 << (height - 1)), hi = (1 << height) - 1;
//    while (lo < hi) {
//        int mid = lo + ((hi - lo) >> 1);
//        if (exist(root, height, mid))
//            lo = mid + 1;
//        else
//            hi = mid;
//    }
//    return exist(root, height, hi) ? hi : hi - 1;
//}
//



int countLevel(TreeNode *root) {
    if (!root)
        return 0;
    return countLevel(root->left) + 1;
}

//DFS
int countNodes(TreeNode *root) {
    if (!root) return 0;
    int leftHeight = countLevel(root->left);
    int rightHeight = countLevel(root->right);
    if (leftHeight == rightHeight)
        return countNodes(root->right)+(1<<leftHeight);
    else
        return countNodes(root->left)+(1<<rightHeight);
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

// BFS
//int countNodes(TreeNode* root) {
//    queue<TreeNode*> list;
//    if(!root)return 0;
//    list.push(root);
//    int ans = 0;
//    while(!list.empty())
//    {
//        TreeNode *cur = list.front();
//        list.pop();
//        ans+=1;
//        if(cur->left) list.push(cur->left);
//        if(cur->right) list.push(cur->right);
//    }
//    return ans;
//}

int main() {
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);

    TreeNode *A = new TreeNode(10, a, b);
    TreeNode *B = new TreeNode(20, c, nullptr);
    TreeNode *head = new TreeNode(100, A, B);
    printTree(head);
    cout << countNodes(head) << endl;
    printTree(head);
}

