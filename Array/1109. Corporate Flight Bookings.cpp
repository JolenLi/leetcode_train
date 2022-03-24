//
// Created by Jolen on 2022/3/23.
//

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> reserved(n,0);
    for(auto &book:bookings){
        reserved[book[0]-1]+=book[2];
        if(book[1]<n)
            reserved[book[1]]-=book[2];
    }
    for(int i =1;i<n;i++)
        reserved[i]+= reserved[i-1];
    return reserved;
}