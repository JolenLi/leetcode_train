//
// Created by Jolen on 2022/3/29.
//

int hIndex(vector<int> &citations) {
    int lo = 0, hi = citations.size();
    while (lo < hi) {
        int mid = lo + (hi - lo >> 1);
        int h = citations.size() - mid;
        if (citations[mid] >= h)
            hi = mid;
        else
            lo = mid + 1;
    }
    return citations.size() - lo;
}