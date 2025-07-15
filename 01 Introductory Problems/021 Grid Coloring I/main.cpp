#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m; cin >> n >> m;
	string g[n]; for (int i=0; i<n; i++) cin >> g[i];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if ((i+j)%2) {
				if (g[i][j]=='A') cout << 'C';
				else cout << 'A';
			}
			else {
				if (g[i][j]=='B') cout << 'D';
				else cout << 'B';
			}
		}
		cout << '\n';
	}

}
	