//
// Created by Jolen on 2021/10/24.
//

//
// Created by Jolen on 2021/10/23.
//

#include <bits/stdc++.h>

using namespace std;

bool canFinish(vector<int> &piles, int h, int k) {
    int t = 0;
    for (const auto &pile:piles) {
        t += (pile - 1) / k + 1;
    }
    return t <= h;
}

int minEatingSpeed(vector<int> &piles, int h) {

    int lo = 1, hi = 0;
    for (auto &pile :piles)
        hi = max(hi, pile);
    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (canFinish(piles, h, mid))
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return lo;
}

int main() {
    vector<int> piles = {30, 11, 23, 4, 20};
    int h = 5;
    cout << minEatingSpeed(piles, h) << endl;

}