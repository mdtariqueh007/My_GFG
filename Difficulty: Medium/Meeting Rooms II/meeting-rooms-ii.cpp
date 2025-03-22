//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        
        int maxEnd = *max_element(end.begin(), end.end());
        
        vector<int> line(maxEnd+1,0);
        
        for(int i = 0;i<start.size();i++){
            line[start[i]]++;
            line[end[i]]--;
        }
        
        int maxi = 0;
        
        for(int i = 1;i<=maxEnd;i++){
            line[i] += line[i-1];
            
            maxi = max(maxi, line[i]);
        }
        
        return maxi;
    }
};



//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.minMeetingRooms(arr, brr);
        cout << res << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends