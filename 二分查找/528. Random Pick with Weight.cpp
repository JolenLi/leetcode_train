//
// Created by Jolen on 2022/3/29.
//

class Solution {
public:
    Solution(vector<int>& w) {
        weight = vector<int>(w.size()+1,0);
        for(int i =1;i<=w.size();i++){
            weight[i] = weight[i-1]+w[i-1];
        }
    }

    int pickIndex() {
        int pick = rand()%weight[weight.size()-1];
        int lo=0,hi=weight.size()-1;
        while(lo<=hi){
            int mid = lo+((hi-lo)>>1);
            if(pick>=weight[mid])
                lo = mid+1;
            else
                hi = mid-1;
        }
        return hi;
    }
private:
    vector<int> weight;
};