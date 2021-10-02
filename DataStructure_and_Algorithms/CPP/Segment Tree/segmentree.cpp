#include<bits/stdc++.h>
using namespace std;


void updateSegmentTree(int arr[], int tree[], int start, int end, int node, int idx, int value){
    if(start==end){
        return;
    }
    if(start==idx || end==idx){
        arr[idx] = value;
        tree[node] = arr[idx];
        return ;
    }

    int mid = (start+end)/2;
    int node1 = node*2;
    int node2 = node*2+1;
    if(mid<=idx){
        updateSegmentTree(arr, tree, start, mid, node1, idx, value);
    }else {
        updateSegmentTree(arr, tree, mid+1, end, node2, idx, value);
    }

    tree[node] = tree[node1]+tree[node2];
}

void makeSegmentTree(int arr[], int tree[], int start, int end, int node){
    if(start==end){
        tree[node] = arr[start];
        return ;
    }
    int mid = (start+end)/2;
    int node1 = node*2;
    int node2 = node*2+1;
    makeSegmentTree(arr, tree, start, mid, node1);
    makeSegmentTree(arr, tree, mid+1, end, node2);
    tree[node] = tree[node1]+tree[node2];
}

int main(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin); 
      freopen("output.txt", "w", stdout);
    #endif

    int n; 
    cin >> n; 

    int arr[n] ;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i : arr) cout << i << " "; 
    cout << endl;
    int* tree = new int[2*n];
    makeSegmentTree(arr, tree, 0, n-1, 1);
    for(int i=1; i<2*n; i++)
       cout << tree[i] << " ";
    
    cout << endl;

    updateSegmentTree(arr, tree, 0, n-1, 1, 4, 200);   
    for(int i=1; i<2*n; i++)
       cout << tree[i] << " ";

    cout << endl;
    for(int i : arr) cout << i << " "; 

    // cout << findSegmentSum(tree, (2*n), 1, 3,6);
    return 0;
}