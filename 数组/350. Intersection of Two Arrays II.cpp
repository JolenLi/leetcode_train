//
// Created by Jolen on 2021/6/22.
//

#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<string>

using namespace std;

//vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//    unordered_map<int,int> table1,table2;
//    vector<int> ans;
//    for(int i:nums1)
//        table1[i]+=1;
//    for(int i:nums2)
//        table2[i]+=1;
//    for(auto it:table1)
//    {
//        int key = it.first;
//        int times = min(it.second,table2[key]);
//        while(times--)
//            ans.push_back(key);
//    }
//    return ans;
//}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    vector<int> ans;
    for(int i=0,j=0;i<nums1.size()&&j<nums2.size();)
    {
        if(nums1[i]==nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }else if(nums1[i]<nums2[j]){
            i++;
        }else{
            j++;
        }
    }
    return ans;
}

int main() {
    vector<int> nums1 = {4,9,5}, nums2 = {9,4,9,8,4};
    nums1.insert(,999);

    intersect(nums1,nums2);
}


