#include <bits/stdc++.h>
using namespace std;

bitset<1000000005> v;

int main() {
	int n, x; cin >> n >> x;
	int a[n]; for (int i=0; i<n; i++) cin >> a[i];
	for (int i=n-1; i>0; i--) {
		for (int j=0; j<i; j++) {
			int r = x-a[i]-a[j];
			if (r>0 && v[r]) {
				for (int k=i+1; k<n; k++) if (a[k]==r) {
					cout << j+1 << ' ' << i+1 << ' ' << k+1 << '\n';
					return 0;
				}
			}
		}
		v[a[i]]=1;
	}
	cout << "IMPOSSIBLE\n";
}