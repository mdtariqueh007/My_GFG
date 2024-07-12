//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    typedef long long ll;
    
    const int mod = 1003;
    
    int dp[201][201][2];
    
    ll solve(int i, int j, bool isTrue, string &s){
        if(i>j){
            return 0;
        }
        
        if(i==j){
            if(isTrue){
                return s[i]=='T';
            }
            else{
                return s[i]=='F';
            }
        }
        
        if(dp[i][j][isTrue]!=-1){
            return dp[i][j][isTrue];
        }
        
        ll ways = 0;
        
        for(int ind = i + 1;ind<=j-1;ind+=2){
            ll lt = solve(i,ind-1,1,s);
            ll lf = solve(i,ind-1,0,s);
            ll rt = solve(ind+1,j,1,s);
            ll rf = solve(ind+1,j,0,s);
            
            if(s[ind]=='&'){
                if(isTrue){
                    ways = (ways + lt*rt)%mod;
                }
                else{
                    ways = (ways + lt*rf + lf*rt + lf*rf)%mod;
                }
            }
            else if(s[ind]=='|'){
                if(isTrue){
                    ways = (ways + lt*rt + lt*rf+ lf*rt)%mod;
                }
                else{
                    ways = (ways + lf * rf)%mod;
                }
            }
            else if(s[ind]=='^'){
                if(isTrue){
                    ways = (ways + lt*rf + lf*rt)%mod;
                }
                else{
                    ways = (ways + lt*rt + lf*rf)%mod;
                }
            }
        }
        
        return dp[i][j][isTrue] = ways;
    }
public:
    int countWays(int n, string s){
        // code here
        
        // int n = s.size();
        
        memset(dp,-1,sizeof(dp));
        
        return solve(0,n-1,1,s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends