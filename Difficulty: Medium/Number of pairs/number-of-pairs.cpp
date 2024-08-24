//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        int m = arr.size();
        int n = brr.size();
        vector<float> x(m), y(n);
        
        for(int i = 0;i<m;i++){
            x[i] = (log2(arr[i]))/arr[i];
        }
        for(int i = 0;i<n;i++){
            y[i] = (log2(brr[i]))/brr[i];
        }
        
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        
        long long ans = 0;
        
        for(int i = 0;i<n;i++){
            int ind = upper_bound(x.begin(),x.end(),y[i]) - x.begin();
            
            ans += m - ind;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends