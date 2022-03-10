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

//SEP = ",";
//NULL = "#";

string serialize(TreeNode *root) {
    string str = "";
    if (!root) return "#";
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

TreeNode *deser(queue<string> &strQue) {
    string val = strQue.front();
    strQue.pop();
    if(val=="#")
        return nullptr;

    TreeNode *root = new TreeNode(stoi(val));
    root->left = deser(strQue);
    root->right= deser(strQue);
    return root;
}

queue<string> split(string str) {
    queue<string> strQue;
    vector<int> a;
    a.push_back()
    string temp = "";
    for(int i =0;i<str.size();i++){
        if (str[i] == ',') {
            strQue.push(temp);
            temp.clear();
        } else{
            temp += str[i];
        }
    }
    strQue.push(temp);
    return strQue;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data) {
    queue<string> strQue = split(data);
    return deser(strQue);
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
    string str = serialize(head);
    cout << str << endl;

    head = deserialize(str);
    printTree(head);

}



