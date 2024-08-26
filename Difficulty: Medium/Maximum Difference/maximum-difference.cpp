//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        
        int n = arr.size();
        
        stack<int> st;
        
        vector<int> leftSmaller(n);
        vector<int> rightSmaller(n);
        
        for(int i = 0;i<n;i++){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            
            leftSmaller[i] = st.empty()?0:st.top();
            
            st.push(arr[i]);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i = n - 1;i>=0;i--){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            
            rightSmaller[i] = st.empty()?0:st.top();
            
            st.push(arr[i]);
        }
        
        int maxDiff = 0;
        
        for(int i = 0;i<n;i++){
            maxDiff = max(maxDiff,abs(rightSmaller[i] - leftSmaller[i]));
        }
        
        return maxDiff;
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

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends