//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& nums) {
        // Code here
        
        int n = nums.size();

        sort(nums.begin(),nums.end());

        unordered_map<int,int> mp;

        int maxi = 0, res = 0;

        for(int i = 0;i<n;i++){
            if(mp[nums[i]]==0){
                mp[nums[i]]++;
                maxi = max(maxi,nums[i]);
            }
            else{
                res += (maxi + 1 - nums[i]);
                mp[maxi+1]++;
                maxi = maxi + 1;
            }
            
        }

        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends