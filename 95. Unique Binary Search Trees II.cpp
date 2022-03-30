
//
// Created by Jolen on 2022/3/29.
//

//
// Created by Jolen on 2021/6/25.
//



//
// Created by Jolen on 2021/6/24.
//



//// 二分查找


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;
vector<TreeNode *> build(int lo, int hi) {
    if (lo > hi)
        return {nullptr};
    vector<TreeNode *> res,ansA,ansB;
    for (int i = lo; i <= hi; i++) {

        ansA = build(lo, i - 1);
        ansB = build(i+1,hi);
        for(TreeNode * a:ansA){
            for(TreeNode * b:ansB){
                TreeNode *root = new TreeNode(i);
                root->left = a;
                root->right = b;
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode *> generateTrees(int n) {
    return build(1,n);
}

int main() {
    string Str = "2-1-1*3-4*5";
    auto sss = diffWaysToCompute(Str);
    for (auto s:sss)
        cout << s << " ";
    cout << endl;
//    cout << << endl;
}