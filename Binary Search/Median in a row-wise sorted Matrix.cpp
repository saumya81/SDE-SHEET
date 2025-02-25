// Given a row-wise sorted matrix where the number of rows and columns is always odd, find the median of the matrix.

// Examples:

// Input: mat = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
// Input: mat = [[1], [2], [3]]
// Output: 2
// Explanation: Sorting matrix elements gives us {1,2,3}. Hence, 2 is median
// Input: mat = [[3], [5], [8]]
// Output: 5
// Explanation: Sorting matrix elements gives us {3,5,8}. Hence, 5 is median.
// Constraints:
// 1 <= mat.size(), mat[0].size() <= 400
// 1 <= mat[i][j] <= 2000



class Solution {
  public:
    int findSmallerEqual(int mid,vector<vector<int>> mat){ // find how many element are smaller than the mid
        int cnt=0;
        for(int i=0;i<mat.size();i++){
            auto it = upper_bound(mat[i].begin(), mat[i].end(), mid);
        cnt += (it - mat[i].begin());
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        int mini=INT_MAX,maxi=INT_MIN;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<mat.size();i++){
            mini=min(mat[i][0],mini);
            maxi=max(mat[i][n-1],maxi);
        }
        int l=mini,h=maxi;
        int req=(n*m)/2; // required number of element less than the mid , i,e exact position of median
        while(l<=h){
            int mid=l+(h-l)/2;
            if(findSmallerEqual(mid,mat)<=req){
                l=l+1;
            }
            else{
                h=h-1;
            }
        }
        return l;
    }
};
