// You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.

// Examples :

// Input: n = 2, m = 9
// Output: 3
// Explanation: 32 = 9
// Input: n = 3, m = 9
// Output: -1
// Explanation: 3rd root of 9 is not integer.
// Input: n = 1, m = 14
// Output: 14

   int nthRoot(int n, int m) {
        int l=1,h=m; //we'll find l=1 and h=m and the root will a number lies between l and h
        if(m==1 || n==1)
        return m;
        while(l<=h){
            int mid=l + (h - l) / 2;
            int k=pow(mid,n);
            if(k==m)
            return mid;
            else if(k<m){
               l= mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return -1;
    }
