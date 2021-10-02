#include<iostream>
#include<vector>
using namespace std;
void heapify(int idx,vector<int> &v)
    {
        int left = idx * 2;
        int right  = left + 1;
        int last = v.size() - 1;
        int min_idx = idx;
        if(left <= last && v[left] > v[idx])
        {
            min_idx = left;
        } 
        if(right <= last && v[right] > v[min_idx])
        {
           min_idx = right;
        }
        if(min_idx != idx)
        {
            swap(v[idx],v[min_idx]);
            heapify(min_idx,v);
        }
    }
void build_heap(vector<int> &v)
{
    for(int i = (v.size() - 1/2);i >= 1;i--)
    {
        heapify(i,v);
    }
} 


void print(vector<int> &v)
{
    for(int i = 0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}

int main()
{
    vector<int> v;
    v.push_back(-1);
    int n;
    cin>>n;
    while(n--)
    {
        int no;
        cin>>no;
        v.push_back(no);
    }
    print(v);
    build_heap(v);
    cout<<endl;
    print(v);
    return 0;
}
