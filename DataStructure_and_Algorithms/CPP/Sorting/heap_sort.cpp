// C++ program for HeapSort 
#include<iostream>
using namespace std;
/*Printing the Heap*/
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";	
	}
}
/*Heapify the heap using top down approach*/
void heapify(int a[], int n, int i)
{
    int big = i; // Initialize big as root
    int left = 2*i+1; // left = 2*i + 1
    int right = 2*i+2; // right = 2*i + 2
    // If left child is larger than root
    if (left<n && a[left]>a[big])
        big = left;
    // If right child is larger than largest so far
    if (right<n && a[right]>a[big])
        big = right;
    // If big is not root
    if (big!=i) {
        swap(a[i],a[big]);
        // Recursively heapify the affected sub-tree
        heapify(a,n,big);
    }
}
// Main Recursive function to do heap sort
void heapsort(int a[],int n)
{
	// Build heap (rearrange array)
	for(int i=(n/2)-1;i>=0;i--)
	{
		heapify(a,n,i);
	}
	// One by one extract an element from heap
	for(int i=n-1;i>=0;i--)
	{
		// Move current root to end
		swap(a[0],a[i]);
		// call max heapify on the reduced heap
		heapify(a,i,0);
	}
}
/*Driver Function*/
int main()
{
	/*Initial elements are */
	int a[]={21,22,19,131,7,5,7,1,0,13};
	int n=10; //size of the array
	cout<<"Before Sorting"<<endl;
	printArray(a,n);
	heapsort(a,n); //sorting function
	cout<<"\nAfter Sorting"<<endl;
	printArray(a,n);
	return 0;
}
