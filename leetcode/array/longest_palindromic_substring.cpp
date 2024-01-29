#ifndef SUBSTRING
#define SUBSTRING
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0;
        int cur_len = 0;
        int cur_len_pair = 0;
        string max_str = "";
        for(int i = 0; i < s.length(); i++) {
            cur_len = max_len(s, i);
            cur_len_pair = max_len_pair(s, i);
            if(cur_len > max) {
                max = cur_len;
                max_str = s.substr(i - max/2, max);  
            }
            if(cur_len_pair > max) {
                max = cur_len_pair;
                max_str = s.substr(i - max/2 + 1, max);
            }
        }
        return max_str;       
    }

    int max_len(string& s, int index) {
        int len = 1;
        for(int i = 1; i <= index  && i <= s.length() - 1 - index; i++) {
            if(s[index - i] == s[index+i]) len = len + 2;
            else break;
        }
        return len;
    }

    int max_len_pair(string& s, int index) {
        int len = 0;
        int upper = index+1;
        int lower = index;
        while(upper < s.length() && lower >= 0) {
            if(s[upper] == s[lower]) {
                len = len + 2;
                upper++;
                lower--;
            } else break;
        }
        return len;
    }
};
#endif