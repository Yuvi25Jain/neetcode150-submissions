class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool isValid(int i , int j , int n , int m){
        return !(i<0 || i>=n || j<0 || j>=m);
    }

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& vis){
        vis[i][j] = 1;
        int n = heights.size(), m = heights[0].size();

        for(int k=0; k<4; k++){
            int row = i + x[k];
            int col = j + y[k];
            if(isValid(row,col,n,m) && !vis[row][col] && heights[row][col] >= heights[i][j]){
                dfs(row,col,heights,vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> pac(n, vector<int>(m,0));
        vector<vector<int>> atl(n, vector<int>(m,0));

        // DFS from Pacific edges
        for(int i=0; i<n; i++) dfs(i,0,heights,pac);      // left edge
        for(int j=0; j<m; j++) dfs(0,j,heights,pac);      // top edge

        // DFS from Atlantic edges
        for(int i=0; i<n; i++) dfs(i,m-1,heights,atl);    // right edge
        for(int j=0; j<m; j++) dfs(n-1,j,heights,atl);    // bottom edge

        // Collect intersection
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
