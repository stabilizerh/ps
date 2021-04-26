#include <bits/stdc++.h>
using namespace std;
#define INF (2'000'000'000)
#define X first
#define Y second
typedef pair<int,int> pii;
int n,e,start;
vector <pii> E[20005];
vector <int> dp(20005,INF);

void input(){
	cin>>n>>e;
	cin>>start;
	for(int u,v,w,i=0;i<e;i++){
		cin>>u>>v>>w;
		E[u].push_back(pii(v,w));
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	input();
	priority_queue<pii> q;
	q.push(pii(0,start));
	dp[start] = 0;
	while(!q.empty()){
		int dist = q.top().X;
		int i = q.top().Y;
		q.pop();
		if(dist>dp[i]) continue;
		for(pii x:E[i]){
			if(dp[x.X]>dp[i]+x.Y){
				dp[x.X] = dp[i]+x.Y;
				q.push(pii(-dp[x.X],x.X));
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dp[i]==INF)
			cout<<"INF"<<'\n';
		else
			cout<<dp[i]<<'\n';
	}
}

