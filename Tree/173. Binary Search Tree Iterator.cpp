/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    vector<int> res;
    int idx=0;

    void inOrder(TreeNode *root){
        if(!root)return;
        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        inOrder(root);
    }

    int next() {
        return res[idx++];
    }

    bool hasNext() {
        return idx!=res.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */