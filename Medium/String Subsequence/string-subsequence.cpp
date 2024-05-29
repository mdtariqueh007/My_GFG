//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
    int dp[501][501];
    const int mod = 1e9+7;
    int helper(int i,int j,string s1,string s2){
        if(j<0) return 1;
        
        if(i<0) return 0;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s1[i]==s2[j]){
            return dp[i][j] = (helper(i-1,j-1,s1,s2)%mod + helper(i-1,j,s1,s2)%mod)%mod;
        }else{
            return dp[i][j] = helper(i-1,j,s1,s2)%mod;
        }
    }
  public:
    int countWays(string s1, string s2) {
        // code here
        memset(dp,-1,sizeof(dp));
        return helper(s1.length()-1,s2.length()-1,s1,s2);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends