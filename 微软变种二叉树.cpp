//
// Created by Jolen on 2021/6/22.
//

//
// Created by Jolen on 2021/6/22.
//


///https://lemonchan.top/posts/f3bed3dc.html

#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>

using namespace std;

int res = 0;

int getLen(string &s, vector<vector<int>> &tree, int cur) {

    if (tree[cur].size() == 0)
        return 1;
    vector<int> sonLen(1, 0);
    for (int &son:tree[cur]) {
        if (s[cur] != s[son]) {
            sonLen.push_back(getLen(s, tree, son));
        }
    }
    sort(sonLen.begin(), sonLen.end(),greater<int>());
    res = max(res, sonLen[0] + sonLen[1] + 1);
    return sonLen[0] + 1;

}

int solution(string s, int a[]) {

    int size = s.size();
    vector<vector<int>> tree(size);

    for (int i = 0; i < size; i++) {
        tree[a[i]].push_back(i);
    }
    getLen(s, tree, 0);
    return res;
}

int main() {
    string S="abbab";
    int A[]={-1,0,0,0,2};
    cout << solution(S, A) << endl;
}

