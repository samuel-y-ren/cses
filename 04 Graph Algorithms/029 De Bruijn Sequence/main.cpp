#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	short n; cin >> n;
	short k=(1<<n)/2;
	short d[k][2]; bool u[k][2], p[k];
	for (int i=0; i<k; i++) {
		d[i][0] = (i<<1) & (k-1);
		d[i][1] = d[i][0]+1;
		u[i][0] = u[i][1] = 0;
		p[i]=1;
	}
	for (int i=0; i<n-1; i++) cout << '0';
	short c=0;
	for (int i=0; i<2*k; i++) {
		cout << p[c];
		p[c] = !p[c];
		c = d[c][!p[c]];
	}
}