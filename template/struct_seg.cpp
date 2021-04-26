#include <bits/stdc++.h>
using namespace std;
#define INF (2e9)
int n;
vector <int> arr;

struct Segtree{
	int n;
	vector <int> segtree;
	Segtree(){}
	Segtree(int _n) : n(_n),segtree(1<<(int)(ceil(log2(_n)+1)),INF){}
	Segtree(int _n,vector<int> arr) : n(_n),segtree(1<<(int)(ceil(log2(_n)+1)),INF){
		init(arr);
	}
	int init(int s,int e,int node,vector<int> &arr){
		if(s==e) return segtree[node]=arr[s];
		else return segtree[node]=min(init(s,(s+e)/2,2*node,arr),init((s+e)/2+1,e,2*node+1,arr));
	}
	void init(vector<int> &arr){
		init(0,n-1,1,arr);
	}

	int minimum(int s,int e,int snode,int enode,int node){
		if(snode>e||enode<s) return INF;
		else if(s<=snode&&enode<=e) return segtree[node];
		else return min(minimum(s,e,snode,(snode+enode)/2,2*node),minimum(s,e,(snode+enode)/2+1,enode,2*node+1));
	}
	int minimum(int s,int e){
		return minimum(s,e,0,n-1,1);
	}

	int update(int pos,int snode,int enode, int node,int val){
		if(snode>pos||enode<pos) return segtree[node];
		if(snode==enode){
			return segtree[node] = val;
		}
		if(snode!=enode){
			return segtree[node] = min(update(pos,snode,(snode+enode)/2,2*node,val),update(pos,(snode+enode)/2+1,enode,2*node+1,val));
		}
	}
	void update(int pos,int val){
		update(pos,0,n-1,1,val);
	}
};

void input(){
	cin>>n;
	for(int u,i=0;i<n;i++){
		cin>>u;
		arr.push_back(u);
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	input();
	Segtree seg(n,arr);
}
