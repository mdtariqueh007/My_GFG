//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int>&arr,int k){
        
        int n = arr.size();
        // code here
        sort(arr.begin(),arr.end());
        
        int ans = arr[n-1] - arr[0];
        
        for(int i = 1;i<n;i++){
            
            if (arr[i] - k < 0)
            continue;
            
            int maxi = max(arr[i-1]+k,arr[n-1]-k);
            int mini = min(arr[i]-k,arr[0]+k);
            
            ans = min(ans,maxi-mini);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends