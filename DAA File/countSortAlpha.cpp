//find element with maximum no of occurence TC O(N) SC O(N) using freq array using count sort
#include<bits/stdc++.h>
using namespace std;
char countSort(vector<char>&arr, int n)
{
    vector<int>freq(256, 0);          //to cover all ASCII characters. Each index in this array represents an ASCII value of a character.
    // vector<int>freq(26, 0);
    int maxfreq = 0;
    char ch;
    for(int i =0; i<n; i++)
    {
        freq[arr[i]]++;
    }

     for(int i =0; i<256; i++)      //for(int i =97; i<122; i++) //only for lower case alphbets
     {
        if(freq[i] > maxfreq)
        {
            maxfreq = freq[i];
            ch = (char)i;
        }
     }
     if(maxfreq <= 1)
    {
     return '\0';
    }
    else
    cout<<"Maximum occurence is : "<<maxfreq;

return ch;
}
int main()
{
    int n,k;
    cout<<"Enter array size: ";
    cin>>n;
    vector<char>arr(n);
    cout<<"Enter alphabets: ";
    for(int i =0;i<n; i++)
    {
    cin>>arr[i];
    }
    char ch=countSort(arr, n);
    if(ch != '\0')
    cout<<"\nElement with maximum no of occurence in array is: "<<ch;
    else
     cout<<"No Duplicate found : \n";
    return 0;
}