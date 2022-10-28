#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define fast_io ios_base:: sync_with_stdio(false);cin.tie(0);cout.tie(0)
 
template<typename T1, typename T2>istream& operator>>(istream& in, pair<T1, T2> &a) {in >> a.fr >> a.sc; return in;}
template<typename T1, typename T2>ostream& operator<<(ostream& out, pair<T1, T2> a) {out << a.fr << " " << a.sc; return out;}
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
struct P
{
	int x, y;
 
	void read() {
		cin >> x >> y;
	}
	P operator - (const P &b) const {
		return P{x - b.x, y - b.y};
	}
	int operator * (const P &b) const {
		return (x * b.y - b.x * y);
	}
	bool operator < (const P & b) const {
		return make_pair(x, y) < make_pair(b.x, b.y);
 
	}
	int triangle(P &b, P &c) {
		return ((b - *this) * (c - *this));
	}
};
 
 
 
 
 
signed main() {
 
	int n, x, y;
	cin >> n;
	std::vector<P> points(n);
	for (int i = 0; i < n; i++) {
		points[i].read();
	}
	sort(points.begin(), points.end());
	vector<P> hull;
	for (int rep = 0; rep < 2; rep++) {
		int S = hull.size();
		for (auto C : points) {
			while ((int)hull.size() + S >= 2) {
				auto A = hull.end()[-1];
				auto B = hull.end()[-2];
				if (A.triangle(B, C) <= 0) {
					break;
				}
				hull.pop_back();
 
			}
			hull.push_back(C);
 
		}
		hull.pop_back();
		reverse(points.begin(), points.end());
 
	}
	cout << hull.size() << endl;
	for (auto Point : hull) {
		cout << Point.x << " " << Point.y << endl;
	}
 
}
