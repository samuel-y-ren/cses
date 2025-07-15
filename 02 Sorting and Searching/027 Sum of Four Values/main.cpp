#include <bits/stdc++.h>
using namespace std;

bitset<1000000005> v;

int main() {
	int n, x; cin >> n >> x;
	int a[n]; for (int i=0; i<n; i++) cin >> a[i];
	for (int k=1; k<n-1; k++) {
		for (int l=k+1; l<n; l++) {
			int r=x-a[k]-a[l];
			if (r>0 && v[r]) {
				for (int i=0; i<k-1; i++) for (int j=i+1; j<k; j++) if (a[i]+a[j]==r) {
					cout << i+1 << ' ' << j+1 << ' ' << k+1 << ' ' << l+1 << '\n';
					return 0;
				}
			}
		}
		for (int i=0; i<k; i++) {
			int r=a[i]+a[k];
			if (r<x) v[r]=1;
		}
	}
	cout << "IMPOSSIBLE\n";
}
