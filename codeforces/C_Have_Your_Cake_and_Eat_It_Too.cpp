#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define read(x) int x; cin>>x
#define readll(x) ll x; cin>>x
#define readstr(s) string s; cin>>s
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,a,n) for(int i=(a); i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define maxi(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mini(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
#define pb push_back
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!



void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD> > &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================


void guru(){
    int n;
    cin>>n;
    
    vi a(n);
    vi b(n);
    vi c(n);

    cin>>a;
    cin>>b;
    cin>>c;

    int xyz = 0;

    fr(i,0,n){
        xyz+=a[i];
    }
    
    int tot =  (xyz+2)/3;
    int sa,sb, sc, ea, eb, ec;

    //looking for all permutation

    //start alice
    int sum = 0, i = 0;
    sa = 0;
    
    while(i<n && sum<tot){
        sum+=a[i];
        i++;
    }
    ea = i-1;

    //followed by bob

    sum = 0;
    sb = i;

    while( i<n && sum<tot){
        sum+=b[i];
        i++;
    }

    eb = i-1;

    // followed by charlie

    sum = 0;
    sc = i;

    while( i<n && sum<tot){
        sum+=c[i];
        i++;
    }

    ec = i-1;

    if( sum>=tot && sa<n && sb <n && sc<n && ea<n && eb<n && ec<n ){

        cout<<sa+1LL<<" "<<ea+1LL<<" "<<sb+1LL<<" "<<eb+1LL<<" "<<sc+1LL<<" "<<ec+1LL;
        nl;
       return;
    }

    //start alice
    sum = 0; i = 0;
    sa = 0;
    
    while(i<n && sum<tot){
        sum+=a[i];
        i++;
    }
    ea = i-1;

    //followed by charlie

    sum = 0;
    sc = i;

    while( i<n && sum<tot){
        sum+=c[i];
        i++;
    }

    ec = i-1;

    // followed by bob

    sum = 0;
    sb = i;

    while( i<n && sum<tot){
        sum+=b[i];
        i++;
    }

    eb = i-1;

    if(sum>= tot && sa<n && sb <n && sc<n && ea<n && eb<n && ec<n){
        cout<<sa+1LL<<" "<<ea+1LL<<" "<<sb+1LL<<" "<<eb+1LL<<" "<<sc+1LL<<" "<<ec+1LL;
       nl;
       return;
    }

    //start bob
     sum = 0; i = 0;
    sb = 0;
    
    while(i<n && sum<tot){
        sum+=b[i];
        i++;
    }
    eb = i-1;

    //followed by alice

    sum = 0;
    sa = i;

    while( i<n && sum<tot){
        sum+=a[i];
        i++;
    }

    ea = i-1;

    // followed by charlie

    sum = 0;
    sc = i;

    while( i<n && sum<tot){
        sum+=c[i];
        i++;
    }

    ec = i-1;

    if(sum>= tot && sa<n && sb <n && sc<n && ea<n && eb<n && ec<n){
        cout<<sa+1LL<<" "<<ea+1LL<<" "<<sb+1LL<<" "<<eb+1LL<<" "<<sc+1LL<<" "<<ec+1LL;
       nl;
       return;
    }

    //start bob
     sum = 0; i = 0;
    sb = 0;
    
    while(i<n && sum<tot){
        sum+=b[i];
        i++;
    }
    eb = i-1;

    //followed by charlie

    sum = 0;
    sc = i;

    while( i<n && sum<tot){
        sum+=c[i];
        i++;
    }

    ec = i-1;

    // followed by alice

    sum = 0;
    sa = i;

    while( i<n && sum<tot){
        sum+=a[i];
        i++;
    }

    ea = i-1;

    if(sum>= tot && sa<n && sb <n && sc<n && ea<n && eb<n && ec<n){
        cout<<sa+1LL<<" "<<ea+1LL<<" "<<sb+1LL<<" "<<eb+1LL<<" "<<sc+1LL<<" "<<ec+1LL;
       nl;
       return;
    }

    //start charlie
    sum = 0; i = 0;
    sc = 0;
    
    while(i<n && sum<tot){
        sum+=c[i];
        i++;
    }
    ec = i-1;

    //followed by bob

    sum = 0;
    sb = i;

    while( i<n && sum<tot){
        sum+=b[i];
        i++;
    }

    eb = i-1;

    // followed by alice

    sum = 0;
    sa = i;

    while( i<n && sum<tot){
        sum+=a[i];
        i++;
    }

    ea = i-1;

    if(sum>= tot && sa<n && sb <n && sc<n && ea<n && eb<n && ec<n){
        cout<<sa+1LL<<" "<<ea+1LL<<" "<<sb+1LL<<" "<<eb+1LL<<" "<<sc+1LL<<" "<<ec+1LL;
       nl;
       return;
    }

    //start charlie
    sum = 0; i = 0;
    sc = 0;
    
    while(i<n && sum<tot){
        sum+=c[i];
        i++;
    }
    ec = i-1;

    //followed by alice

    sum = 0;
    sa = i;

    while( i<n && sum<tot){
        sum+=a[i];
        i++;
    }

    ea = i-1;

    // followed by bob

    sum = 0;
    sb = i;

    while( i<n && sum<tot){
        sum+=b[i];
        i++;
    }

    eb = i-1;

    if(sum>= tot && sa<n && sb <n && sc<n && ea<n && eb<n && ec<n){
        cout<<sa+1LL<<" "<<ea+1LL<<" "<<sb+1LL<<" "<<eb+1LL<<" "<<sc+1LL<<" "<<ec+1LL;
       nl;
       return;
    }

    cout<<-1;nl;  
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        guru();
    }
    return 0;
}