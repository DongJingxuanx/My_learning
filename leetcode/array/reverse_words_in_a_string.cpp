#ifndef REVERSE
#define REVERSE
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    Solution(){};
    string reverseWords(string s) {
        //first traverse
        vector<int> index;
        vector<int> length;
        int cur_length = 0;
        string results = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' ' && (i == 0 || s[i-1] == ' ')) {
                index.push_back(i);
            }
            if(s[i] != ' ') cur_length++;
            if (i == s.length() - 1 || (s[i] == ' ' && ( i != 0 && s[i-1] != ' '))){
                length.push_back(cur_length);
                cur_length = 0;
            }
        }
        for(int i = index.size() - 1; i >= 0; i--) {
            string cur_string = s.substr(index[i], length[i]);
            results.append(cur_string);
            if(i != 0) results.append(" ");
        }
        return results;
    }  
};

int main(int argc, char** argv){
    string s = "the sky is blue";
    Solution sol;
    string res = sol.reverseWords(s);
    cout << "result:" << res << endl;
}
#endif