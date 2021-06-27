//
// Created by Jolen on 2021/6/26.
//

vector<int> countBits(int n) {
    vector<int> ans(n+1,0);
    for(int i=1;i<=n;i++){
        ans[i]= ans[i&(i-1)]+1;
    }
    return ans;
}