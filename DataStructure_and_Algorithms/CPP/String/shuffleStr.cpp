// #6 - [https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings]
#include<bits/stdc++.h>
using namespace std;

bool check(string s1, string s2, string suff){
    unordered_map<char,int> t;
    string temp = s1+s2;
    for(int i=0; i<temp.size(); i++){
        t[temp[i]]++;
    }
    

    for(int i=0; i<suff.size(); i++){
        if(t.find(suff[i]) != t.end()){
            t[suff[i]]--;
            if(t[suff[i]] == 0)
               t.erase(suff[i]);
        }else return false; 
    }

    return suff.size() == temp.size();
}

int main(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif

    string str1,str2, suff; cin >> str1 >> str2 >> suff;

    cout << check(str1, str2, suff);

    return 0;  
}