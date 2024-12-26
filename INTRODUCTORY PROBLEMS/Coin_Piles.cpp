#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef vector<int> vi; 
typedef vector<vi> vvi;  
typedef vector<ll> vl; 
typedef vector<vl> vvl; 

#define f(a, b, c) for (int(a) = (b); (a) < (c); ++(a)) 
#define fn(a, b, c) for (int(a) = (b); (a) >= (c); --(a)) 
#define fit(a, b) for (auto&(a) : (b)) 

#define rep(i, n) f(i, 0, n) 
#define repn(i, n) fn(i, 1, n) 
#define SQR(x) ((LL)(x) * (x)) 

#define i(a,n) rep(i,n) cin>>a[i]
#define o(a,n) rep(i,n) cout<<a[i]<<" " ; cout<<endl;

#define ALL(v) v.begin(), v.end() 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 
#define TC(t) while (t--) 
#define mod (ll)(1e9 + 7)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    TC(t)
    {
        int a,b;
        cin>>a>>b;

        // while(a>0 && b>0)
        // {
        //     if(a>b)
        //     {
        //         a -=2;
        //         b -=1;
        //     }
        //     else
        //     {
        //         a -=1;
        //         b -=2;
        //     }
        // }
        // if(a==0 && b==0)
        // {
        //     cout<<"YES"<<endl;
        // }
        // else
        // {
        //     cout<<"NO"<<endl;
        // }

        int x = (2*b -a);
        int y = (2*a -b);

        if(x>=0 && y>=0 && x%3==0 && y%3==0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

}