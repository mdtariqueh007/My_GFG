//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
    private:
    
    void merge(vector<pair<int,int>>&nums,int low,int mid,int high,vector<int>&cnt){
        vector<pair<int,int>> temp(high-low+1);
        int left = low;
        int right = mid+1;
        int k = 0;


        while(left<=mid && right<=high){
            if(nums[left].first<=nums[right].first){
                temp[k++] = nums[right];
                right++;
            }
            else{
                temp[k++] = nums[left];
                cnt[nums[left].second] += (high-right+1);
                left++;
            }
        }

        while(left<=mid){
            temp[k++] = nums[left];
            left++;
        }
        while(right<=high){
            temp[k++] = nums[right];
            right++;
        }

        for(int i = low;i<=high;i++){
            nums[i] = temp[i-low];
        }

        // return cnt;

    }
    void mergeSort(vector<pair<int,int>>&nums,int low,int high,vector<int>&count){
        if(low>=high) return;
        int mid = low + (high-low)/2;
        mergeSort(nums,low,mid,count);
        mergeSort(nums,mid+1,high,count);
        merge(nums,low,mid,high,count);

        // return cnt;
    }
  public:
    vector<int> constructLowerArray(vector<int> &nums) {
        // code here
        vector<pair<int,int>> numsPair;
        for(int  i = 0;i<nums.size();i++){
            numsPair.push_back({nums[i],i});
        }
        vector<int> cnt(nums.size(),0);
        mergeSort(numsPair,0,nums.size()-1,cnt);
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends