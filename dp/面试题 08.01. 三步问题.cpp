//
// Created by Jolen on 2022/3/17.
//

int waysToStep(int n) {
    long long a = 1, b = 1, c = 2;
    long long t;
    if(n <= 2) return n;
    for(int i = 3; i <= n; i++) {
        t = a;
        a = b;
        b = c;
        c = (t + a + b)%1000000007;
    }
    return c;
}