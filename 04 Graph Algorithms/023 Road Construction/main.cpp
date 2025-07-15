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
	for (int i=1; i<=n; i++) {
		p[i]=i; s[i]=1;
	}
	int mc=1;
	while (m--) {
		int a,b; cin >> a >> b;
		if (g(a) != g(b)) {
			mg(g(a),g(b)); 
			mc = max(mc, s[g(a)]);
			n--;
		}
		cout << n << ' ' << mc << '\n';
	}
}