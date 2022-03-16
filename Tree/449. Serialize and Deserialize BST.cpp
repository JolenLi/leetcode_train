/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#,";
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }

    queue<string> info;
    void getInfo(string &data){
        string str = "";
        for(int i =0;i<data.size();i++){
            if(data[i]==','){
                info.push(str);
                str = "";
            }else{
                str = str + data[i];
            }
        }
    }
    TreeNode* getNode(){
        string nodeVal = info.front();
        info.pop();
        if(nodeVal =="#")return NULL;
        TreeNode* root = new TreeNode(stoi(nodeVal));
        root->left = getNode();
        root->right = getNode();
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        getInfo(data);
        return getNode();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;//
// Created by Jolen on 2022/3/16.
//

