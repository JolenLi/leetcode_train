//
// Created by Jolen on 2022/3/30.
//

vector<int> twoSum(vector<int>& numbers, int target) {
    int lo=0,hi=numbers.size()-1;
    while(lo<hi){
        int sum = numbers[lo]+numbers[hi];
        if(sum==target)
            return {lo+1,hi+1};
        else if(sum>target)
            hi--;
        else if(sum<target)
            lo++;
    }
    return {-1,-1};
}