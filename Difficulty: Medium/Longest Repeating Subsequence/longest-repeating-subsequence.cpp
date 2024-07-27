//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    int dp[1001][1001];
    int helper(int i,int j,string &s,string &t){
        if(i==s.size() || j==t.size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==t[j] && i!=j){
            return dp[i][j] = 1 + helper(i+1,j+1,s,t);
        }
        
        return dp[i][j] = max(helper(i+1,j,s,t),helper(i,j+1,s,t));
    }
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    
		    memset(dp,-1,sizeof(dp));
		    
		    string t(str);
		    
		    return helper(0,0,str,t);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends