#include <bits/stdc++.h>
using namespace std;
const int MOD=1000000007;

int main() {
	int n,m; cin >> n >> m;
	vector<int> adj[n]; 
	int e[n]; for (int i=0; i<n; i++) e[i]=0;
	for (int i=0; i<m; i++) {
		int a,b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		e[b]++;
	}
	vector<int> stk; 
	int t[n]; 
	for (int i=0; i<n; i++) {
		t[i]=0;
		if (!e[i]) stk.push_back(i);
	}
	t[0]=1;
	while (stk.size()) {
		int cn=stk.back();
		stk.pop_back();
		for (int i:adj[cn]) {
			t[i]+=t[cn];
			t[i]%=MOD;
			e[i]--;
			if (!e[i]) stk.push_back(i);
		}
	}
	cout << t[n-1];
	
}