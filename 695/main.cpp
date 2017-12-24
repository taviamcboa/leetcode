class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //each source bfs
        int m = grid.size(); 
        int n = grid[0].size(); 
        int ans = 0; 
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){   
                if (grid[i][j] == 1) {
                    //ans = max(ans, bfs(grid, i, j)); 
                    ans = max(ans, dfs(grid, i, j)); 
                }
            }      
        }
        return ans;  
    }

    // iterative version (stack)
    int maxAreaOfIsland_dfsIterative(vector<vector<int>>& grid) {

        vector<int> dir({-1,0,1,0,-1});
        int ans = 0;
        int m = grid.size(), n = grid[0].size();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    int area = 0;
                    stack<pair<int, int>> stack; 
                    stack.push(make_pair(r, c));
                    grid[r][c] = 2; // mark as visited

                    while (!stack.empty()) {
                        pair<int, int> current = stack.top();
                        stack.pop(); 
                        int currentX = current.first; 
                        int currentY = current.second;
                        area++;
                        for (int k = 0; k < 4; k++) {
                            int nr = r + dir[k];
                            int nc = c + dir[k + 1];
                            if (0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] == 1) {
                                stack.push(make_pair(nr, nc));
                                 grid[nr][nc] = 2;
                            }
                        }
                    }
                    ans = Math.max(ans, area);
                }
            }
        }
        return ans;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size(), area = 1;
        grid[row][col] = 2;
        vector<int> dir({-1,0,1,0,-1});
        for (int i = 0; i < 4; i++) {
            int r = row + dir[i], c = col + dir[i+1];
            // unvisited
            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) 
                area += dfs(grid, r, c);
        }
        return area;
    }


    // source position: i, j
    int bfs(vector<vector<int>>& grid, int i, int j){
        int m = grid.size(); 
        int n = grid[0].size(); 
        
        
        queue<pair<int,int>> bfs;
        bfs.push(make_pair(i, j));
        
        //mark as visited
        grid[i][j] = 2;
        vector<int> dir({-1,0,1,0,-1});
        
        int area = 1; 
        
        while(!bfs.empty()){
            int currentX = bfs.front().first;
            int currentY = bfs.front().second;
            bfs.pop();
            
            // push four neighboring 
            for (int i = 0; i < 4; i++) {
                
                int r = currentX + dir[i];
                int c = currentY + dir[i+1];
                
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                    grid[r][c] = 2;
                    area++;
                    bfs.push({r,c});
                }
            }
            
        }
     
        return area;    
    }
};