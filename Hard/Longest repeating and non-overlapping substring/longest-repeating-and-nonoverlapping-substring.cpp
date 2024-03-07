//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    // private:
    // int f(int i,int j)
  public:
    string longestSubstring(string s, int n) {
        // code here
        // map<string,vector<int>> mp;
        
        // string ans = "";
        
        // int len = 0;
        
        // for(int i = 0;i<n;i++){
        //     string str = "";
        //     for(int j = i;j<n;j++){
        //         str += s[j];
                
        //         if(mp.find(str)!=mp.end()){
        //             for(int it : mp[str]){
        //                 if(str.length()>len && it<=i){
        //                     ans = str;
        //                     len = str.length();
        //                 }
        //             }
        //         }
                
        //         mp[str].push_back(i+str.length());
        //     }
        // }
        
        // return ans==""?"-1":ans;
        
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        
        int ind = 0;
        int maxLen = 0;
        
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                if(i+dp[i-1][j-1]<j && s[i-1]==s[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(dp[i][j]>maxLen){
                        maxLen = dp[i][j];
                        ind = max(i,ind);
                    }
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        
        string res = "";
        
        for(int i = ind-maxLen+1;i<=ind;i++){
            res = res + s[i-1];
        }
        
        if(res==""){
            return "-1";
        }
        else{
            return res;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends