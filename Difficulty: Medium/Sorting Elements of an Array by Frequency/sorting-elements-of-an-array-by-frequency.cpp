//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        
        unordered_map<int,int> mp;
        
        for(int x : arr){
            mp[x]++;
        }
        
        vector<pair<int,int>> temp;
        
        for(auto it : mp){
            temp.push_back({it.first,it.second});
        }
        
        sort(temp.begin(),temp.end(),[&](pair<int,int> a,pair<int,int> b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            else{
                return a.second>b.second;
            }
        });
        
        vector<int> ans;
        
        for(auto it : temp){
            while(it.second>0){
                ans.push_back(it.first);
                it.second--;
            }
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

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends