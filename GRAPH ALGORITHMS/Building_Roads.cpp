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

void dfs(int node, vector<int> adj[], vector<bool>& vis)
{
    vis[node] = true;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis);
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

    vector<int> adj[n];
    vector<bool> vis(n, false);

    for (int i = 0;i < m;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    int connectedComponents = 0;
    vector<int> toBeConn;
    for (int i = 0;i < n;i++)
    {
        if (!vis[i])
        {
            connectedComponents++;
            toBeConn.push_back(i);
            dfs(i, adj, vis);
        }
    }

    cout << connectedComponents - 1 << '\n';
    for (int i = 0;i < toBeConn.size() - 1;i++)
    {
        cout << toBeConn[i] + 1 << " " << toBeConn[i + 1] + 1 << '\n';
    }

}