//
// Created by Jolen on 2022/3/28.
//

int chalkReplacer(vector<int> &chalk, int k) {
    long long sum = 0;
    for (int &num:chalk)
        sum += num;
    k %= sum;
    int num = 0;
    for (; num < chalk.size(); num++) {
        k -= chalk[num];
        if (k < 0)
            break;;
    }
    return num;
}


int chalkReplacer(vector<int> &chalk, int k) {
    vector<long long> prefix;
    prefix.push_back(chalk[0]);
    for (int i = 1; i < chalk.size(); i++)
        prefix.push_back(prefix[i - 1] + chalk[i]);
    k %= prefix[prefix.size() - 1];
    int lo = 0, hi = prefix.size();
    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (prefix[mid] == k)
            lo = mid + 1;
        else if (prefix[mid] < k)
            lo = mid + 1;
        else if (prefix[mid] > k)
            hi = mid;
    }
    return lo;
}