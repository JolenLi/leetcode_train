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

#include <bitset>

using namespace std;

int findComplement(int num) {
    int ans = 0;
    int idx = 0;
    while(num){
        if((num&1)==0)
            ans += (1<<idx);
        idx++;
        num>>=1;
    }
    return ans;
}

int main() {
    cout << findComplement(2147483647) << endl;
}
