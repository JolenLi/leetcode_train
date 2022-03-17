class Solution {
public:
    vector<vector<int>> ans;
    vector<int> getNext(int idx){
        vector<int> res = {1};
        vector<int> last = ans[idx-1];
        for(int i=1;i<idx;i++){
            res.push_back(last[i-1]+last[i]);
        }
        res.push_back(1);
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        ans.push_back({1});
        for(int i=1;i<numRows;i++)
            ans.push_back(getNext(i));
        return ans;
    }
};