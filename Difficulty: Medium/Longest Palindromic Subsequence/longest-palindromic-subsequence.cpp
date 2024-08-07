//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    int LCS(string &s,string &t){
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
       for(int j = 0;j<=m;j++){
           dp[0][j] = 0;
       }
       for(int i = 0;i<=n;i++){
           dp[i][0] = 0;
       }
       
       for(int i = 1;i<=n;i++){
           for(int j = 1;j<=n;j++){
               if(s[i-1]==t[j-1]){
                   dp[i][j] = 1 + dp[i-1][j-1];
               }
               else{
                   dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
               }
           }
       }
       
       return dp[n][m];
    }
  public:
    int longestPalinSubseq(string A) {
        //code here
        string rev(A);
        
        reverse(rev.begin(),rev.end());
        
        return LCS(A,rev);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends