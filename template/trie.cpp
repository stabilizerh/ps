#include <bits/stdc++.h>
using namespace std;
#define MAX 10

char word[20];
int t,n;

struct Trie{
	Trie* go[MAX];
	bool cnt;
	bool exist;
	
	Trie(){
		fill(go,go+MAX,nullptr);
		cnt = false;
		exist = false;
	}
	~Trie(){
		for(int i=0;i<MAX;i++){
			if(go[i]) delete go[i];
		}
	}

	void insert(const char* key){
		if(!(*key)) cnt = true;
		else{
			int next = *key-'0';
			if(!go[next]) go[next] = new Trie;
			exist = true;
			go[next]->insert(key+1);
		}
	}
};

bool dfs(Trie* node){
	bool rtn = true;
	if(node->cnt&&node->exist) return false;
	for(int i=0;i<MAX;i++){
		if(node->go[i]){
			if(!dfs(node->go[i])){
				rtn = false;
				break;
			}
		}
	}
	return rtn;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	for(;t--;){
		Trie* root = new Trie;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>word;
			root->insert(word);
		}
		cout<<(dfs(root)?"YES":"NO")<<'\n';
	}
}

