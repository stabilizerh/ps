#include <bits/stdc++.h>
using namespace std;
#define NUM 205

#define nodify(x) ((x)>0?2*(x):2*(-x)-1)
#define revs(x) ((x)%2?(x)+1:(x)-1)

int N,n,m,cnt,scc_n;
vector <int> E[NUM],q,scc_v[NUM];
int vis[NUM],scc[NUM],ansv[NUM];
bool fin[NUM];

int dfs(int node){
	vis[node] = ++cnt;
	q.push_back(node);
	int r = vis[node];
	for(int x:E[node]){
		if(!vis[x]) r = min(r,dfs(x));
		else if(!fin[x]) r = min(r,vis[x]);
	}
	if(r==vis[node]){
		while(1){
			scc_v[scc_n].push_back(q.back());
			scc[q.back()] = scc_n;
			fin[q.back()] = true;
			if(q.back()==node){
				q.pop_back();
				break;
			}
			q.pop_back();
		}
		scc_n++;
	}
	return r;
}

void input(){
	cin>>N>>m;
	n = 2*N;
	for(int u,v,i=0;i<m;i++){
		cin>>u>>v;
		u = nodify(u);
		v = nodify(v);
		E[revs(u)].push_back(v);
		E[revs(v)].push_back(u);
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	input();
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i);
	}
	int ans = 1;
	for(int i=1;i<=N;i++){
		if(scc[2*i-1]==scc[2*i]) ans = 0;
	}
	cout<<ans<<'\n';
	if(!ans) return 0;
	for(int i=scc_n;i--;){
		for(int x:scc_v[i]){
			if(!ansv[(x-1)/2]) ansv[(x-1)/2] = x%2?2:1;
		}
	}
	for(int i=0;i<N;i++){
		cout<<ansv[i]-1<<' ';
	}
}
