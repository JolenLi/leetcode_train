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


vector<TreeNode *> ans;
unordered_map<string, int> vis;

string getOrder(TreeNode *root) {
    if (root == nullptr)
        return "#";

    string leftStr = getOrder(root->left);
    string rightStr = getOrder(root->right);
    string rootStr = leftStr  + "," + rightStr+ "," + (to_string(root->val));

    if (vis[rootStr] == 1)
        ans.push_back(root);
    vis[rootStr]++;
    return rootStr;
}


vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    getOrder(root);
    return ans;
}





//
//
//
//
//
//
//unordered_map<string,int> treeString;
//vector<TreeNode*> res;
//
//string tree2String(TreeNode* root)
//{
//    if(root== nullptr) return "#";
//    string str = to_string(root->val)+','+tree2String(root->left)+','+tree2String(root->right);
//
//    if(treeString[str]==1)
//        res.push_back(root);
//    treeString[str]++;
////    if(treeString.count(str)){
////        if(treeString[str]==1)
////            res.push_back(root);
////        treeString[str]++;
////    }else{
////        treeString[str]=1;
////    }
//    return str;
//}
//vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//    tree2String(root);
//    return res;
//}

int main() {
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(1);
    TreeNode *d = new TreeNode(2);
    TreeNode *A = new TreeNode(20, a, b);
    TreeNode *B = new TreeNode(20, c, d);
    TreeNode *head = new TreeNode(100, A, B);
    printTree(head);
    findDuplicateSubtrees(head);

}