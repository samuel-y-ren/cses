#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m; cin >> n >> m;
	vector<int> po[n+1];
	int t[n+1]; for (int i=1; i<=n; i++) t[i]=0;
	for (int i=0; i<m; i++) {
		int a,b; cin >> a >> b;
		po[a].push_back(b);
		t[b]++;
	}
	vector<int> stk;
	vector<int> ord;
	for (int i=1; i<=n; i++) if (!t[i]) stk.push_back(i);
	while (stk.size()) {
		int cn=stk.back();
		ord.push_back(cn);
		stk.pop_back();
		for (int i : po[cn]) {
			t[i]--; if (!t[i]) stk.push_back(i);
		}
	}
	if (ord.size()==n) {
		for (int i : ord) cout << i << ' ';
	}
	else {
		cout << "IMPOSSIBLE";
	}
}