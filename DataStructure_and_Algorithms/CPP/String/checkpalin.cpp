// #2 - [https://practice.geeksforgeeks.org/problems/palindrome-string0817/1#]
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	
	
	int isPlaindrome(string S)
	{
	    // Your code goes here
	int i=0, j=S.size()-1;
    while(i<j){
        if(S[i] != S[j])
        return 0;
        i++; j--;
    }
    return 1;
	}
};