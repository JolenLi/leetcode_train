//
// Created by Jolen on 2021/6/24.
//
//
// Created by Jolen on 2021/6/23.
//



//// dp


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>


using namespace std;

//
//
//int m,n;
//pair<int,int> start;
//pair<int,int> endPos;
//map<pair<int,int>,bool> pool;
//queue<pair<int,int>> que;
//
//bool isValid(pair<int,int> pos){
//    if(pos.first<0||pos.first>=m)
//        return false;
//    if(pos.second<0||pos.second>=n)
//        return false;
//    if(pool[pos])
//        return false;
//    return true;
//}
//
//void pushPair(pair<int,int> pos){
//    pair<int,int> insertPos = pos;
//    insertPos.first++;
//    if(isValid(insertPos))
//        que.push(insertPos);
//    insertPos = pos;
//    insertPos.first--;
//    if(isValid(insertPos))
//        que.push(insertPos);
//    insertPos = pos;
//    insertPos.second++;
//    if(isValid(insertPos))
//        que.push(insertPos);
//    insertPos = pos;
//    insertPos.second--;
//    if(isValid(insertPos))
//        que.push(insertPos);
//}
//bool bfs(){
//    que.push(start);
//    int paths=-1,count=0;
//    while(!que.empty()){
//        int times = que.size();
//
//        for(int i=0;i<times;i++){
//            pair<int,int> now = que.front();
//            que.pop();
//            if(now==endPos)
//                count++;
//            else {
//                pushPair(now);
//            }
//        }
//        paths++;
//        if(count){
//            cout<<count<<" "<<paths<<endl;
//            return true;
//        }
//    }
//    return false;
//}
//
//
//
//
//
//int main() {
//    int count;
//    cin>>m>>n;
//
//    cin>>start.first>>start.second;
//    cin>>endPos.first>>endPos.second;
//    cin>>count;
//
//    while(count--){
//        pair<int,int> tmp;
//        cin>>tmp.first>>tmp.second;
//        pool[tmp]=1;
//    }
//    bfs();
//}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//vector<TreeNode *> ans;
TreeNode *ans;
unordered_map<string, int> vis;


int getHight(TreeNode *root) {
    if (!root) return 0;
    int l = getHight(root->left);
    int r = getHight(root->right);
    return max(l, r) + 1;
}

string getOrder(TreeNode *root) {
    if (root == nullptr)
        return "#";

    string leftStr = getOrder(root->left);
    string rightStr = getOrder(root->right);
    string rootStr = leftStr + "," + rightStr + "," + (to_string(root->val));

    if (vis[rootStr] == 1) {
        if (getHight(root) > getHight(ans))
            ans = root;
    }
//        ans.push_back(root);
    vis[rootStr]++;
    return rootStr;
}

TreeNode *findDuplicateSubtrees(TreeNode *root) {
    getOrder(root);
    return ans;
}

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

vector<int> getTree(TreeNode *root) {
    queue<TreeNode *> que;
    que.push(root);
    vector<int> res;
    int n = getHight(root);
    for (int i = 0; i < n; i++) {
        int times = que.size();
        while (times--) {
            TreeNode *now = que.front();
            que.pop();
            if (now != nullptr) {
                res.push_back(now->val);
                que.push(now->left);
                que.push(now->right);
            } else {
                res.push_back(0);
                que.push(nullptr);
                que.push(nullptr);
            }
        }
    }
    return res;
}

int main() {
    queue<TreeNode *> que;
    int val;
    TreeNode *root = new TreeNode();
    cin >> root->val;
    que.push(root);
    for (int i = 0; i < 7; i++) {

//        while
        (cin >> val);
        {
            TreeNode *now = que.front();
            TreeNode *left = nullptr;
            TreeNode *right = nullptr;
            que.pop();
            if (val != 0) {
                left = new TreeNode(val);
                now->left = left;
            }
            que.push(left);
            cin >> val;
            if (val != 0) {
                right = new TreeNode(val);
                now->right = right;
            }
            que.push(right);
        }
    }




    printTree(root);
    getOrder(root);
    if (getHight(ans) == 0)
        cout << -1 << endl;
    else{
        for (auto i:getTree(ans))
            cout << i << " ";
        cout << endl;
    }


}