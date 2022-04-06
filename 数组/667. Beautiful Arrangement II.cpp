//
// Created by Jolen on 2022/4/6.
//

vector<int> constructArray(int n, int k) {
    vector<int> ans(n,1);
    int lo=1,hi=n;
    for(int i=0;i<k;i++){
        if(i%2==0)
            ans[i]=lo++;
        else
            ans[i]=hi--;
    }
    for(int i=k;i<n;i++){
        if(k%2==0)
            ans[i]=hi--;
        else
            ans[i]=lo++;
    }
    return ans;
}