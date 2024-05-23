//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    const int mod = 1e9 + 7;
    int helper(int ind,vector<int>&arr,vector<vector<int>>&dp,int target){
        if(ind==0){
            if(target==0 && arr[0]==0){
                return 2;
            }
            if(target==0  || arr[0]==target){
                return 1;
            }
            
            return 0;
        }
        
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        
        int pick = 0;
        int notPick = 0;
        
        notPick = helper(ind-1,arr,dp,target);
        if(arr[ind]<=target){
            pick = helper(ind-1,arr,dp,target-arr[ind]);
        }
        
        return dp[ind][target] = (pick + notPick)%mod;
    }
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totSum = 0;
        
        for(int i = 0;i<n;i++){
            totSum += arr[i];
        }
        
        if(totSum<d){
            return 0;
        }
        
        if((totSum-d)%2==1){
            return 0;
        }
        
        int s = (totSum-d)/2;
        
        vector<vector<int>> dp(n+1,vector<int>(s+1,-1));
        
        return helper(n-1,arr,dp,s);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends