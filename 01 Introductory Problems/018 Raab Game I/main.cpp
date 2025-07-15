#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n,a,b; cin >> n >> a >> b;
		if (a+b==0) {
			cout << "YES\n";
			for (int i=1; i<=n; i++) cout << i << ' ';
			cout << '\n';
			for (int i=1; i<=n; i++) cout << i << ' ';
			cout << '\n';
		}
		else if (a+b==1) cout << "NO\n";
		else if (a+b>n) cout << "NO\n";
		else if (a==0 || b==0) cout << "NO\n";
		else {
			cout << "YES\n";
			for (int i=1; i<=n; i++) cout << i << ' ';
			cout << '\n';
			for (int i=1; i<=b; i++) cout << i+a << ' ';
			for (int i=b+1; i<=a+b; i++) cout << i-b << ' ';
			for (int i=a+b+1; i<=n; i++) cout << i << ' ';
			cout << '\n';
		}
	}
}