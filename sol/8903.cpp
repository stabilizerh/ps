#include <bits/stdc++.h>
using namespace std;
int n,K,T;
vector <int> a[5];
int bits[1<<5];
int ans;
void init(){
	n=K=0;
	for(int i=0;i<32;i++){
		bits[i]=0;
	}
	for(int i=0;i<5;i++){
		a[i].clear();
	}
	ans = 0;
}

void input(){
	cin>>n>>K;
	for(int u,i=0;i<n;i++){
		for(int j=0;j<5;j++){
			cin>>u;
			a[j].push_back(u);
		}
	}
	for(int b=1;b<32;b++){
		vector <int>idx;
		for(int i=0;i<5;i++){
			if((b>>i)&1) idx.push_back(i);
		}
		for(int i=0;i<n;i++){
			int mx = 0;
			for(int j:idx) mx += a[j][i];
			bits[b] = max(bits[b],mx);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		input();
		switch(K){
			case 1:
				ans = bits[31];
				break;
			case 2:
				for(int i=0;i<5;i++){
					for(int j=0;j<5;j++){
						if(i==j) continue;
						int mx = 0;
						mx += bits[(1<<i)+(1<<j)];
						mx += bits[31-(1<<i)-(1<<j)];
						ans = max(ans,mx);
					}
				}
				for(int i=0;i<5;i++){
					int mx = 0;
					mx += bits[1<<i];
					mx += bits[31-(1<<i)];
					ans = max(ans,mx);
				}
				break;
			case 3:
				for(int i=0;i<5;i++){
					for(int j=0;j<5;j++){
						if(i==j) continue;
						for(int k=0;k<5;k++){
							if(k==i||k==j) continue;
							for(int w=0;w<5;w++){
								if(w==i||w==j||w==k) continue;
								int mx = 0;
								mx += bits[(1<<i)+(1<<j)];
								mx += bits[(1<<k)+(1<<w)];
								mx += bits[31-(1<<i)-(1<<j)-(1<<k)-(1<<w)];
								ans = max(ans,mx);
							}
						}
					}
				}
				for(int i=0;i<5;i++){
					for(int j=0;j<5;j++){
						if(i==j) continue;
						int mx = 0;
						mx += bits[(1<<i)];
						mx += bits[(1<<j)];
						mx += bits[31-(1<<i)-(1<<j)];
						ans = max(ans,mx);
					}
				}
				break;
			case 4:
				for(int i=0;i<5;i++){
					for(int j=0;j<5;j++){
						if(i==j) continue;
						int mx = 0;
						mx += bits[(1<<i)+(1<<j)];
						for(int k=0;k<5;k++){
							if(k==i||k==j) continue;
							mx+=bits[1<<k];
						}
						ans = max(ans,mx);
					}
				}
				break;
			default:
				for(int i=0;i<5;i++){
					ans+=bits[1<<i];
				}
		}
		cout<<ans<<'\n';
		init();
	}
}
