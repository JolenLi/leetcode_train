//
// Created by Jolen on 2022/3/30.
//

bool isPerfectSquare(int num) {
    int lo=0,hi=num;
    while(lo<=hi){
        long long mid = lo+((hi-lo)>>1);
        long long mul = mid*mid;
        if(mul==num)
            return true;
        else if(mul>num)
            hi = mid-1;
        else if(mul<num)
            lo = mid+1;
    }
    return false;
}