#ifndef CAR_POOLING
#define CAR_POOLING
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    Solution(){};
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int to_max = 0;
        for (const auto& trip: trips) {
            to_max = max(to_max, trip[2]);
        }
        
        // vector<int> table(to_max + 1);
        int* table  = new int[to_max + 1];
        for(int i = 0; i < trips.size(); i++) {
            int left = trips[i][1];
            int right = trips[i][2];
            table[left] = table[left] + trips[i][0];
            table[right] = table[right] - trips[i][0];
        }
        int sum = 0;
        for (int i = 0; i < to_max +1; i++) {
            sum = sum + table[i];
            if(sum > capacity) return false;
        }
        return true;
    }

};

int main(int argc, char** argv[]) {
    vector<vector<int>> test1 {{2,1,5},{3,3,7}};
    int capacity = 5;
    int capacity2 = 4;
    Solution s;
    bool res = s.carPooling(test1, capacity);
    cout << "result:" << res << endl;
}
#endif