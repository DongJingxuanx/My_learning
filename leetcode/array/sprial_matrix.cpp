#ifndef SPIRAL_MATRIX
#define SPIRAL_MATRIX
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, up = 0;
        int down = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        vector<int> res;
        while(true) {
            //inner for
            for(int i = left; i <= right; i++) res.push_back(matrix[up][i]);
            if(++up > down) break;
            for(int i = up; i <= down; i++) res.push_back(matrix[i][right]);
            if(--right < left) break;
            for(int i = right; i >= left; i--) res.push_back(matrix[down][i]);
            if(--down < up) break;
            for(int i = down; i >=up; i--) res.push_back(matrix[i][left]);
            if(++left > right) break;

            }
        return res;
    }
};
#endif