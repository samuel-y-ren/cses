#include <bits/stdc++.h>
using namespace std;

struct sort_end {
	bool operator()(const pair<int, int> a, const pair<int, int> b) const {
		return a.second>b.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, sort_end> mq;
multiset<int> pq;

int main() {
	int n, k; cin >> n >> k;
	for (int i=0; i<n; i++) {
		int a, b; cin >> a >> b;
		mq.push({a,b});
	}
	for (int i=0; i<k; i++) pq.insert(0);
	int tot=0;
	while (mq.size()) {
		if (mq.top().first<*pq.begin()) {
			mq.pop();
			continue;
		}
		// pq.pop();
		// pq.push(mq.top().second);
		auto p = pq.upper_bound(mq.top().first);
		p--;
		pq.erase(p);
		pq.insert(mq.top().second);
		mq.pop();
		tot++;
	}
	cout << tot << '\n';
}