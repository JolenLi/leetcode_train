//
// Created by Jolen on 2021/6/22.
//
/*
 *
 *      递归
 *
 * */
TreeNode* searchBST(TreeNode* root, int val) {
    if(root==nullptr||root->val==val)
        return root;
    if(root->val<val)
        return searchBST(root->right,val);
    else
        return searchBST(root->left,val);
}

/*
 *
 *      迭代
 *
 * */
TreeNode* searchBST(TreeNode* root, int val) {
    if(root==nullptr||root->val==val)
        return root;
    TreeNode *ans = root;
    while(ans){
        if(ans->val==val)
            return ans;
        if(ans->val<val)
            ans = ans->right;
        else
            ans = ans->left;
    }
    return ans;
}
