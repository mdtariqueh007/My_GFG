//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string str){
        // code here 
         int n = str.size();
        
        int dp[n][n];
        
        memset(dp,0,sizeof(dp));
        
        for(int gap = 1;gap<n;gap++){
            int low = 0;
            int high = gap;
            while(high<n){
                if(str[low]==str[high]){
                    dp[low][high] = dp[low+1][high-1];
                }
                else{
                    dp[low][high] = 1 + min(dp[low][high-1],dp[low+1][high]);
                }
                
                low++;
                high++;
            }
        }
        
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends