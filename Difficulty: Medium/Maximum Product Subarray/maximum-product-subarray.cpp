//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &nums) {
        // Your Code Here
        if(nums.size()==1) return nums[0];

        long long pre = 1,suff = 1;
        int n = nums.size();
        long long res  = 0;
        for(int i = 0;i<n;i++){

            if(pre>INT_MAX || pre<INT_MIN){
                pre = 1;
            }
            if(suff>INT_MAX || suff<INT_MIN){
                suff = 1;
            }
            if(pre==0) pre = 1;
            if(suff==0) suff = 1;
            pre = pre*(long long)nums[i];
            suff = suff*nums[n-i-1];
            res = max(res,max(pre,suff));
        }

        return (int)res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends