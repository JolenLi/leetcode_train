//
// Created by Jolen on 2022/3/29.
//

int guessNumber(int n) {
    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        int flag = guess(mid);
        if (flag == 0)return mid;
        else if (flag == -1) hi = mid - 1;
        else if (flag == 1) lo = mid + 1;
    }
    return -1;
}