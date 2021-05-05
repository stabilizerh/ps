#include <bits/stdc++.h>
using namespace std;
#define MAX 26

char word[82];
int t,n;
int ans;

struct Trie{
	Trie* go[MAX];
	bool fin;
	int cnt;
	
	Trie(){
		fill(go,go+MAX,nullptr);
		fin = false;
		cnt = 0;
	}
	~Trie(){
		for(int i=0;i<MAX;i++){
			if(go[i]) delete go[i];
		}
	}

	void insert(const char* key){
		if((*key)){
			cnt++;
			int next = *key-'a';
			if(!go[next]) go[next] = new Trie;
			go[next]->insert(key+1);
		}
		else fin=true;
	}
};

void dfs(Trie* node){
	int deg = 0;
	if(node->fin) deg++;
	for(int i=0;i<MAX;i++){
		if(node->go[i]){
			dfs(node->go[i]);
			deg++;
		}
	}
	if(deg<=1) return;
	ans+=node->cnt;
}

int main(){
	cout<<fixed;
	cout.precision(2);
	while(1){
		Trie* root = new Trie;
		cin>>n;
		if(cin.eof()) break;
		ans = 0;
		for(int i=0;i<n;i++){
			cin>>word;
			root->insert(word);
		}
		ans+=root->cnt;
		for(int i=0;i<MAX;i++){
			if(root->go[i]){
				dfs(root->go[i]);
			}
		}
		cout<<ans/(double)n<<'\n';
		delete root;
	}
}
