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

// 1 2 3     4 5 6 7
// 1 6 2 5
// 3 4 7 


// 1 2 3 4 5       6 7 8 9 10 11

// 1 10 2 9 3 8
// 4 7 5 6 11


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin>>t;
    // TC(t)
    // {
        
    // }

    int n;
    cin>>n;
    if(n<=2)
    {
        cout<<"NO\n";
    }
    else
    {
        ll total_sum = n*(n+1)/2;
        ll to_look = total_sum/2;

        if(total_sum&1)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
            vi v1,v2;

            ll s1 = 0;
            ll s2 = 0;

            int k = n;
            while(k>0)
            {
                if(s1 <= s2)
                {
                    v1.push_back(k);
                    s1+=k;
                }
                else
                {
                    v2.push_back(k);
                    s2+=k;
                }
                k--;
            }

            cout<<v1.size()<<"\n";
            for(auto it:v1)
            {
                cout<<it<<" ";
            }
            cout<<'\n';
            cout<<v2.size()<<"\n";
            for(auto it:v2)
            {
                cout<<it<<" ";
            }
        }

    }
    return 0;
}