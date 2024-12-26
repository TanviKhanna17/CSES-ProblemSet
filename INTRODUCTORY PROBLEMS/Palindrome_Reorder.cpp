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

    string s;
    cin >> s;

    int n = s.size();
    vector<int> freq(26, 0);

    for (int i = 0; i < n; i++) {
        freq[s[i] - 'A']++;
    }

    bool odd_found = false;
    char odd_char;
    string first_half = "";

    for (int i = 0; i < 26; i++) 
    {
        if (freq[i] % 2 == 1) 
        {
            if (odd_found) {
                cout << "NO SOLUTION";
                return 0;
            }
            odd_found = true;
            odd_char = i + 'A';
        }

        first_half += string(freq[i] / 2, i + 'A');
    }

    string second_half = first_half;
    reverse(second_half.begin(), second_half.end());

    if (odd_found) {
        cout << first_half + odd_char + second_half << '\n';
    } else {
        cout << first_half + second_half << '\n';
    }
}