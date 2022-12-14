/* MAximum sum of Non-Adjacent Elements*/
#include <bits/stdc++.h>
using namespace std;

int f(int ind,vector<int> &nums,vector<int> &dp)//
{
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind]; //check if it exists in dp array so that to avoid overlapping sub intervals and reduce time complexity

    int pick = nums[ind] + f(ind-2,nums,dp);
    int notpick = 0 + f(ind-1,nums,dp);
    return dp[ind] = max(pick,notpick);
}

int maximumNonAdjacentsum(vector<int> &nums) //  Recursion --> Memorisation
{
    int n = nums.size();
    vector<int> dp(n,-1);
    return f(n-1,nums,dp);
}

int maximumNonAdjacentsum(vector<int> &nums) // Tabulation --> space optimisation

{
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i = 1;i<n;i++)
    {
        int take = nums[i];
        if(i>1) take += prev2;
        int nottake = 0 + prev;
        int  curi = max(take,nottake);
        prev2 = prev;
        prev = curi;

    }
    return prev;
}




int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<maximumNonAdjacentsum(arr);
    return 0;
    
}