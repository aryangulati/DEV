// #1 - [https://leetcode.com/problems/reverse-string/submissions/]
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int i=0, j=s.size()-1;
        while(i<j){
            swap(s[i], s[j]);
            i++; j--;
        }
    }
};