https://leetcode.com/problems/maximum-subarray/



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsofar=nums[0];
        int max_ending_here=0;
        for(int i=0;i<nums.size();i++)
        {
           max_ending_here+=nums[i];
            if(max_ending_here>maxsofar)
                maxsofar=max_ending_here;
            if(max_ending_here<0)
                max_ending_here=0;
        }
        return maxsofar;
        
    }
};
