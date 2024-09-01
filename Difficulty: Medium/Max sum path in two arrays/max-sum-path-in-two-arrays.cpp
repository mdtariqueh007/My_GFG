//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        
        int n1 = arr1.size();
        int n2 = arr2.size();
        
        int totalSum = 0, sum1 = 0, sum2 = 0;
        
        int i = 0, j = 0;
        
        while(i<n1 || j<n2){
            
            int a = i<n1?arr1[i]:INT_MAX;
            int b = j<n2?arr2[j]:INT_MAX;
            
            if(a<b){
                sum1 += a;
                i++;
            }
            else if(b<a){
                sum2 += b;
                j++;
            }
            else{
                totalSum += max(sum1,sum2) + a;
                
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
            
            
            
        }
        
        return totalSum + max(sum1,sum2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends