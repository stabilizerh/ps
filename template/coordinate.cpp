//Coordinate Compression
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int,int> pii;
vector <int> a;
vector <int> idx;

void coordinate(vector<int> &a,vector<int> &idx){
	vector<pii> p;
	int len = a.size();
	for(int i=0;i<len;i++){
	   p.push_back(pii(a[i],i));
	}
	sort(p.begin(),p.end());
	idx.resize(len);
	for(int i=0;i<len;i++){
	   if(i!=0&&p[i].X==p[i-1].X) idx[p[i].Y]=idx[p[i-1].Y];
	   else idx[p[i].Y]=i;
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int input[]={1,4,2,2,10,7,10};
	for(int x:input){
		a.push_back(x);
	}
	coordinate(a,idx);
	for(int x:idx){
		cout<<x<<' ';
	}
}

