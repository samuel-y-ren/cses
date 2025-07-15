#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
 
int p[MAXN], s[MAXN];
 
int g(int nd) {
	if (p[p[nd]]==p[nd]) return p[nd];
	p[nd]=g(p[nd]);
	return p[nd];
}
 
void mg(int a, int b) {
	if (s[a]<s[b]) swap(a,b);
	p[b]=a;
	s[a]+=s[b];
}
 
struct ed{
	int a,b,c;
};
 
bool operator < (const ed &a, const ed &b) {
	return a.c>b.c;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m; cin >> n >> m;
	priority_queue<ed> pq;
	for (int i=1; i<=n; i++) {
		p[i]=i;
		s[i]=1;
	}
	while (m--) {
		int a,b,c; cin >> a >> b >> c;
		pq.push({a,b,c});
	}
	long long t=0; int nr=0;
	while (pq.size()) {
		ed ce=pq.top();
		pq.pop();
		if (g(ce.a) != g(ce.b)) {
			mg(g(ce.a),g(ce.b));
			t+=ce.c; nr++;
		}
	}
	if (nr==n-1) cout << t;
	else cout << "IMPOSSIBLE";
}