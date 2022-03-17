vector<int> res;

void dfs(TreeNode *root) {
    if (!root)return;
    dfs(root->left);
    dfs(root->right);
    res.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root) {
    dfs(root);
    return res;
}