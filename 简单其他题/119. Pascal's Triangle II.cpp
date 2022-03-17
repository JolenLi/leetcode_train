void getNext(vector<int> &ans,int idx){
    ans.push_back(1);
    for(int i=idx-1;i>0;i--)
        ans[i] = ans[i-1]+ans[i];
}
vector<int> getRow(int rowIndex) {
    vector<int> ans = {1};
    for(int i=1;i<=rowIndex;i++)
        getNext(ans,i);
    return ans;
}