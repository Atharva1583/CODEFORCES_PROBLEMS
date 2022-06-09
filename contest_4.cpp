//
// Created by Icon on 07-06-2022.
//

// CP
// Atharva's Code
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef  long double lld;
typedef unsigned long long ull;

const lld pi = 3.141592653589793238;
const ll INF = LONG_LONG_MAX;
const ll mod =1e9+7;

typedef pair<ll,ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<string> vs;
typedef map<ll,ll> ml;
typedef unordered_map<ll,ll> uml;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repR(i,a,b) for(ll i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
#define setBits(x) builtin_popcount(x)
#define arraySum(a)  accumulate(a.begin(), a.end(),(ll)0);
ll binaryToDecimal(string s){
    return stoi(s,0,2);
}
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

void solve(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll b=0,w=0;
    rep(i,0,n){
        if(s[i]=='B'){
            b++;
        }else{
            w++;
        }
    }
    if(w==n){
        cout<<k<<endl;
        return;
    }
    vl prefix(n,0);
    if(s[0]=='W'){
        prefix[0]=1;
    }else{
        prefix[0]=0;
    }
    rep(i,1,n){
        prefix[i]=prefix[i-1];
        if(s[i]=='W'){
            prefix[i]+=1;
        }
    }
    ll ans=LONG_LONG_MAX;
    rep(i,0,n){
        if(i+k-1 < n){
            ll x=prefix[i+k-1];
            if(i-1>=0){
                x-=prefix[i-1];
            }
            ans=min(ans,x);
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;cin>>t;
    while (t--){
        solve();
    }
}