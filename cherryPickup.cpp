class Solution {
    int dp[52][52][52];
    int solve(int i1,int j1,int i2,vector<vector<int>>& grid,int n){
        if(i1==n-1 and j1==n-1)
            return grid[n-1][n-1];
        int j2=i1+j1-i2;
          if(i1>=n ||  i2>=n || j1>=n || j2>=n || grid[i1][j1]==-1 ||grid[i2][j2]==-1)
            return -1e3;
        
        if(dp[i1][j1][i2]!=-1)
            return dp[i1][j1][i2];
        
        int PickedCherries=0;
        
        if(j1==j2 && i1==i2)
        PickedCherries+=grid[i1][j1];    
        else
            PickedCherries+=grid[i1][j1]+grid[i2][j2];
        
        
        
        return dp[i1][j1][i2]=PickedCherries+max({solve(i1+1,j1,i2+1,grid,n),solve(i1,j1+1,i2+1,grid,n),
                    solve(i1+1,j1,i2,grid,n),solve(i1,j1+1,i2,grid,n)});
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int ans=solve(0,0,0,grid,n);
        return ans>0?ans:0;
    }
};
