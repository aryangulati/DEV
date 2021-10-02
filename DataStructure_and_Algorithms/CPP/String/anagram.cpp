
#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        long s1 = 0; 
        long s2 = 0;
        
        for(int i=0; i<a.size(); i++)
           s1 += a[i]; 
        for(int i=0; i<b.size(); i++)
           s2 += b[i]; 
        
        return s1 == s2;   
    }
};


int main(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin); 
      freopen("output.txt", "w", stdout);
    #endif

    string s1,s2;
    cin >> s1 >> s2;

    Solution s;
    s.isAnagram(s1,s2) ? cout << "YES" : cout << "NO";
   

    return 0;   
}
    