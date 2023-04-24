// #3 - [https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/]
#include<bits/stdc++.h>
using namespace std;

unordered_map<char,int> findDup(string str){
    unordered_map<char, int> ans;
    for(int i=0; i<str.size(); i++ ){
        ans[str[i]]++;
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif

    string str; cin >> str;

    unordered_map<char,int> ans = findDup(str);  
    unordered_map<char,int> :: iterator it = ans.begin();
    while(it != ans.end()){
        cout << it->first << " " << it->second << endl;;
        it++;
    }

    return 0;  
}