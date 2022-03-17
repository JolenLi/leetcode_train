//
// Created by Jolen on 2022/3/17.
//

int numWays(int n) {
    int a=1,b=1;
    int cur = 1;
    int div =  1e9+7;
    for(int i=2;i<=n;i++){
        cur = (a+b)%div;
        a=b;
        b=cur;
    }
    return cur;
}