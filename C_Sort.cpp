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
    read(n);
    read(q);

    readstr(a);
    readstr(b);

    vector<pair<int,int> > qr;

    fr(i,0,q){
        read(x);
        read(y);

        pair<int,int> p;
        p.first = x;
        p.second = y;

        qr.pb(p);
    }

    vvi a_alpha(n+1,vi(26,0));
    vvi b_alpha(n+1,vi(26,0));

    fr(i,0,n){
        int ch = a[i] - 'a';
        int chb = b[i] - 'a';
        fr(j,0,26){
            if(j == ch){
                a_alpha[i+1][j] = a_alpha[i][j] + 1;
            }
            else {
                a_alpha[i+1][j] = a_alpha[i][j];
            }
            if(j == chb){
                b_alpha[i+1][j] = b_alpha[i][j] + 1;
            }
            else {
                b_alpha[i+1][j] = b_alpha[i][j];
            }


        }
    }

    

    fr(i,0,q){
        auto it = qr[i];
        int l = it.first;
        int r = it.second;
        int change = 0;
        for(int j = 0;j<26;j++){
            int kitna = a_alpha[r][j] - a_alpha[l-1][j];
            int kitna2 = b_alpha[r][j] - b_alpha[l-1][j];

            if(kitna !=kitna2) change+=abs(kitna-kitna2);

        }
        cout<<change/2;
        nl;
    }
    
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
