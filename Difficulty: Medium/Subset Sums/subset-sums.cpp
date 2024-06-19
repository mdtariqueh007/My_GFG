//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    void helper(int ind,vector<int> &arr,vector<int>&ans,int&sum){
        
        ans.push_back(sum);
            
        
        
        for(int i = ind;i<arr.size();i++){
            sum += arr[i];
            helper(i+1,arr,ans,sum);
            sum -= arr[i];
        }
        
        
    }
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> ans;
        
        int sum = 0;
        
        helper(0,arr,ans,sum);
        
        return ans;
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
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends