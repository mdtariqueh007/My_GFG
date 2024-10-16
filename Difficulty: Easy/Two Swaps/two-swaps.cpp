//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        
        int cnt = 0;
        
        for(int i = 1;i<arr.size();i++){
            if(arr[i]<arr[i-1]){
                cnt++;
            }
            
        }
        
        if(arr.size()>1 && arr[0]>arr[1]){
            cnt++;
        }
        
      
        return (cnt<=4 && cnt%2==0);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends