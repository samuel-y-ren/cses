#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

struct node {
	ll d=1000000000000000000;
	int n=0;
	int mi=1000000000, ma=-1000000000;
};

bool trans(node &t, const node &f, int d) {
	if (f.d+d>t.d) return false;
	if (f.d+d<t.d) {
		t.d=f.d+d;
		t.n=f.n;
		t.mi=f.mi+1;
		t.ma=f.ma+1;
		return true;
	}
	t.n+=f.n;
	t.n%=MOD;
	t.mi=min(t.mi,f.mi+1);
	t.ma=max(t.ma,f.ma+1);
	return false;
}

int main() {
	int n,m; cin >> n >> m;
	vector<pair<int,int>> adj[n+1];
	for (int i=0; i<m; i++) {
		int a,b,c; cin >> a >> b >> c;
		adj[a].push_back({b,c});
	}
	node dp[n+1];
	dp[1]={0,1,0,0};
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	pq.push({0,1});
	while (pq.size()) {
		ll cd=pq.top().first; int cn=pq.top().second;
		pq.pop();
		if (cd != dp[cn].d) continue;
		for (auto i:adj[cn]) if (trans(dp[i.first],dp[cn],i.second)) pq.push({dp[i.first].d,i.first});
	}
	cout << dp[n].d << ' ' << dp[n].n << ' ' << dp[n].mi << ' ' << dp[n].ma << '\n';
}