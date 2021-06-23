//
// Created by Jolen on 2021/6/22.
//

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

vector<TreeNode*> findBST(int lo,int hi)
{
    vector<TreeNode*> ans;
    if(lo>hi) {
        ans.push_back(nullptr);
        return ans;
    }
    for(int i = lo;i<=hi;i++)
    {
        vector<TreeNode*> left = findBST(lo,i-1);
        vector<TreeNode*> right = findBST(i+1,hi);
        for(auto l:left)
            for(auto r:right){
                TreeNode *root = new TreeNode(i);
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
    }
    return ans;
}
vector<TreeNode*> generateTrees(int n) {
    return findBST(1,n);
}

int main() {
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(11);
    TreeNode *c = new TreeNode(150);
    TreeNode *d = new TreeNode(300);
    TreeNode *A = new TreeNode(10, a, b);
    TreeNode *B = new TreeNode(200, c, d);
    TreeNode *head = new TreeNode(100, A, B);
    printTree(head);
    vector<TreeNode*> ans = generateTrees(3);
    for(auto i:ans)
        printTree(i);


}

