//
// Created by Jolen on 2022/4/6.
//

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


int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0;
    int count=0;
    for(int num:nums){
        if(num==1)
            count++;
        else
            count=0;
        ans = max(ans,count);
    }
    return ans;
}
int main() {

}
