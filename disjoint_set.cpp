class Disjoint_Set{
    vector<int> rank,parent,size;
public:
    Disjoint_Set(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);

        for(int i=0;i<=n;i++) parent[i] = i;
    }


    int ult_parent(int node){
        if(parent[node] == node) return node;
        return parent[node] = ult_parent(parent[node]);
    }


    void union_by_rank(int u , int v){
        int ult_u = ult_parent(u);
        int ult_v = ult_parent(v);

        if(ult_u == ult_v) return;

        if(rank[ult_u]>rank[ult_v]){
            parent[ult_v] = ult_u; 
        }
        else if(rank[ult_v]>rank[ult_u]){
            parent[ult_u] = ult_v;
        }
        else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
        
    }
   
   
    void union_by_size(int u , int v){
        int ult_u = ult_parent(u);
        int ult_v = ult_parent(v);

        if(ult_u == ult_v) return;

        if(size[ult_u]>size[ult_v]){
            parent[ult_v] = ult_u; 
            size[ult_u] +=size[ult_v];
        }
        else{
            parent[ult_u] = ult_v; 
            size[ult_v] +=size[ult_u];
        }
    }
};