#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;

#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define repn(i, n) for (int i = (n); i >= 0; --i) 
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
    // int t;
    // cin >> t;
    // TC(t)
    // {
    int n, m;
    cin >> n >> m;

    pair<int, int> src, dst;

    vector<vector<char>> grid(n, vector<char>(m, '-'));

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                src.first = i;
                src.second = j;
            }
            if (grid[i][j] == 'B')
            {
                dst.first = i;
                dst.second = j;
            }
        }
    }


    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vis[src.first][src.second] = true;

    vector<vector<char>> prev_vis(n, vector<char>(m, '.'));

    vector<pair<int, int>> directions = { {-1,0},{0,1},{1,0},{0,-1} };
    vector<char> dirChar = { 'U','R','D','L' };

    string ans = "";

    queue<pair<int, int>> q;
    q.push(src);

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        if (it == dst)
        {
            break;
        }

        for (int k = 0;k < 4;k++)
        {
            int ni = it.first + directions[k].first;
            int nj = it.second + directions[k].second;

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && (grid[ni][nj] == '.' || grid[ni][nj] == 'B') && !vis[ni][nj])
            {
                vis[ni][nj] = true;
                q.push({ ni,nj });
                prev_vis[ni][nj] = dirChar[k];
            }
        }
    }




    if (vis[dst.first][dst.second])
    {
        cout << "YES\n";
        string ans = "";

        while (dst != src)
        {
            ans += prev_vis[dst.first][dst.second];
            if (prev_vis[dst.first][dst.second] == 'L') { dst = { dst.first,dst.second + 1 }; }
            else if (prev_vis[dst.first][dst.second] == 'R') { dst = { dst.first,dst.second - 1 }; }
            else if (prev_vis[dst.first][dst.second] == 'D') { dst = { dst.first - 1,dst.second }; }
            else if (prev_vis[dst.first][dst.second] == 'U') { dst = { dst.first + 1,dst.second }; }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.length() << '\n';
        cout << ans << '\n';
    }
    else
    {
        cout << "NO\n";
    }
    // }
    return 0;
}