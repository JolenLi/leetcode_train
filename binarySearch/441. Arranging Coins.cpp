//
// Created by Jolen on 2022/3/29.
//

bool check(int n,int i){
    long long cnt = (1+i)*(i/2.0);
    return n>=cnt;
}
int arrangeCoins(int n) {
    int lo=1,hi=n;
    while(lo<=hi){
        int mid = lo+(hi-lo>>1);
        if(check(n,mid))
            lo = mid+1;
        else
            hi = mid-1;
    }
    return hi;
}