//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       int n = str.size();
       
       const int mod = 1e9+7;
       
       long long int dp[n+2][n+2];
       
       memset(dp,0,sizeof(dp));
       
       for(int i = 0;i<n;i++){
           dp[i][i] = 1;
       }
       
       for(int len = 2;len<=n;len++){
           for(int i = 0;i<=n-len;i++){
               int j = i + len - 1;
               if(str[i]==str[j]){
                   dp[i][j] = (1 + dp[i+1][j]+dp[i][j-1])%mod;;
               }else{
                   dp[i][j] = (dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1] + mod)%mod;
               }
           }
       }
       
       return dp[0][n-1]%mod;
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends