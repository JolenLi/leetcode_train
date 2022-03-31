//
// Created by Jolen on 2022/3/19.
//

int singleNumber(vector<int>& nums) {
    vector<int> bits(32,0);
    for(int &num:nums){
        for(int idx=0;idx<32;idx++){
            bits[idx] += num&1;
            num>>=1;
        }
    }
    int ans=0;
    for(int i=31;i>=0;i--){
        ans<<=1;
        ans+=bits[i]%3;
    }
    return ans;
}