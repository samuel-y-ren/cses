#include <bits/stdc++.h>
using namespace std;

int dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
char dir[4]={'L','D','R','U'};

int main() {
	int n,m; cin >> n >> m;
	int px,py;
	bool g[n+2][m+2];
	int md[n+2][m+2];
	int pd[n+2][m+2];
	for (int i=0; i<n+2; i++) g[i][0]=g[i][m+1]=1;
	for (int i=0; i<m+2; i++) g[0][i]=g[n+1][i]=1;
	for (int i=0; i<n+2; i++) for (int j=0; j<m+2; j++) {
		md[i][j]=1000000000;
		pd[i][j]=-1;
	}
	queue<pair<pair<int,int>,int>> q;
	for (int i=1; i<=n; i++) {
		string s; cin >> s;
		for (int j=1; j<=m; j++) {
			char c = s[j-1];
			g[i][j] = (c=='#');
			if (c=='M') q.push({{i,j},0});
			if (c=='A') {
				px=i; py=j;
			}
		}
	}
	while (q.size()) {
		int x=q.front().first.first, y=q.front().first.second, d=q.front().second;
		q.pop();
		if (md[x][y]!=1000000000 || g[x][y]) continue;
		md[x][y]=d;
		for (int i=0; i<4; i++) q.push({{x+dx[i],y+dy[i]},d+1});
	}
	q.push({{px,py},0});
	while (q.size()) {
		int x=q.front().first.first, y=q.front().first.second, d=q.front().second;
		q.pop();
		if (pd[x][y]!=-1 || g[x][y] || md[x][y]<=d) continue;
		pd[x][y]=d;
		for (int i=0; i<4; i++) q.push({{x+dx[i],y+dy[i]},d+1});
	}
	int ex=-1,ey=-1;
	for (int i=1; i<=n; i++) {
		if (pd[i][1]!=-1) {
			ex=i;ey=1;
		}
		if (pd[i][m]!=-1) {
			ex=i;ey=m;
		}
	}
	for (int i=1; i<=m; i++) {
		if (pd[1][i]!=-1) {
			ex=1;ey=i;
		}
		if (pd[n][i]!=-1) {
			ex=n;ey=i;
		}
	}
	if (ex==-1) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	int l=pd[ex][ey];
	cout << l << '\n';
	string p;
	for (int i=0; i<l; i++) {
		for (int j=0; j<4; j++) {
			if (pd[ex+dx[j]][ey+dy[j]]==l-i-1) {
				p.push_back(dir[j]);
				ex += dx[j]; ey += dy[j];
				break;
			}
		}
	}
	for (int i=l-1; i>=0; i--) cout << p[i];
}