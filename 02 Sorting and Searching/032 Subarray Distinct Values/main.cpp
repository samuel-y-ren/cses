#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define el << '\n'
#define nl cout << '\n'
#define cina(a,n) for (int i=0; i<n; i++) cin >> a[i]
#define ll long long
#define spc << ' '
#define forn(i,n) for (int i=0; i<n; i++)
#define forl(i,s,e) for (int i=s; i<e; i++)
#define MOD 1000000007
#define MOD2 998244353
#define pb push_back
#define ansyes cout << "YES\n"
#define ansno cout << "NO\n"
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<long long, long long>
#define pss pair<short, short>
#define MAX *max_element
#define MIN *min_element
#define rsz resize
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
    queue<int> c;
    map<int, int> v;
    ll tot=0;
    forn(i,n) {
        int temp; cin >> temp;
        c.push(temp);
        if (v.find(temp) == v.end()) v[temp]=1;
        else v[temp]++;
        while (v.size() > k) {
            int rn = c.front();
            c.pop();
            if (v[rn]==1) v.erase(rn);
            else v[rn]--;
        }
        tot += c.size();
    }
    cout << tot;
}