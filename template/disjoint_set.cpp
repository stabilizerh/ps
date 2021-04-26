#include <bits/stdc++.h>
#define INF ((ll)(2e9))
#define X first
#define Y second

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using ppi = pair<int,pii>;
int n,m,T;
ll arr[505][505];
void init(){
}

struct dset{
    vector<int> parent, rank;
    dset(int n) : parent(n), rank(n,1) {
        for (int i=0; i < n; ++i)
            parent[i] = i;
    }
    
    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge (int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        if (rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v]) ++rank[v];
    }
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	for(int t=1;t<=T;t++){
		ll ans = 0;
		ll sum = 0;
		vector<int> E[505];
		vector<ppi> v;
		cin>>n;
		dset vtx(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
				v.push_back(ppi(arr[i][j],pii(i,j)));
				sum += arr[i][j];
			}
		}
		for(int u,i=0;i<2*n;i++){
			cin>>u;
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		for(ppi p : v){
			int x = p.Y.X;
			int y = p.Y.Y;
			if(E[x].empty()){
				E[x].push_back(y);
				ans += p.X;
			}
			else{
				if(vtx.find(E[x].back())==vtx.find(y)) continue;
				vtx.merge(E[x].back(),y);
				ans += p.X;
			}
		}
		cout<<"Case #"<<t<<": "<<sum-ans<<'\n';
	}
}
