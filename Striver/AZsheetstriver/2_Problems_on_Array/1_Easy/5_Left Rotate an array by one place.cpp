#include<bits/stdc++.h>
using namespace std;

void left_rotate_array_by_one(vector<int> &nums,int k)
{
          int n = nums.size();
          k = k%n;

        /*  
            1 2 3 4 5 6 --> original array and k = 3

            3 2 1 4 5 6

            3 2 1 6 5 4
            
            4 5 6 1 2 3
        */
        
          // Reverse the first n - k numbers.
          // Index i (0 <= i < n - k) becomes n - k - i.
          reverse(nums.begin(),nums.begin()+n-k);
            
          // Reverse tha last k numbers.
          // Index n - k + i (0 <= i < k) becomes n - i.
          reverse(nums.begin() + n - k, nums.begin() + n);
            
          // Reverse all the numbers.
          // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
         // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
          reverse(nums.begin(), nums.end());
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    left_rotate_array_by_one(arr,k);
    cout<<"output of the array"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i];
    cout<<endl;
    return 0;
}