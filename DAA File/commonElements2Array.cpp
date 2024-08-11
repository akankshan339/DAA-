// given 2 sorted integer arrays of size m and n. find elements which are common to both.
// TC O(m+n)
#include<bits/stdc++.h>
using namespace std;

vector<int> CommonElements_2Arrays(vector<int>&arr1, vector<int>&arr2, int m, int n)
{
    vector<int>common;
    int i =0 , j=0;
    while( i<m && j <n)
    {
        if(arr1[i] == arr2[j])
        {
            common.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j])          //arr[i] cannot be found in arr[j] so increment i
            i++;
        else
            j++;
    }
    return common;

}
int main()
{
    int m,n;
    cout<<"Enter size of both arrays: \n";
    cin>>m>>n;
    vector<int>arr1(m);
    vector<int>arr2(n);
    vector<int>common;
    cout<<"Enter elements of 2 arrays in sorted order: \n";
    cout<<"Enter array 1 element :\n";
    for(int i =0;i<m; i++)
    {
    cin>>arr1[i];
    }
    cout<<"Enter array 2 element :\n";
    for(int i =0;i<n; i++)
    {
    cin>>arr2[i];
    }
    common = CommonElements_2Arrays(arr1, arr2, m, n);

    cout<<"Common Elements are : \n";
    for(int i =0;i<common.size(); i++)
    { 
        cout<<common[i]<<" ";
    }

    return 0;
}
