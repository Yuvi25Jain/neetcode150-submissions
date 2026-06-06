class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool isValid(int i , int j , int n , int m){
        return !(i<0 || i>=n || j<0 || j>=m);
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;

        // Step 1: push all treasure cells (0) into queue
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        // Step 2: BFS from all treasures simultaneously
        while(q.size()){   // same as while(!q.empty())
            auto [i,j] = q.front();
            q.pop();

            for(int k=0; k<4; k++){
                int row = i + x[k];
                int col = j + y[k];

                if(isValid(row,col,n,m) && grid[row][col] == 2147483647){
                    grid[row][col] = grid[i][j] + 1;  // update distance
                    q.push({row,col});                // push updated cell
                }
            }
        }
    }
};
