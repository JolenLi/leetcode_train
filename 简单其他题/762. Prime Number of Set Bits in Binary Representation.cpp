//
// Created by Jolen on 2022/3/19.
//

bool isPrime(int num){
    for(int i=2;i<num;i++){
        if(num%i==0)
            return false;
    }
    return true;
}
int getCnt(int num){
    int count=0;
    while(num){
        if(num&1)
            count++;
        num>>=1;
    }
    return count;
}
int countPrimeSetBits(int left, int right) {
    unordered_set<int> prime;
    for(int i=2;i<20;i++)
        if(isPrime(i))
            prime.insert(i);
    int res=0;
    for(int i=left;i<=right;i++){
        if(prime.count(getCnt(i)))
            res++;
    }
    return res;
}