//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    #define ll long long
    ll powerMod(ll x, ll n, ll mod)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n = n >> 1;
    }

    return res;
}
    long long dp[100001][2];
    const int mod = 1e9 + 7;
    long long helper(int n,int prev){
        if(n==0){
            return 0;
        }
        
        if(n==1){
            if(prev==0){
                return 2;
            }
            else{
                return 1;
            }
        }
        
        if(dp[n][prev]!=-1){
            return dp[n][prev];
        }
        
        if(prev==1){
            return dp[n][prev] = helper(n-1,0)%mod;
        }
        else{
            return dp[n][prev] = (helper(n-1,1)%mod + helper(n-1,0)%mod)%mod;
        }
    }
  public:
    int numberOfConsecutiveOnes(int n) {
        // code here
        
        memset(dp,-1,sizeof(dp));
        
        return  (powerMod(2LL,n,mod) - helper(n,0)+mod)%mod;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends