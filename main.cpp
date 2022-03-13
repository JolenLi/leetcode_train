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
queue<string> split(string data){
    string str;
    queue<string> que;
    for(auto &c:data){
        if(c==','){
            que.push(str);
            str="";
        }else{
            str+=c;
        }
    }
    que.push(str);
    return que;
}

string serialize(TreeNode* root) {
    string str= "";
    if(!root) return "#";
    return to_string(root->val)+","+ serialize(root->left)+","+serialize(root->right);

//    queue<TreeNode*> que;
//    que.push(root);
//    while(!que.empty()){
//        TreeNode *cur = que.front();
//        que.pop();
//        if(cur== nullptr)
//            str+="#,";
//        else{
//            str+=to_string(cur->val);
//            str+=",";
//            que.push(cur->left);
//            que.push(cur->right);
//        }
//    }
    return str;
}

TreeNode* deser(queue<string> &que){
    string cur = que.front();
    que.pop();
    if(cur=="#")return nullptr;
    TreeNode* root = new TreeNode(stoi(cur));
    root->left = deser(que);
    root->right = deser(que);
    return root;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    queue<string> que = split(data);

    return deser(que);
}



int main() {
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(11);
    TreeNode *c = new TreeNode(150);
    TreeNode *d = new TreeNode(300);
//    TreeNode *A = new TreeNode(10, a, b);
//    TreeNode *B = new TreeNode(200, c, d);
    TreeNode *A = new TreeNode(10);
    TreeNode *B = new TreeNode(200);
    TreeNode *head = new TreeNode(100, A, B);
    printTree(head);


//    for(auto i:ans)
//        printTree(i);
//    cout<<deserialize(serialize(head))<<endl;
cout<<endl;
    printTree(deserialize(serialize(head)));

}

