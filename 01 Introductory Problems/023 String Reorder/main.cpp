#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int n = s.size();
	int c[26]; for (int i=0; i<26; i++) c[i]=0;
	for (char i : s) c[int(i)-int('A')]++;
	auto p = max_element(c,c+26);
	if (*p>(n+1)/2) {
		cout << -1;
		return 0;
	}
	int pv=-1;
	for (int i=0; i<n; i++) {
		p=max_element(c,c+26);
		if ((n-i)%2&&*p==(n-i+2)/2) {
			cout << char(65+(p-c));
			pv=p-c;
			(*p)--;
			continue;
		}
		for (int j=0; j<26; j++)  if (c[j]) {
			if (pv==j) continue;
			cout << char(65+j);
			pv=j;
			c[j]--;
			break;
		}
	}
}