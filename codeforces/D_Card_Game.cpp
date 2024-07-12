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
    char ch;
    cin>>ch;

    vector<string> v(2*n);

    fr(i,0,2*n){
        string s;
        cin>>s;
        v[i] = (s);
    }

    map<char,vector<int> > mp;

    vector<pair<string,string> > ans; 

    int m = 2*n;

    //kitne c,d,s,h hai
    fr(i,0,m){
        mp[v[i][1]].push_back(i);
    }

    for(auto it = mp.begin();it!=mp.end();it++){
        if(it->first!=ch){
            while(it->second.size()>1){
                int size = it->second.size();
                if(v[it->second[size-1]]<v[it->second[size-2]]){
                    pair<string,string> p;
                    p.first = v[it->second[size-1]];
                    p.second = v[it->second[size-2]];
                    ans.pb(p);
                }
                else{
                   pair<string,string> p;
                    p.first = v[it->second[size-2]];
                    p.second = v[it->second[size-1]];
                    ans.pb(p);
                }
                it->second.pop_back();
                it->second.pop_back();
            }
            
        }
    }

    if(ch == 'S'){

        if(mp['C'].size() == 1){
            if(mp['S'].size() == 0){
                cout<<"IMPOSSIBLE";
                nl;return;
            }else{
                int sz = mp['S'].size();
                cout<<v[mp['C'][0]]<<" "<<v[mp['S'][sz-1]];
                nl;
                mp['S'].pop_back();
            }
        }
        if(mp['H'].size() == 1){
            if(mp['S'].size() == 0){
                cout<<"IMPOSSIBLE";
                nl;return;
            }else{
                int sz = mp['S'].size();
                cout<<v[mp['H'][0]]<<" "<<v[mp['S'][sz-1]];
                nl;
                mp['S'].pop_back();
            }
        }
        if(mp['D'].size() == 1){
            if(mp['S'].size() == 0){
                cout<<"IMPOSSIBLE";
                nl;return;
            }else{
                int sz = mp['S'].size();
                cout<<v[mp['D'][0]]<<" "<<v[mp['S'][sz-1]];
                nl;
                mp['S'].pop_back();
            }
        }

        while(mp['S'].size()>1){
                int size = mp['S'].size();

                if(v[mp['S'][size-1]]<v[mp['S'][size-2]]){
                    pair<string,string> p;
                    p.first = v[mp['S'][size-1]];
                    p.second = v[mp['S'][size-2]];
                    ans.pb(p);
                }
                else {
                    pair<string,string> p;
                    p.first = v[mp['S'][size-2]];
                    p.second = v[mp['S'][size-1]];
                    ans.pb(p);
                }
                
                mp['S'].pop_back();
                mp['S'].pop_back();
            }

            if(mp['S'].size() == 1){
                cout<<"IMPOSSIBLE";
                nl;return;
            }
    }
    if(ch == 'D'){

        if(mp['C'].size() == 1){
            if(mp['D'].size() == 0){
                cout<<"IMPOSSIBLE";
                nl;return;
            }else{
                int sz = mp['D'].size();
                cout<<v[mp['C'][0]]<<" "<<v[mp['D'][sz-1]];
                nl;
                mp['D'].pop_back();
            }
        }
        if(mp['H'].size() == 1){
            if(mp['D'].size() == 0){
                cout<<"IMPOSSIBLE";
                nl;return;
            }else{
                int sz = mp['D'].size();
                cout<<v[mp['H'][0]]<<" "<<v[mp['D'][sz-1]];
                nl;
                mp['D'].pop_back();
            }
        }
        if(mp['S'].size() == 1){
            if(mp['D'].size() == 0){
                cout<<"IMPOSSIBLE";
                nl;return;
            }else{
                int sz = mp['D'].size();
                cout<<v[mp['S'][0]]<<" "<<v[mp['D'][sz-1]];
                nl;
                mp['D'].pop_back();
            }
        }

        while(mp['D'].size()>1){
                int size = mp['D'].size();
               if(v[mp['D'][size-1]]<v[mp['D'][size-2]]){
                    pair<string,string> p;
                    p.first = v[mp['D'][size-1]];
                    p.second = v[mp['D'][size-2]];
                    ans.pb(p);
                }
                else {
                    pair<string,string> p;
                    p.first = v[mp['D'][size-2]];
                    p.second = v[mp['D'][size-1]];
                    ans.pb(p);
                }
                mp['D'].pop_back();
                mp['D'].pop_back();
            }

            if(mp['D'].size() == 1){
                cout<<"IMPOSSIBLE";
                nl;return;
            }

    }
    if(ch == 'C'){

        if(mp['S'].size() == 1){
            if(mp['C'].size() == 0){
                cout<<"IMPOSSIBLE";
                nl;return;
            }else{
                int sz = mp['C'].size();
                cout<<v[mp['S'][0]]<<" "<<v[mp['C'][sz-1]];
                nl;
                mp['C'].pop_back();
            }
        }
        if(mp['H'].size() == 1){
            if(mp['C'].size() == 0){
                cout<<"IMPOSSIBLE";
                nl;return;
            }else{
                int sz = mp['C'].size();
                cout<<v[mp['H'][0]]<<" "<<v[mp['C'][sz-1]];
                nl;
                mp['C'].pop_back();
            }
        }
        if(mp['D'].size() == 1){
            if(mp['C'].size() == 0){
                cout<<"IMPOSSIBLE";
                nl;return;
            }else{
                int sz = mp['C'].size();
                cout<<v[mp['D'][0]]<<" "<<v[mp['C'][sz-1]];
                nl;
                mp['C'].pop_back();
            }
        }

        while(mp['C'].size()>1){
                int size = mp['C'].size();
               if(v[mp['C'][size-1]]<v[mp['C'][size-2]]){
                    pair<string,string> p;
                    p.first = v[mp['C'][size-1]];
                    p.second = v[mp['C'][size-2]];
                    ans.pb(p);
                }
                else {
                    pair<string,string> p;
                    p.first = v[mp['C'][size-2]];
                    p.second = v[mp['C'][size-1]];
                    ans.pb(p);
                }
                mp['C'].pop_back();
                mp['C'].pop_back();
            }

            if(mp['C'].size() == 1){
                cout<<"IMPOSSIBLE";
                nl;return;
            }

    }
    if(ch == 'H'){

        if(mp['C'].size() == 1){
            if(mp['H'].size() == 0){
                cout<<"IMPOSSIBLE";
                nl;return;
            }else{
                int sz = mp['H'].size();
                cout<<v[mp['C'][0]]<<" "<<v[mp['H'][sz-1]];
                nl;
                mp['H'].pop_back();
            }
        }
        if(mp['S'].size() == 1){
            if(mp['H'].size() == 0){
                cout<<"IMPOSSIBLE";
                nl;return;
            }else{
                int sz = mp['H'].size();
                cout<<v[mp['S'][0]]<<" "<<v[mp['H'][sz-1]];
                nl;
                mp['H'].pop_back();
            }
        }
        if(mp['D'].size() == 1){
            if(mp['H'].size() == 0){
                cout<<"IMPOSSIBLE";
                nl;return;
            }else{
                int sz = mp['H'].size();
                cout<<v[mp['D'][0]]<<" "<<v[mp['H'][sz-1]];
                nl;
                mp['H'].pop_back();
            }
        }

        while(mp['H'].size()>1){
                int size = mp['H'].size();
              if(v[mp['H'][size-1]]<v[mp['H'][size-2]]){
                    pair<string,string> p;
                    p.first = v[mp['H'][size-1]];
                    p.second = v[mp['H'][size-2]];
                    ans.pb(p);
                }
                else {
                   pair<string,string> p;
                    p.first = v[mp['H'][size-2]];
                    p.second = v[mp['H'][size-1]];
                    ans.pb(p);
                }
                mp['H'].pop_back();
                mp['H'].pop_back();
            }

            if(mp['H'].size() == 1){
                cout<<"IMPOSSIBLE";
                nl;return;
            }

    }

    fr(i,0,ans.size()){
        cout<<ans[i].first<<" "<<ans[i].second;
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
