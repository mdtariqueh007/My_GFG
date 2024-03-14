//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        // code here
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{0,0}));
        
        if(a[0][0]=='X'){
            dp[0][0] = {1,1};
        }
        
        
        for(int j = 1;j<n;j++){
            if(a[0][j]=='X'){
                dp[0][j] = {dp[0][j-1].first + 1,1};
            }
        }
        
        for(int i = 1;i<n;i++){
            if(a[i][0]=='X'){
                dp[i][0] = {1, dp[i-1][0].second+1};
            }
        }
        
        
        for(int i = 1;i<n;i++){
            for(int j = 1;j<n;j++){
                if(a[i][j]=='X'){
                    dp[i][j] = {dp[i][j-1].first+1,dp[i-1][j].second+1};
                }
            }
        }
        
        int res = 0;
        
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                int val = min(dp[i][j].first,dp[i][j].second);
                
                // cout<<i<<" "<<j<<"\n";
                
                while(val>res){
                    if(dp[i][j-val+1].second>=val && dp[i-val+1][j].first>=val){
                    
                        res = val;
                    }
                    
                    val--;
                
                }
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends