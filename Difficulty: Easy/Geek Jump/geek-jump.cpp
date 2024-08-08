//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int dp[100001];
    int solve(int ind,vector<int>&height){
        if(ind>=height.size()-1){
            return 0;
        }
        
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        int oneStep = 1e9;
        int twoStep = 1e9;
        
        if((ind+1)<=height.size()-1){
            oneStep = abs(height[ind] - height[ind+1]) + solve(ind+1,height);
        }
        if((ind+2)<=height.size()-1){
            twoStep = abs(height[ind] - height[ind+2]) + solve(ind+2,height);
        }
        
        return dp[ind] = min(oneStep,twoStep);
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        
        memset(dp,-1,sizeof(dp));
        
        return solve(0,height);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends