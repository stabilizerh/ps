#include <bits/stdc++.h>
using namespace std;
#define NUM ((int)5e3)
//Warning!!
int n;
vector <int> arr;

struct Segtree{
	int n;
	vector <int> segtree[NUM];
	Segtree(){}
	Segtree(int _n,vector<int> arr) : n(_n){
		init(arr);
	}
	void init(int s,int e,int node,vector<int> &arr){
		if(s==e) segtree[node].push_back(arr[s]);
		else{
			init(s,(s+e)/2,2*node,arr);
			init((s+e)/2+1,e,2*node+1,arr);
			merge(segtree[2*node],segtree[2*node+1],segtree[node]);
		}
	}
	void init(vector<int> &arr){
		init(0,n-1,1,arr);
	}

	void merge(vector<int> &a,vector<int> &b,vector<int> &r){
		int pos1= 0, pos2 = 0;
		while(pos1<a.size()||pos2<b.size()){
			if(pos1==a.size()) r.push_back(b[pos2++]);
			else if(pos2==b.size()) r.push_back(a[pos1++]);
			else{
				if(a[pos1]>b[pos2]) r.push_back(b[pos2++]);
				else r.push_back(a[pos1++]);
			}
		}
	}

	int upper(int s,int e,int snode,int enode,int node,int val){
		if(snode>e||enode<s) return 0;
		else if(s<=snode&&enode<=e) return upper_bound(segtree[node].begin(),segtree[node].end(),val)-segtree[node].begin();
		else return upper(s,e,snode,(snode+enode)/2,2*node,val)+upper(s,e,(snode+enode)/2+1,enode,2*node+1,val);
	}

	int upper(int s,int e,int val){
		return upper(s,e,0,n-1,1,val);
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
	int q;
	cin>>q;
	for(int u,v,w,i=0;i<q;i++){
		cin>>u>>v>>w;
		cout<<v-u+1-seg.upper(u-1,v-1,w)<<'\n';
	}
}
