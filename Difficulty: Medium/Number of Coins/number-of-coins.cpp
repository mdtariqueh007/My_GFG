//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    int solve(int ind,vector<int>&coins,int v,vector<vector<int>>&dp){
        if(v<0){
            return 1e9;
        }
        if(ind==0){
            if(v%coins[ind]==0){
                return v/coins[0];
            }
            else{
                return 1e9;
            }
        }
        
        if(dp[ind][v]!=-1){
            return dp[ind][v];
        }
        
        int take = 1e9;
        
        int notTake = solve(ind-1,coins,v,dp);
        
        if(v>=coins[ind]){
            take = 1 + solve(ind,coins,v-coins[ind],dp);
        }
        
        return dp[ind][v] = min(take,notTake);
    }
	public:
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(M,vector<int>(V+1,-1));
	    
	    int ans = solve(M-1,coins,V,dp);
	    
	    return (ans==1e9)?-1:ans;
	    
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends