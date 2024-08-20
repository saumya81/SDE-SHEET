
// Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.

// Examples:

// Input: mat[][] = [[1, 0, 0, 0],
//                 [1, 1, 0, 1], 
//                 [1, 1, 0, 0],
//                 [0, 1, 1, 1]]
// Output: DDRDRR DRDDRR
// Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
// Input: mat[][] = [[1, 0],
//                 [1, 0]]
// Output: -1
// Explanation: No path exists and destination cell is blocked.


class Solution{
    public:
     void solve(int i,int j,vector<vector<int>> &m,int n,
    vector<vector<int>> &visited,vector<string> &ans,string path,int di[],int dj[])
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(path);
            return;
        }
        string direction="DLRU";
        for(int idx=0;idx<4;idx++)
        {
            int nexti=i+di[idx];
            int nextj=j+dj[idx];
            if(nexti>=0 && nextj>=0 && nexti<n && nextj<n 
            && m[nexti][nextj]==1 && visited[nexti][nextj]==0)
            {
                visited[i][j]=1;
                solve(nexti,nextj,m,n,visited,ans,path+direction[idx],di,dj);
                visited[i][j]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
      vector<vector<int>> vis(n,vector<int>(n,0));
       vector<string> ans;
       int di[]={1,0,0,-1};
       int dj[]={0,-1,1,0};
       if(m[0][0]==1)
       solve(0,0,m,n,vis,ans,"",di,dj);
       return ans;
    }
};
