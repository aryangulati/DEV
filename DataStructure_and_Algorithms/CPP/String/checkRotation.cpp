// #5 - [https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/]
#include<bits/stdc++.h>
using namespace std;

bool check(string str1, string str2){
    if(str1.size() != str2.size())
     return false;
    string temp = str1+str1;
    int n = temp.size();
    int m = str2.size();

    for(int i=0; i<=(n-m); i++){
        bool isFound = true;
        for(int j=0; j<m; j++){
            if(temp[i+j] != str2[j]){
                isFound = false;
                break;
            }
        }
        if(isFound) return true;
    }

    return false;

}

int main(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif

    string str1,str2; cin >> str1 >> str2;

    cout << check(str1, str2);

    return 0;  
}