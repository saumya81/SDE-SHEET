https://www.interviewbit.com/problems/repeat-and-missing-number-array/


vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int n1=A.size();
 long long int s=n1*(n1+1)/2;
    long long int p=(n1*(n1+1)*(2*n1+1))/6;
    for(int i=0;i<n1;i++)
    {
        s=s-(long long int)A[i];
        p=p-(long long int)A[i]*(long long int)A[i];
    }
    int miss=(s+p/s)/2;
    int rep=miss-s;
   vector<int> ans;
   ans.push_back(rep%1000000007);
   ans.push_back(miss%1000000007);
   return ans;
    
}
