#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q; cin >> n >> q;
	int d[n+1][32];
	for (int i=1; i<=n; i++) cin >> d[i][0];
	for (int j=1; j<32; j++) for (int i=1; i<=n; i++) d[i][j]=d[d[i][j-1]][j-1];
	while (q--) {
		int x,k; cin >> x >> k;
		for (int i=0; i<32; i++) if (k&(1<<i)) x=d[x][i];
		cout << x << '\n';
	}
}