//
// Created by Jolen on 2022/3/12.
//

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> res;
    int size = intervals.size();
    for(int i=0;i<size;){
        int l = intervals[i][0],r = intervals[i][1];
        int j = i+1;
        while(j<size&&r>=intervals[j][0]){
            r = max(r,intervals[j][1]);
            j++;
        }
        res.push_back({l,r});
        i=j;
    }
    return res;
}