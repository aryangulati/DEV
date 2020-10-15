#include<bits/stdc++.h>
using namespace std;

int main(){

    cout<<"\n\n\n\t\tTIC TAC TOE\n";
    cout<<"\t\tversion 1.0\n\n\n";


    int arr[9];
    int i,t,flag=0,win=0;
    cout<<"\t\t";
    for(i=0;i<9;i++){
        arr[i]=0;
        cout<<" "<<i+1<<" ";
        if((i+1)%3==0){
            cout<<endl;
            cout<<"\t\t";
        }
    }

    while(true){
        if(flag==0){
            cout<<"Player 1 turn. Enter position: ";
        }
        else{
            cout<<"Player 2 turn. Enter position: ";
        }
        cin>>t;
        if(arr[t-1]!=0){
            cout<<"Invalid position!!!"<<endl;
        }
        else{
            if(flag==0){
                arr[t-1]=1;
            }
            else{
                arr[t-1]=2;
            }
        }
        cout<<"\t\t";
        for(i=0;i<9;i++){
            if(arr[i]==0){
                cout<<" "<<i+1<<" ";
            }
            else if(arr[i]==1){
                cout<<" O ";
            }
            else{
                cout<<" X ";
            }
            if((i+1)%3==0){
                cout<<endl;
                cout<<"\t\t";
            }
        }

        if(arr[0]!=0 && arr[1]!=0 && arr[2]!=0){
            if(arr[0]==arr[1] && arr[0]==arr[2]){
                win = arr[0];
            }
        }
        if(arr[3]!=0 && arr[4]!=0 && arr[5]!=0){
            if(arr[3]==arr[4] && arr[3]==arr[5]){
                win = arr[3];
            }
        }
        if(arr[6]!=0 && arr[7]!=0 && arr[8]!=0){
            if(arr[6]==arr[7] && arr[6]==arr[8]){
                win = arr[6];
            }
        }
        if(arr[0]!=0 && arr[3]!=0 && arr[6]!=0){
            if(arr[0]==arr[3] && arr[0]==arr[6]){
                win = arr[0];
            }
        }
        if(arr[1]!=0 && arr[4]!=0 && arr[7]!=0){
            if(arr[1]==arr[4] && arr[1]==arr[7]){
                win = arr[1];
            }
        }
        if(arr[2]!=0 && arr[5]!=0 && arr[8]!=0){
            if(arr[2]==arr[5] && arr[2]==arr[8]){
                win = arr[2];
            }
        }
        if(arr[0]!=0 && arr[4]!=0 && arr[8]!=0){
            if(arr[0]==arr[4] && arr[0]==arr[8]){
                win = arr[0];
            }
        }
        if(arr[2]!=0 && arr[4]!=0 && arr[6]!=0){
            if(arr[2]==arr[4] && arr[2]==arr[6]){
                win = arr[2];
            }
        }

        if(win!=0){
            if(win==1){
                cout<<"Player 1 wins!!!"<<endl;
            }
            else{
                cout<<"Player 2 wins!!!"<<endl;
            }
            break;
        }

        if(flag==0){
            flag=1;
        }
        else{
            flag=0;
        }
        cout<<endl;
        cout<<"\t\t";
    }

    return 0;
}
