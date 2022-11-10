#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> a;
        if(nums.size()<3) return a;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;++i)
        {
            if(nums[i]>0) break;
            if(i>0 and nums[i] == nums[i-1]) continue;
            int left = i+1,right = n - 1;
            while(left<right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum<0) ++left;
                else if(sum>0) --right;
                else
                {
                    a.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left+1] == nums[left]) ++left;
                    while(left<right && nums[right-1] == nums[right]) --right;
                    left++;
                    right--;
                }
            }
        }
        return a;
    }
};