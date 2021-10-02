
// ............................. Quick Sort : O(NlogN) ......................
//                 principle : it choose a pivote element from array and part 
//      the array around that element it, continue untill it cannot be part further then sort every part 

#include<bits/stdc++.h>
using namespace std;

// partition function
int partition(int arr[], int l, int r){
   
   // 3 approach

   // if pivote is first element 
 //...............................................................................................
 
  
  /*
   int pivote = arr[l];
   int i = l;

   for(int j=l+1; j<=r; j++){
       if(arr[j] < pivote){
           i++;
           swap(arr[j],arr[i]);
       }
   }

   swap(arr[i],arr[l]);
   return i++;

   */

   
//.....................OR.....................................................................
   
   /*
   int pivote = arr[l];
   int index=0;
   for(int i=l; i<=r; i++)
      if(arr[i]<pivote)
          index++;

   swap(arr[l],arr[l+index]);
    int i=l,j=r;
   while(i<(l+index) && j>(l+index)){
       if(arr[i]<pivote)
          i++;
        else if(arr[j]>=pivote)
         j--;
        else{
            swap(arr[i],arr[j]);
            i++; j--;
        }   
   }

   return l+index;       

   */








      // if pivote is last element
//.................................................................................................   
   
   /*
    int pivote = arr[r];
    int i = l-1;

    for(int j=l; j<r; j++){
        if(arr[j] < pivote){
            i++;
            swap(arr[j], arr[i]);
        }    
    }
    swap(arr[i+1], arr[r]);
    return i++;

   */
//......................OR....................................................................
    
   /* 
   int pivote = arr[r];
   int index=0;
   for(int i=l; i<=r; i++)
      if(arr[i]<pivote)
          index++;

   swap(arr[r],arr[l+index]);
    int i=l,j=r;
   while(i<(l+index) && j>(l+index)){
       if(arr[i]<pivote)
          i++;
        else if(arr[j]>=pivote)
         j--;
        else{
            swap(arr[i],arr[j]);
            i++; j--;
        }   
   }

   return l+index;      

   */







   // if middle element is pivote 
//.............................................................................................
   
   
   int mid = l + (r-l)/2;
   int pivote = arr[mid];

   int index=0;
   for(int i=l; i<=r; i++)
      if(arr[i]<pivote)
          index++;

   swap(arr[mid],arr[l+index]);

   int i=l,j=r;
   while(i<(l+index) && j>(l+index)){
       if(arr[i]<pivote)
          i++;
        else if(arr[j]>=pivote)
         j--;
        else{
            swap(arr[i],arr[j]);
            i++; j--;
        }   
   }

   return l+index; 
        
    
}


//    Quick Sort Function
void quickSort(int arr[], int l, int r){
    if(l>=r)
      return;

    int pi = partition(arr, l, r);

    quickSort(arr,l,pi-1);
    quickSort(arr,pi+1,r);  
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

    quickSort(arr,0,n-1);

    for(int x : arr)
        cout << x << " ";

     cout << endl;   
    }
    
    return 0;
}