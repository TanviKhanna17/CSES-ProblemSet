#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

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

vector<pair<int, int>> directions = { {-1,0},{0,1},{1,0},{0,-1} };

void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis)
{
    vis[i][j] = true;
    int n = grid.size();
    int m = grid[0].size();

    for (int k = 0;k < 4;k++)
    {
        int ni = i + directions[k].first;
        int nj = j + directions[k].second;

        if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && grid[ni][nj] == '.')
        {
            dfs(ni, nj, grid, vis);
        }
    }
}

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

    vector<vector<char>> grid(n, vector<char>(m, '-'));

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            cin >> grid[i][j];
        }
    }


    int ans = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                ans++;
                dfs(i, j, grid, vis);
            }
        }
    }

    cout << ans;
    // }
    return 0;
}