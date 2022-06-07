https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind1,ind2;
        bool flag=false;
        for(int i=nums.size()-2;i>=0;i--)
        {
           if(nums[i]<nums[i+1])
           {
               ind1=i;
               flag=true;
               break;
           }
        }
        if(ind1<0)
        {
           reverse(nums.begin(),nums.end()); 
        }
        else
        {
            for(int i=nums.size()-1;i>ind1;i--)
            {
                if(nums[i]>nums[ind1])
                {
                      ind2=i;
                     break;
                }
            }
            swap(nums[ind1],nums[ind2]);
            reverse(nums.begin()+ind1+1,nums.end());
        }
      
    }
};
