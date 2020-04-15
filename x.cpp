/*
 * * We can solve this task using greedy and DFS.
    * If diameter of a subtree is not bigger than K, we can let it as it is,
or else we will have to cut the subtrees which have the highest depth and then compute the highest depth possible.
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ld pai=acos(-1);
int n , k , ans ;
vi v[200009];
int dis[200009];
void dfs ( int node , int p ) {
	vpi ret;
	for ( auto u : v[node] ) {
		if ( u == p ) C ;
		dfs ( u , node ) ;
		ret .pb ( { dis [u] , u } ) ;
	}
	sort ( ret.begin() , ret.end() );
	while ( ret.size() && ret.back().fi==k ) ret.ppb() , ans ++ ;
	while ( ret.size()>=2 && ret.back().fi + ret[ret.size()-2].fi + 2 > k ) ret.ppb() , ans ++ ; 
	if ( ret.size() ) dis[node] = ret.back().fi + 1 ;
}
int main () {
	ifstream fin("kdtree.in");
	ofstream fout("kdtree.out");
	fin >> n >> k ;
	for ( int i = 0 ; i < n - 1 ; i ++ ) {
		int a , b ;
		fin >> a >> b ;
		a -- , b -- ;
		v[a] .pb ( b ) ;
		v[b] .pb ( a ) ;
	}
	dfs ( 0 , 0 ) ;
	fout << ans << endl ;
}
