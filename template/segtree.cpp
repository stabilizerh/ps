#include <bits/stdc++.h>
using namespace std;
#define INF (2e9)
#define NUM 100

int n;
vector <int> arr;
vector <int> segtree(NUM*2);

int init_tree(int s,int e,int node){
    if(s==e) return segtree[node]=arr[s];
    else return segtree[node]=min(init_tree(s,(s+e)/2,2*node),init_tree((s+e)/2+1,e,2*node+1));
}
void init(){
	init_tree(0,n-1,1);
}

int min_tree(int s,int e,int snode,int enode,int node){
    if(snode>e||enode<s) return INF;
    else if(s<=snode&&enode<=e) return segtree[node];
    else return min(min_tree(s,e,snode,(snode+enode)/2,2*node),min_tree(s,e,(snode+enode)/2+1,enode,2*node+1));
}
int minimum(int s,int e){
    return min_tree(s,e,0,n-1,1);
}

int update_tree(int pos,int snode,int enode, int node,int val){
    if(snode>pos||enode<pos) return segtree[node];
	if(snode==enode){
		return segtree[node] = val;
	}
    if(snode!=enode){
        return segtree[node] = min(update_tree(pos,snode,(snode+enode)/2,2*node,val),update_tree(pos,(snode+enode)/2+1,enode,2*node+1,val));
    }
}
void update(int pos,int val){
    update_tree(pos,0,n-1,1,val);
}

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
	init();
}
