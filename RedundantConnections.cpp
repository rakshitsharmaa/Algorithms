class Solution {
public:
    int find(int node,vector<int>& parent){
        if(parent[node]==node)
            return node;
        
        return find(parent[node],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++)
            parent[i]=i;
        
        for(auto edge:edges){
            int s1=find(edge[0],parent);
            int s2=find(edge[1],parent);
           // int s1=0,s2=0;
            if(s1==s2)
                return {edge[0],edge[1]};
           parent[s1]=s2;
        }
       
        return {};
    }
};
