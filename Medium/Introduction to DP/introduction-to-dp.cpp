//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  const int mod = 1e9+7;
  long long int memo[10001];
  long long int helper(int n){
      if(n==0 || n==1){
            return n;
        }
        
        if(memo[n]!=-1){
            return memo[n];
        }
        
        return memo[n] =  (helper(n-1)%mod + helper(n-2)%mod)%mod;
  }
    long long int topDown(int n) {
        // code here
        
        memset(memo,-1,sizeof(memo));
        
        return helper(n);
        
    }
    long long int bottomUp(int n) {
        // code here
        
        vector<long long int> dp(n+1,0);
        
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2;i<=n;i++){
            dp[i] = (dp[i-1]%mod + dp[i-2]%mod)%mod;
        }
        
        return dp[n];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends