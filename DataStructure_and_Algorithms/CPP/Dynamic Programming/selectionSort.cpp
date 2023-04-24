//.............. Selection sort O(N^2) ................
//            princple : it is something like insertion sort , it has two array sorted and unsorted
//      each time it pick the minimum element from unsorted array and put it in sorted array at right position(at last) 


#include<bits/stdc++.h>
using namespace std;


// function for sort by recursion   (select max element and put at last i.e first of sorted array)
void selectionSort1(int arr[], int n){
      if(n<=1)
      return ;

    int max = INT_MIN;
    int maxIndex = n-1;
    for(int i=0; i<n; i++)
         if(max < arr[i]){
             max = arr[i];
             maxIndex = i;
         }
    if(maxIndex != n-1){
       arr[maxIndex] = arr[n-1];      
       arr[n-1] = max;
    }

    selectionSort1(arr,n-1);
}
//  OR ....  (Select Min and put at first i.e. last of sorted array)
void secondRecursion(int arr[], int n, int index=0){
      if(n<=index)
      return ;

    int min = INT_MAX;
    int minIndex = index;
    for(int i=index; i<n; i++)
         if( min > arr[i]){
             min = arr[i];
             minIndex = i;
         }
   if(minIndex != index){
        arr[minIndex] = arr[index];      
        arr[index] = min;

   }
    secondRecursion(arr,n,index+1);
}

// by iterator .....
void selectionSort2(int arr[], int n){
    if(n<=1)
      return ;
      
      int lastIndexOfSorted = 0;
      for(int i=0; i<n-1; i++){
          int min = INT_MAX;
          int minIndex = i;
          for(int j=lastIndexOfSorted; j<n; j++)
                if(min > arr[j]){
                    min = arr[j];
                    minIndex = j;
                }
         if(minIndex != lastIndexOfSorted){
             arr[minIndex] = arr[lastIndexOfSorted];
             arr[lastIndexOfSorted] = min;
         } 
         lastIndexOfSorted++;      
      }


}


int main(){
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
    #endif
       freopen("output.txt","w",stdout);
    
    int test; cin >> test;
    while(test--){
    int n; cin >> n; 
    int arr[n];

    for(int i=0; i<n; i++)
       cin >> arr[i];

    selectionSort1(arr,n);        // recursion
   //secondRecursion(arr,n);        // recursion
   //selectionSort2(arr,n);        // iterartor

    for(int x : arr)
        cout << x << " ";

     cout << endl;   
    }
    
    return 0;
} 