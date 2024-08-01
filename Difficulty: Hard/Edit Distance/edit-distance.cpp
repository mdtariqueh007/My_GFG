//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int dp[101][101];
    int solve(int i,int j,string& str1,string&str2){
        if(i<0) return j + 1;
        if(j<0) return i + 1;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(str1[i]==str2[j]){
            return solve(i-1,j-1,str1,str2);
        }
        
        int insert = 1 + solve(i, j - 1, str1,str2);
        int del = 1 + solve(i - 1,j,str1,str2);
        int replace = 1 + solve(i-1,j-1,str1,str2);
        
        return dp[i][j] = min({insert , del, replace});
    }
  public:
    int editDistance(string str1, string str2) {
        // Code here
        
        int n = str1.size();
        int m = str2.size();
        
        memset(dp,-1,sizeof(dp));
        
        return solve(n-1,m-1,str1,str2);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends