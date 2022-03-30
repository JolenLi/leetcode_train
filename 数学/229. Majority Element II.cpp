//
// Created by Jolen on 2022/3/30.
//

vector<int> majorityElement(vector<int>& nums) {
    vector<int> majorA(2,0);
    vector<int> majorB(2,0);
    majorA[0] =nums[0],majorB[0]= nums[0];
    for(int &num:nums){
        if(num==majorA[0])
            majorA[1]++;
        else if(num==majorB[0])
            majorB[1]++;
        else if(majorA[1]==0){
            majorA[0]=num;
            majorA[1]=1;
        }else if(majorB[1]==0){
            majorB[0] = num;
            majorB[1]=1;
        }else{
            majorA[1]--;
            majorB[1]--;
        }
    }
    int countA=0,countB=0;
    vector<int> ans;
    for(int &num:nums){
        if(num==majorA[0])
            countA++;
        else if(num==majorB[0])
            countB++;
    }
    if(countA>(nums.size()/3))
        ans.push_back(majorA[0]);
    if(countB>(nums.size()/3))
        ans.push_back(majorB[0]);
    return ans;
}



vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int,int> times;
    unordered_set<int> ans;
    for(int &num:nums){
        times[num]++;
        if(times[num]>nums.size()/3)
            ans.insert(num);
    }
    return vector<int>(ans.begin(),ans.end());
}