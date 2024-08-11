//find common elemnts in 3 sorted array
//TC O(l + m + n)
//Approach 1 using 2 pointer, find common in 2 arrays and then again find common in comman array and 3rd array 
//Approach 2 using 3 pointer
#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

vector<int> CommonElements_3Arrays(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    vector<int> ans;
    int i = 0, j = 0, k = 0;
    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            ans.push_back(arr1[i]);
            i++;
            j++;
            k++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr3[k]) {
            j++;
        } else {
            k++;
        }
    }
    return ans;
}

int main() {
    int l, m, n;
    cout << "Enter size of all 3 arrays: ";
    cin >> l >> m >> n;
    vector<int> arr1(l);
    vector<int> arr2(m);
    vector<int> arr3(n);
    cout << "Enter elements of 3 arrays in sorted order: \n";
    cout << "Enter array 1 elements: ";
    for (int i = 0; i < l; i++) {
        cin >> arr1[i];
    }
    cout << "Enter array 2 elements: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    cout << "Enter array 3 elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr3[i];
    }
    vector<int> ans = CommonElements_3Arrays(arr1, arr2, arr3);
    cout << "Common Elements are: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

//  1, 5, 10, 20, 40, 80 };
// { 6, 7, 20, 80, 100 };
// { 3, 4, 15, 20, 30, 70, 80, 120


//using 2 pointer
/*
#include<bits/stdc++.h>
using namespace std;

vector<int> CommonElements_3Arrays(vector<int>&arr1, vector<int>&arr2, vector<int>&arr3, vector<int>&common, int l, int m, int n)
{
vector<int>ans;
int i = 0, j=0;
while(i < l && j <m)
{
    if(arr1[i] == arr2[j])
    {
        common.push_back(arr1[i]);
        i++;
        j++;
    }
    else if(arr1[i] < arr2[j])      //arr[i] cannot be found in arr[j] so increment i
        i++;
    else
        j++;
}
int len = common.size();
//finding common elements in common array and in arr3
while(i < len && j <n)
{
   if(common[i] == arr3[j])
   {
        ans.push_back(common[i]);
        i++;
        j++;
   }
    else if(common[i] < arr2[j])      //arr[i] cannot be found in arr[j] so increment i
        i++;
    else
        j++; 
}
return ans;
}
int main()
{
    int l,m,n;
    cout<<"Enter size of all 3 arrays: \n";
    cin>>l>>m>>n;
    vector<int>arr1(l);
    vector<int>arr2(m);
    vector<int>arr3(n);
    vector<int>common;
    vector<int>ans;
    cout<<"Enter elements of 3 arrays in sorted order: \n";
    cout<<"Enter array 1 elements: \n";
    for(int i =0;i<l; i++)
    {
    cin>>arr1[i];
    }
    cout<<"Enter array 2 elements: \n";
    for(int i =0;i<m; i++)
    {
    cin>>arr2[i];
    }
    cout<<"Enter array 3 elements: \n";
    for(int i =0;i<n; i++)
    {
    cin>>arr3[i];
    }
    ans = CommonElements_3Arrays(arr1, arr2, arr3, common, l, m, n);

    cout<<"Common Elements are : \n";
    for(int i =0;i<ans.size(); i++)
    { 
        cout<<ans[i]<<" ";
    }

    return 0;
}
*/



