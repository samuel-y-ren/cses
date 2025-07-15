#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int x[n]; for (int i=0; i<n; i++) cin >> x[i];
	map<int,int> pos;
	int nc[n]; for (int i=0; i<n; i++) nc[i]=1000000000;
	for (int i=0; i<n; i++) {
		if (pos.find(x[i])!=pos.end()) nc[pos[x[i]]]=i;
		pos[x[i]]=i;
	}
	int no=n;
	long long tot=0;
	for (int i=n-1; i>=0; i--) {
		no = min(no,nc[i]);
		tot += no-i;
	}
	cout << tot;
}