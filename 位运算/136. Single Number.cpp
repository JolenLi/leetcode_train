//
// Created by Jolen on 2022/4/1.
//

//
// Created by Jolen on 2021/6/26.
//


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int &num:nums)
        ans^= num;
    return ans;
}


int main() {

}
