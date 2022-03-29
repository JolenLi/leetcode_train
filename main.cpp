//
// Created by Jolen on 2021/6/24.
//
//
// Created by Jolen on 2021/6/23.
//



//// dp


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

int Gcd(int a, int b) {
    if (b == 0)
        return a;
    return Gcd(b, a % b);
}

int solution(int n) {
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0 && Gcd(i, n / i) == 1){
            cout<<i<<" "<<n/i<<" "<<n<<endl;
            cnt++;
        }

    }
    return cnt;
}


int main() {
    cout << solution(30) << endl;
}