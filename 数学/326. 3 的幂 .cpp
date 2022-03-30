//
// Created by Jolen on 2022/3/30.
//

bool isPowerOfThree(int n) {
    while (n && n % 3 == 0)
        n /= 3;
    return n == 1;
}