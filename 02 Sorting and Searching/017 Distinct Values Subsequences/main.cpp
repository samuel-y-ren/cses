#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int main() {
	int n; cin >> n;
	int x[n]; for (int i=0; i<n; i++) cin >> x[i];
	ll ct=1;
	map<int,int> a;
	for (int i : x) {
		if (a.find(i)==a.end()) a[i]=0;
		a[i]++;
	}
	for (auto i : a) ct = (ct*(i.second+1)%MOD);
	cout << (ct+MOD-1)%MOD;
}