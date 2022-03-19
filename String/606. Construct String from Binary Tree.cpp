//
// Created by Jolen on 2022/3/19.
//

string tree2str(TreeNode* root) {
    if(!root)return "";
    string str = to_string(root->val);
    if(root->right){
        str += "(" +tree2str(root->left)+")";
        str += "(" +tree2str(root->right)+")";
    }else if(root->left)
        str += "(" +tree2str(root->left)+")";
    return str;
}