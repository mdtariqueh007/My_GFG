//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    #define pii pair<int,pair<int,int>>
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        
        int m = rows;
        int n = columns;
        
        priority_queue<pii,vector<pii>,greater<>> pq;
        
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        
        pq.push({0,{0,0}});
        
        dist[0][0] = 0;
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        while(!pq.empty()){
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            
            pq.pop();
            
            if(row==m-1 && col==n-1){
                return diff;
            }
            
            for(int i = 0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n){
                    int newEffort = max(diff,abs(heights[nrow][ncol] - heights[row][col]));
                    
                    if(newEffort<dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }
        
        
        return 0;
        
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends