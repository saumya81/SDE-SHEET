https://leetcode.com/problems/set-matrix-zeroes/ 


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool flag=false;
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;i++)
        {
            if(matrix[i][0]==0)
                    flag=true;
      //col will start from 1 
            for(int j=1;j<col;j++)
            {
                
                if(matrix[i][j]==0)
                    matrix[i][0]= matrix[0][j]=0;

            }
        }
        for(int i=row-1;i>=0;i--)
        {
        //need not to check for first row as this case is already been checked by flag 
             for(int j=col-1;j>=1;j--)
             {
                 if(matrix[i][0]==0 || matrix[0][j]==0)
                     matrix[i][j]=0;
             }
            if(flag==true)
            matrix[i][0]=0;
        }
        
        
        
    }
};
