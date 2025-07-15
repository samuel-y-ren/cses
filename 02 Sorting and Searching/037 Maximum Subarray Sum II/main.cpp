#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, a, b; cin >> n >> a >> b;
	int x[n]; for (int i=0; i<n; i++) cin >> x[i];
	ll ps[n+1];
	ps[0]=0; for (int i=0; i<n; i++) ps[i+1]=ps[i]+x[i];
	priority_queue<pair<ll,int>> pq;
	for (int i=a; i<=b; i++) pq.push({ps[i], i});
	ll mt=-1000000000000000000;
    for (int i=0; i<=n-a; i++) {
    	while (pq.top().second < i+a) pq.pop();
    	mt = max(mt, pq.top().first-ps[i]);
    	if (i+b+1<=n) pq.push({ps[i+b+1], i+b+1});
    }
    cout << mt << '\n';
}