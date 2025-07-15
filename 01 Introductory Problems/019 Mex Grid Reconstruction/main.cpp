#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int m[n][n]; for (int i=0; i<n; i++) for (int j=0; j<n; j++) m[i][j]=0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			bool u[2*n]; for (int i=0; i<2*n; i++) u[i]=0;
			for (int k=0; k<i; k++) u[m[k][j]]=1;
			for (int k=0; k<j; k++) u[m[i][k]]=1;
			for (int k=0; k<2*n; k++) if (!u[k]) {
				m[i][j]=k;
				break;
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) cout << m[i][j] << ' ';
		cout << '\n';
	}
}