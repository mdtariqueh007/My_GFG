//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    long long dp[4][3][26];
    long long helper(int i,int j,int n){
        if(i>=4 or i<0 or j<0 or j>=3){
            return 0;
        }
        if(i==3 and (j==0 or j==2)){
            return 0;
        }
        
        if(n==1){
            return 1;
        }
        
        if(dp[i][j][n]!=-1){
            return dp[i][j][n];
        }
        
        int dx[] = {0,-1,1,0,0};
        int dy[] = {0,0,0,-1,1};
        
        long long ans = 0;
        
        for(int k = 0;k<5;k++){
            ans += helper(i+dx[k],j+dy[k],n-1);
        }
        
        return dp[i][j][n] = ans;
    }
  public:
    long long getCount(int n) {
        // Your code goes here
        long long ans = 0;
        
        memset(dp,-1,sizeof(dp));
        
        for(int i = 0;i<4;i++){
            for(int j = 0;j<3;j++){
                if(i==3 and (j==0 or j==2)) continue;
                
                ans += helper(i,j,n);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends