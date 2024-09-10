//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        
        long long cost = 0;
        
        long long n = arr.size();
        
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        
        for(long long i = 0;i<n;i++){
            pq.push(arr[i]);
        }
        
        while(pq.size()>=2){
            
            long long val1 = pq.top();
            pq.pop();
            long long val2 = pq.top();
            pq.pop();
            
            cost += (val1+val2);
            
            pq.push(val1+val2);
            
        }
        
        return cost;
        
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends