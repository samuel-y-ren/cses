#include <bits/stdc++.h>
using namespace std;

int n, m;
int g[1005][1005];
pair<int, int> s,e;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
char dir[4]={'D','R','U','L'};

int main() {
	cin >> n >> m;
	for (int i=0; i<n+2; i++) {
		g[i][0]=-1;
		g[i][m+1]=-1;
	}
	for (int i=0; i<m+2; i++) {
		g[0][i]=-1;
		g[n+1][i]=-1;
	}
	for (int i=0; i<n; i++) {
		string st; cin >> st;
		for (int j=0; j<m; j++) {
			if (st[j]=='#') g[i+1][j+1]=-1;
			else g[i+1][j+1]=0;
			if (st[j]=='B') s={i+1,j+1};
			else if (st[j]=='A') e={i+1,j+1};
		}
	}
	queue<pair<pair<int,int>,int>> q;
	q.push({s,1});
	while (q.size()) {
		int x=q.front().first.first, y=q.front().first.second, d=q.front().second;
		q.pop();
		if (g[x][y]) continue;
		g[x][y]=d;
		for (int i=0; i<4; i++) q.push({{x+dx[i],y+dy[i]},d+1});
	}
	if (g[e.first][e.second]) {
		cout << "YES\n";
		int l=g[e.first][e.second]-1;
		cout << l << '\n';
		int cx=e.first,cy=e.second;
		for (int i=0; i<l; i++) {
			for (int j=0; j<4; j++) if (g[cx+dx[j]][cy+dy[j]]==l-i) {
				cx += dx[j]; cy += dy[j];
				cout << dir[j];
			}
		}
	}
	else {
		cout << "NO\n";
	}
}