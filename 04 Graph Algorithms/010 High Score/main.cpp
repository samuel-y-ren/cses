#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n,m; cin >> n >> m;
	ll ms[n+1]; for (int i=0; i<=n; i++) ms[i]=-1000000000000000000;
	ms[1]=0;
	int a[m],b[m],x[m];
	vector<int> ra[n+1];
	for (int i=0; i<m; i++) {
		cin >> a[i] >> b[i] >> x[i];
		ra[b[i]].push_back(a[i]);
	}
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) ms[b[j]] = max(ms[b[j]],ms[a[j]]+x[j]);
	bool v[n+1]; for (int i=0; i<=n; i++) v[i]=0;
	vector<int> stk={n};
	while (stk.size()) {
		int nd=stk.back();
		stk.pop_back();
		if (v[nd]) continue;
		v[nd]=1;
		for (int i : ra[nd]) stk.push_back(i);
	}
	for (int i=0; i<m; i++) if (v[b[i]] && ms[b[i]]<ms[a[i]]+x[i] && ms[b[i]]>-500000000000000000) {
		cout << "-1\n";
		return 0;
	}
	cout << ms[n];
}