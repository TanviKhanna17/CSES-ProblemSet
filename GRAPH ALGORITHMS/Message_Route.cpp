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

    vector<int> adj[n];
    vector<bool> vis(n, false);

    for (int i = 0;i < m;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> parent(n, -1);
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    parent[0] = -1;

    pq.push(0);

    while (!pq.empty())
    {
        int node = pq.top();
        pq.pop();

        for (auto it : adj[node])
        {
            int childNode = it;

            if (dist[node] + 1 < dist[childNode])
            {
                dist[childNode] = dist[node] + 1;
                parent[childNode] = node;
                pq.push(childNode);
            }
        }
    }

    if (dist[n - 1] == INT_MAX)
    {
        cout << "IMPOSSIBLE \n";
    }
    else
    {
        vector<int> path;
        int node = n - 1;
        path.push_back(n - 1);
        while (parent[node] != -1)
        {
            path.push_back(parent[node]);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << '\n';
        for (auto it : path)
        {
            cout << it + 1 << " ";
        }
        cout << '\n';
    }

}