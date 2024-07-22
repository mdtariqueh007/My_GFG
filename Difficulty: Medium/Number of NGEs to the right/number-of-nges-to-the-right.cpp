//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    void merge(int low,int mid,int high,vector<pair<int,int>>&arr,vector<int>&cnt){
        vector<pair<int,int>> temp;
        
        int left = low;
        int right = mid + 1;
        
        while(left<=mid && right<=high){
            if(arr[left].first<arr[right].first){
                cnt[arr[left].second] += (high - right + 1);
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = low;i<=high;i++){
            arr[i] = temp[i-low];
        }
    }
    void mergeSort(int low,int high,vector<pair<int,int>>&arr,vector<int>&cnt){
        if(low>=high){
            return;
        }
        
        int mid = low + (high - low)/2;
        
        mergeSort(low,mid,arr,cnt);
        mergeSort(mid+1,high,arr,cnt);
        
        merge(low,mid,high,arr,cnt);
    }
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        
        
        vector<int> cnt(n,0);
        vector<pair<int,int>> v;
        
        for(int i  = 0;i<n;i++){
            v.push_back({arr[i],i});
        }
        
        mergeSort(0,n-1,v,cnt);
        
        vector<int> ans;
        
        for(int i : indices){
            ans.push_back(cnt[i]);
        }
        
        
        return ans;
        
       
    }

};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> v1(n);
       for(int i = 0;i<n;i++) cin >> v1[i];
        int q; cin >> q;
        vector<int> v2(q);
        for(int i = 0;i<q;i++) cin >> v2[i];

        Solution obj;
        vector<int> ans = obj.count_NGE(n,v1,q,v2);

        for(int i = 0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends