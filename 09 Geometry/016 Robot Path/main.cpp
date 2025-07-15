// File: main.cpp
// Author: Samuel Ren
// Created: 2025-07-13 21:24:28 PST

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// set to min
inline void smin(int& a, int b) {
    if (b<a) a=b;
}

// set to max
inline void smax(int& a, int b) {
    if (a<b) a=b;
}

// segment tree for point update and range rmq
struct segt {
    int n;
    vector<int> t;
    vector<set<int>> ln;
    segt (int n_) : n(n_) {
        t.resize(n<<1,INT_MAX);
        ln.resize(n,{INT_MAX});
    }
    void upd(int x, int v, bool q) {
        if (q) ln[x].insert(v);
        else ln[x].erase(v);
        if (t[x+n]!=(*(ln[x].begin()))) {
            t[x+n]=*(ln[x].begin());
            for (x+=n; x>1; x>>=1) t[x>>1]=min(t[x],t[x^1]);
        }
    }
    int qr(int l, int r) {
        int mv=INT_MAX;
        for (l+=n,r+=n; l<r; l>>=1,r>>=1) {
            if (l&1) smin(mv,t[l++]);
            if (r&1) smin(mv,t[--r]);
        }
        return mv;
    }
};

struct rg {
    ll l,r;
    rg() {}
    rg(const ll& l_, const ll& r_) : l(l_), r(r_) {}
};

bool operator< (const rg& a, const rg& b) {
    return a.l<b.l;
}

struct pt {
    ll x,y;
    pt() {}
    pt(ll x_, ll y_) : x(x_), y(y_) {}
};

struct line {
    ll x1,y1,x2,y2;
    line() {};
    line(const pt& p1, const pt& p2) : x1(p1.x), y1(p1.y), x2(p2.x), y2(p2.y) {}
};

// detects intersections of horizontal and vertical line segments and returns the first horizontal one
int fi(const vector<line> &v) { 
    //coordinate compress to be indexable
    vector<ll> xi={v[0].x1}, yi={v[0].y1};
    for (auto& i : v) {
        if (i.x1==i.x2) yi.emplace_back(i.y2);
        else xi.emplace_back(i.x2);
    }
    sort(xi.begin(),xi.end());
    sort(yi.begin(),yi.end());
    int m = (int)xi.size(), n = (int)yi.size();
    vector<ll> xin={xi[0]},yin={yi[0]};
    for (int i=1; i<m; ++i) if (xi[i]!=xi[i-1]) xin.emplace_back(xi[i]);
    for (int i=1; i<n; ++i) if (yi[i]!=yi[i-1]) yin.emplace_back(yi[i]);
    swap(xi,xin); swap(yi,yin);
    m=(int)xi.size();
    n=(int)yi.size();

    // split into horizontal and vertical pairs
    vector<pair<int,int>> vl[m+1]; // {y value, change value (+1/-1 for start and end)}
    vector<pair<rg,int>> hl[m]; // {{lower y, upper y}, index of line segment}
    int h=(int)v.size();
    for (int i=0; i<h; ++i) {
        auto r=v[i];
        // convert all values to coordinate compressed
        r.x1=lower_bound(xi.begin(),xi.end(),r.x1)-xi.begin();
        r.y1=lower_bound(yi.begin(),yi.end(),r.y1)-yi.begin();
        r.x2=lower_bound(xi.begin(),xi.end(),r.x2)-xi.begin();
        r.y2=lower_bound(yi.begin(),yi.end(),r.y2)-yi.begin();
        if (r.x1==r.x2) { // horizontal line
            if (r.y1<r.y2) hl[r.x1].emplace_back(rg(r.y1,r.y2),i); 
            else hl[r.x1].emplace_back(rg(r.y2+1,r.y1+1),i); 
        }
        else { // vertical line
            if (r.x1<r.x2) {
                vl[r.x1].emplace_back(r.y1,i); 
                vl[r.x2].emplace_back(r.y1,i|(1<<31));
            }
            else {
                vl[r.x2+1].emplace_back(r.y1,i); 
                vl[r.x1+1].emplace_back(r.y1,i|(1<<31));
            }
        }
    }
    int ff=INT_MAX;
    segt st(n);
    for (int i=0; i<m; ++i) {
        for (auto& j : vl[i]) st.upd(j.first,j.second&INT_MAX,j.second>=0);
        for (auto& j : hl[i]) {
            if (st.qr(j.first.l,j.first.r)<j.second) smin(ff,j.second); // detect if there are lines in range 
        }
    }
    return ff;

}

int det(map<ll,set<rg>>& s, ll v, rg r) {
    if (r.r<r.l) {
        swap(r.r,r.l);
        ++r.r; ++r.l;
        if (s.find(v)==s.end()) {
            s[v]={r};
            return INT_MAX;
        }
        auto ptr=s[v].lower_bound(rg(r.r,0ll));
        if (ptr!=s[v].begin()) {
            --ptr;
            if ((*ptr).r>r.l) return r.r-min(r.r,(*ptr).r);
        }
        s[v].insert(r);
        return INT_MAX;
    }
    if (s.find(v)==s.end()) {
        s[v]={r};
        return INT_MAX;
    }
    auto ptr=s[v].lower_bound(r);
    if (ptr!=s[v].begin()) {
        --ptr;
        if ((*ptr).r>r.l) return 0;
        ++ptr;
    }
    if (ptr!=s[v].end()) {
        if ((*ptr).l<r.r) return (*ptr).l-r.l;
    }
    s[v].insert(r);
    return INT_MAX;
}

int fd(map<ll,set<rg>>& s, ll v, rg r) { // can assume there will be an intersection
    rg sv(v,-1000000000000000000);
    if (r.r<r.l) {
        auto ptr=s.upper_bound(r.l);
        while (ptr!=s.begin()) {
            --ptr;
            auto p2=(*ptr).second.upper_bound(sv);
            if (p2!=(*ptr).second.begin()) {
                --p2; 
                if ((*p2).r>v) return r.l-(*ptr).first;
            }
        }
    }
    for (auto ptr=s.lower_bound(r.l);ptr!=s.end();++ptr) {
        auto p2=(*ptr).second.upper_bound(sv);
        if (p2!=(*ptr).second.begin()) {
            --p2;
            if ((*p2).r>v) return ((*ptr).first)-r.l;
        }
    }
    return -1;
}

// counterclockwise from right, +x=down, +y=right
const int dx[4] = {0,-1,0,1}; 
const int dy[4] = {1,0,-1,0};
const char dc[4] = {'R','U','L','D'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    pair<pt,int> p[n+1];
    ll x=0,y=0;
    for (int i=0; i<n; ++i) {
        p[i].first={x,y};
        char d; int m; cin >> d >> m;;
        for (int j=0; j<4; ++j) if (d==dc[j]) {
            p[i].second=j; 
            break;
        }
        x+=dx[p[i].second]*m;
        y+=dy[p[i].second]*m;
    }
    p[n].first={x,y};
    vector<line> v;
    for (int i=0; i<n; ++i) v.emplace_back(p[i].first,p[i+1].first);
    // finds first line that intersects with a perpendicular one
    int ev=fi(v);
    for (int i=0; i<n; ++i) { // swap x and y since function only detects intersections for horizontal lines 
        swap(v[i].x1,v[i].y1);
        swap(v[i].x2,v[i].y2);
    }
    smin(ev,fi(v));
    map<ll,set<rg>> mpv, mph; // sets to store ranges to detect parallel lines on the same value
    ll dt=0;
    for (int i=0; i<n; ++i) {
        if (i&&(p[i].second^2)==p[i-1].second) {
            cout << dt;
            return 0;
        }
        int mv = abs(p[i].second&1 ? p[i+1].first.x-p[i].first.x : p[i+1].first.y-p[i].first.y);
        int ov=mv;
        if (p[i].second&1) {
            smin(mv,det(mpv,p[i].first.y,rg(p[i].first.x,p[i+1].first.x)));
            if (ev==i) smin(mv,fd(mph,p[i].first.y,rg(p[i].first.x,p[i+1].first.x)));
        }
        else {
            smin(mv,det(mph,p[i].first.x,rg(p[i].first.y,p[i+1].first.y)));
            if (ev==i) smin(mv,fd(mpv,p[i].first.x,rg(p[i].first.y,p[i+1].first.y)));
        }
        dt+=mv;
        if (ov!=mv) {
            cout << dt;
            return 0;
        }
    }
    cout << dt;
}