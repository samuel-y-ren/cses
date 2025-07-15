#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n,m,q; cin >> n >> m >> q;
	ll md[n][n]; for (int i=0; i<n; i++) for (int j=0; j<n; j++) md[i][j]=1000000000000000000;
	for (int i=0; i<n; i++) md[i][i]=0;
	for (int i=0; i<m; i++) {
		int a,b,c; cin >> a >> b >> c;
		a--; b--;
		md[a][b] = md[b][a] = min(md[a][b], (ll)c);
	}
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) for (int k=0; k<n; k++) md[j][k] = min(md[j][k],md[j][i]+md[i][k]);
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (md[i][j]==1000000000000000000) md[i][j]=-1;
	while (q--) {
		int a,b; cin >> a >> b;
		cout << md[a-1][b-1] << '\n';
	}
}