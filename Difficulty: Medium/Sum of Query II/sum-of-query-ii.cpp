//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        // code here
        vector<int> prefix(n,0);
        prefix[0] = arr[0];
        
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + arr[i];
        }
        
        vector<int> ans;
        
        for(int i = 0;i<2*q;i+=2){
            int l = queries[i];
            int r = queries[i+1];
            l--;
            r--;
            
            if(l==0){
                ans.push_back(prefix[r]);
            }
            else{
                ans.push_back(prefix[r] - prefix[l-1]);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];
        
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends