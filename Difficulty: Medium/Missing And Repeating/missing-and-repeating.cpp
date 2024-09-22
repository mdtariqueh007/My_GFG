//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
         int x = 0;
        
        for(int i = 1;i<=n;i++){
            x = x^arr[i-1];
            x = x^i;
        }
        
        int diff = x&(~(x-1));
        
        int zero = 0, one = 0;
        
        for(int i = 1;i<=n;i++){
            if((arr[i-1]&diff)==0){
                zero = zero^arr[i-1];
            }
            else{
                one = one^arr[i-1];
            }
            
            if((i&diff)!=0){
                one = one^i;
            }
            else{
                zero = zero^i;
            }
        }
        
        int cnt = 0;
        
        for(int i = 0;i<n;i++){
            if(arr[i]==zero){
                cnt++;
            }
        }
        
        if(cnt==2){
            return  {zero,one};
        }
        else{
            return {one,zero};
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends