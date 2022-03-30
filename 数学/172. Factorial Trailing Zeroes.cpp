//
// Created by Jolen on 2022/3/29.
//

int trailingZeroes(int n) {
    int cnt = 0;
    for (int i = 5; i <= n; i += 5)
        for (int j = i; j % 5 == 0; j /= 5)
            cnt++;
    return cnt;
}