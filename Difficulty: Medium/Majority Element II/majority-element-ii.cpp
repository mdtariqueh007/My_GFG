//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int cnt1 = 0,cnt2 = 0;
        int ele1 = INT_MIN,ele2  =INT_MIN;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(cnt1==0 && ele2!=nums[i]){
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2==0 && ele1!=nums[i]){
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(ele1==nums[i]){
                cnt1++;
            }
            else if(ele2==nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;
        cnt1 = 0;cnt2 = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
        }

        if(cnt1>n/3){
            ans.push_back(ele1);
        }
        if(cnt2>n/3){
            ans.push_back(ele2);
        }
        
        if(ans.empty()){
            return ans;
        }
        
        sort(ans.begin(), ans.end());

        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends