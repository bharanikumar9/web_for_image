#include<bits/stdc++.h>
#define ll long long
#define ln cout<<"\n"
using namespace std;
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define pc(x) __builtin_popcount(x)
void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    //cerr << '[' << endl;
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T> using indexed_set = 
tree<T,null_type,less<T>,rb_tree_tag,
tree_order_statistics_node_update>;

void solve(){
	
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for(auto &i : v)cin >> i;
    indexed_set<pi> s;  
    rep(i,0,n){
        s.insert({v[i],i});
    }
    rep(i,0,q){
        char c;
        cin >> c;
        if(c == '!'){
            int k,x;
            cin >> k >> x;
            --k;
            s.erase({v[k],k});
            s.insert({x,k});
            v[k] = x;
        }
        else{
            int a,b;
            cin >> a >> b;
            int r = s.order_of_key({b + 1,-1}) - s.order_of_key({a - 1,n + 1});
            cout << r;ln;
        }
    }  


}	

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // gen_factorial(1e6);  	
    int test=1;
	// cin>>test;   
    while(test--)
        solve();
    return 0;
}
