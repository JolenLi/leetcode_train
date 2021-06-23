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

string SEP = ",";
string null = "#";

string traverse(TreeNode* root) {
    if (root == nullptr)
        return "#,";
    string str = to_string(root->val)+",";
    str += traverse(root->left);
    str += traverse(root->right);
    return str;
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    string data = traverse(root);
    data.pop_back(); // 去掉尾部 ,
    return data;
}

queue<string> getNum(string &str) {
    queue<string> nums;
    int start = 0;
    for (int i = 0; i <= str.size(); i++) {
        str[i];
        if (str[i] == ','||i==str.size()) {
            nums.push(str.substr(start, i - start));
            start = i + 1;
        }
    }
    return nums;
}

TreeNode *traverse(queue<string> &strNum) {
    string head = strNum.front();
    strNum.pop();
    if (head== "#") {
        return nullptr;
    }
    int num = stoi(head);
    TreeNode *root = new TreeNode(num);
    root->left = traverse(strNum);
    root->right = traverse(strNum);
    return root;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data) {
    queue<string> strNum = getNum(data);
    return traverse(strNum);
}

int main() {
    TreeNode *a = nullptr;
    TreeNode *b = nullptr;
    TreeNode *c =new TreeNode(4);
    TreeNode *d =new TreeNode(5);
    TreeNode *A = new TreeNode(2, a, b);
    TreeNode *B = new TreeNode(3, c, d);
    TreeNode *head = new TreeNode(1, A, B);
    printTree(head);
    string str = serialize(head);
    cout << str << endl;

    head = deserialize(str);
    printTree(head);

}



