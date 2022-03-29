//
// Created by Jolen on 2022/3/11.
//

int maxDiam = 0;

int dfs(TreeNode* root){
    if(root==nullptr) return 0;
    int leftLen = dfs(root->left);
    int rightLen = dfs(root->right);
    maxDiam = max(maxDiam,leftLen+rightLen+1);

    return leftLen>rightLen?leftLen+1:rightLen+1;
}

int diameterOfBinaryTree(TreeNode* root) {

    dfs(root);
    return maxDiam-1;

}