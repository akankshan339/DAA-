//Eculid GCD Algorithm find element with maximum no of occurence
//increment arr[ arr[i] % k] by k 
//TC O(N) SC O(1)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cout<<"Enter array size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter array elements: ";
    for(int i =0;i<n; i++)
    {
    cin>>arr[i];
    }
    cout<<"Enter value of k: ";
    cin>>k;
    int currmax= -1;
    int ele =0;
    for(int i =0;i<n; i++)
    {
        arr[ arr[i] % k] = arr[ arr[i] % k] + k;

        if(arr[ arr[i] % k] > currmax)
        {
            currmax = arr[ arr[i] % k];
            ele = arr[i] % k;
        }
    }
   
    
    cout<<"Element with maximum no of occurence in array is: "<<ele;
    return 0;
}
