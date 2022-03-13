//
// Created by Jolen on 2021/6/23.
//


//
// Created by Jolen on 2021/6/22.
//


////  前序遍历，序列化，二叉树


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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> queNode;
    bool reverse = false;
    if(root)
        queNode.push(root);
    while(!queNode.empty()){
        int n = queNode.size();
        deque<int> valList;
        while (n--){
            TreeNode *cur = queNode.front();
            queNode.pop();
            if(reverse)
                valList.push_front(cur->val);
            else
                valList.push_back(cur->val);
            if(cur->left)
                queNode.push(cur->left);
            if(cur->right)
                queNode.push(cur->right);
        }
        res.push_back(vector<int>{valList.begin(),valList.end()});
        reverse = !reverse;
    }
    return res;
}

int main() {
    TreeNode *a = nullptr;
    TreeNode *b = nullptr;
    TreeNode *c = new TreeNode(4);
    TreeNode *d = new TreeNode(5);
    TreeNode *A = new TreeNode(2, a, b);
    TreeNode *B = new TreeNode(3, c, d);
    TreeNode *head = new TreeNode(1, A, B);
    printTree(head);

    auto res = zigzagLevelOrder(head);
    for(auto i:res)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }

}



