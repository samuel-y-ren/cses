#include <bits/stdc++.h>
using namespace std;

const int dx[8]={-1,-2,-2,-1,1,2,2,1};
const int dy[8]={2,1,-1,-2,-2,-1,1,2};

int main() {
	int n; cin >> n;
	int d[n][n]; for (int i=0; i<n; i++) for (int j=0; j<n; j++) d[i][j]=-1;
	queue<pair<pair<int,int>,int>> q;
	q.push({{0,0},0});
	while (q.size()) {
		int x = q.front().first.first, y = q.front().first.second, dt=q.front().second;
		q.pop();
		if (x<0 || y<0 || x>=n || y>=n) continue;
		if (d[x][y] != -1) continue;
		d[x][y]=dt;
		for (int i=0; i<8; i++) q.push({{x+dx[i],y+dy[i]},dt+1});
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) cout << d[i][j] << ' ';
		cout << '\n';
	}
}