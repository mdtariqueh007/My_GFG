//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<pair<int,pair<int,int>>> temp;
        
        for(int i = 0;i<n;i++){
            temp.push_back({arr[i]-brr[i],{arr[i],brr[i]}});
        }
        
        sort(temp.begin(),temp.end(),[&](pair<int,pair<int,int>>a , pair<int,pair<int,int>>b){
            return abs(a.first)>abs(b.first);
        });
        
        long long res = 0;
        
        for(int i = 0;i<n;i++){
            if(x==0 && y==0){
                break;
            }
            
            else if(x==0){
                res += temp[i].second.second;
                y--;
            }
            else if(y==0){
                res += temp[i].second.first;
                x--;
            }
            else{
                if(temp[i].first>=0){
                    res += temp[i].second.first;
                    x--;
                }
                else{
                    res += temp[i].second.second;
                    y--;
                }
            }
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends