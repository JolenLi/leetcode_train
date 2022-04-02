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
int getSum(int a, int b) {
    if(a==0)
        return b;
    if(b==0)
        return a;
    return getSum(a^b,(unsigned )(a&b)<<1);
}



int getSum(int a, int b) {
    int c =0,add=0;
    int idx = 0;
    for(int i=0;i<32;i++){
        int x = a&1,y=b&1;
        if(x&&y){
            c |= (add<<idx);
            add=1;
        }else if(x||y){
            c |= ((1^add)<<idx);
        }else{
            c|=(add<<idx);
            add = 0;
        }
        idx++;
        a>>=1,b>>=1;
    }
    return c;
}
int main() {
    cout << getSum(2,3) << endl;
}
