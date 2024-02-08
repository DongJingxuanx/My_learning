#ifndef  Corporate_Flight_Bookings
#define Corporate_Flight_Bookings
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer(n);
        vector<int> prefix(n);
        prefix[0] = answer[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = answer[i] - answer[i-1];
        }

        for(int i = 0; i < bookings.size(); i++) {
            int start = bookings[i][0] - 1;
            int end = bookings[i][1] - 1;
            prefix[start] = prefix[start] + bookings[i][2];
            if(end < n - 1) prefix[end + 1] = prefix[end + 1] - bookings[i][2];
        }
        
        answer[0] = prefix[0];
        for(int i = 1; i < n; i++) {
            answer[i] = answer[i-1] + prefix[i];
        }
        return answer;
    }

}; 
#endif