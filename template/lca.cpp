#include <bits/stdc++.h>
#define NUM 100005
using namespace std;

vector <int> E[NUM];
int depth[NUM];
bool vis[NUM];
vector <int> lcabin[NUM];
int N;

void dfs(int i){
    vis[i]=true;
    int node,d=0;
    for(int t=1;t<=depth[i];t*=2,d++)
    if(d){
        node=lcabin[i][0];
    }
    for(int t=0;t<d-1;t++){
        node=lcabin[node][t];
        lcabin[i].push_back(node);
    }
    for(int x:E[i]){
        if(!vis[x]){
            depth[x]=depth[i]+1;
            lcabin[x].push_back(i);
            dfs(x);
        }
    }
}

int anc(int i,int k){//kth ancestor of i
    if(depth[i]<k) return 0;
    int l=log2(k);
    for(;l>=0;l--){
        if(k>=(1<<l)){
            i=lcabin[i][l];k-=(1<<l);
        }
    }
    return i;
}

int lca(int u,int v){
    if(depth[u]<depth[v]) swap(u,v);
    int d=depth[u]-depth[v];
    if(d!=0){
        int l=log2(d);
        for(;l>=0;l--){
            if(d>=(1<<l)){
                u=lcabin[u][l];d-=(1<<l);
            }
        }
    }
    if(u!=v){
        int d=log2(depth[u]-1)+1;
        for(;d>=0;d--){
            if(depth[u]>=(1<<d)&&lcabin[u][d]!=lcabin[v][d]){
                u=lcabin[u][d],v=lcabin[v][d];
            }
        }
        u=lcabin[u][0];v=lcabin[v][0];//u=v is lca node
    }
    return u;
}
int dist(int u,int v){
    int w = lca(u,v);
    return depth[u]+depth[v]-2*depth[w];
}
int path(int u,int v,int k){//k+1th element during path u->v
    int l = lca(u,v);
    if(k<=depth[u]-depth[l]) return anc(u,k);
    else return anc(v,depth[u]+depth[v]-2*depth[l]-k);
}
void input(){
    cin>>N;
    for(int i=N-1,u,v;i--;){
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    input();
    dfs(1);
}
