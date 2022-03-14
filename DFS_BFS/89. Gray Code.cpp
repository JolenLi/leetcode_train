vector<int> res;
unordered_set<int> visited;
void dfs(int n,int i){
    for(int k=0;k<n;k++){
        int cur = i^(1<<k);
        if(!visited.count(cur)){
            visited.insert(cur);
            res.push_back(cur);
            dfs(n,cur);
        }
    }
}
vector<int> grayCode(int n) {
    res.push_back(0);
    visited.insert(0);
    dfs(n,0);
    return res;
}