//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        const int mod = 1e9 + 7;
        int cntPos = 0, cntNeg = 0;
        
        for(int x : arr){
            if(x>0){
                cntPos++;
            }
            else if(x<0){
                cntNeg--;
            }
        }
        
        if(cntPos==0 && cntNeg==0){
            return 0;
        }
        
        
        
        if(cntNeg%2==0){
            long long ans = 1;
            
            for(long long x : arr){
                if(x!=0){
                    ans = (ans%mod * x%mod)%mod;
                }
            }
            
            return ans;
        }
        else{
            vector<int> neg;
            
            
            long long int ans = 1;
            
            for(long long x : arr){
                if(x<0){
                    neg.push_back(x);
                }
                else if(x>0){
                    ans = (ans%mod * x%mod)%mod;
                }
            }
            
            sort(neg.begin(),neg.end());
            
            if(neg.size()==arr.size() && arr.size()==1){
                return neg[0];
            }
            
            if(cntPos==0 && neg.size()==1){
                return 0;
            }
            
            for(int i = 0;i<neg.size()-1;i++){
                ans = (ans%mod * neg[i]%mod)%mod;
            }
            
            return ans;
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends