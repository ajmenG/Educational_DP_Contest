#include <bits/stdc++.h>
using namespace std;
int n, m, maxi, dp[100005], vis[100005];
vector<int> G[100005];

int dfs(int v)
{
    if (dp[v]!=-1)
        return dp[v];

    int pom=0, maxpom=0;;
    for (auto h : G[v])
    {
       pom = dfs(h)+1;
       maxpom = max(maxpom, pom);
    }
    dp[v]=maxpom;
    return maxpom;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;

    cin >> n >> m;
    for (int i=1; i<=m; i++)
    {
        cin >> a >> b;
        G[a].push_back(b);
    }
    for (int i=1; i<=n; i++)
    {
        dp[i]=-1;
    }

    for (int i=1; i<=n; i++)
    {
        maxi = max(dfs(i), maxi);
    }
    cout << maxi;
    return 0;
}

