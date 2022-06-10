https://leetcode.com/problems/merge-intervals/



class Solution {
public:
   static bool comp(vector<int> t1,vector<int> t2)
    {
            return  t1[0]<t2[0];
      
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> ans ;
        ans.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++)
        {
            if(ans.back()[1]>=intervals[i].front())
            {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
            else
                ans.push_back(intervals[i]);
        }
        return ans;
        
    }
};
