//find whether two elements exist such that their sum is equal to the given key arr[i] +arr[j] = key
//TC  = O(n log n))
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr, int lt, int rt)
{
int pivot = arr[rt];
int i = lt -1;
for(int j =lt; j<rt; j++)
{
    if(arr[j] < pivot)
    {
        i++;
        swap(arr[i], arr[j]);
    }
}
swap(arr[i+1], arr[rt]);        //all elements less than pivot are on its left side and all greater than it are on its right side
return i+1;
}

void sortQuick(vector<int>&arr, int lt, int rt)
{
    if(lt < rt)                             //Or if(lt > rt) return;
    {
        int pi = partition(arr, lt, rt);
        sortQuick(arr, lt, pi-1);
        sortQuick(arr, pi+1, rt);
    }
}

pair<int, int> keySum(vector<int>&arr, int key, int n)
{
    pair<int, int> p;
    int i =0, j = n-1;
    while(i < j)
    {
        if(arr[i] +arr[j] == key)
        {
            p= {arr[i] , arr[j]};
            return p;
        }
        else if(arr[i] +arr[j] < key)   //if sum < key
        {
            i++;
        }
        else                            //if sum > key
        j--;
    }
    return {-1, -1};
}
int main()
{
    int n,key;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int>arr(n);
    pair<int, int> p;
    cout<<"Enter array elements: ";
    for(int i =0;i<n; i++)
    {
    cin>>arr[i];
    }
    cout<<"Enter value of key: ";
    cin>>key;

    sortQuick(arr, 0, n-1);
    cout<<"Sorted array : \n";
     for(int i =0;i<n; i++)
     {
        cout<<arr[i] <<" ";
     }
    cout<<"\n";
    p=keySum(arr, key, n);
    if(p.first != -1 && p.second != -1)
    cout<<p.first<<" and "<<p.second<<" are 2 elements in array whoes sum is equal to "<<key;
    else
    cout<<"\nNo such 2 elements are found in array ";
    return 0;
}
//64 28 97 40 12 72 84 24 38 10