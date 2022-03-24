//
// Created by Jolen on 2022/3/23.
//

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    int MAXSIZE = 1000;
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> people(1005,0);
        for(auto &trip:trips){
            people[trip[1]]+=trip[0];
            people[trip[2]]-=trip[0];
        }
        for(int i =0;i<=MAXSIZE;i++){
            capacity -= people[i];
            if(capacity<0)return false;
        }
        return true;
    }