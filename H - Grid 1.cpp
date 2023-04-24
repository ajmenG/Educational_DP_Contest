#include <bits/stdc++.h>
using namespace std;

int64_t n, m, tab[1007][1007], dp[1007][1007];
char a;
const int64_t MAX=1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            cin >> a;
            if(a=='.')
                tab[i][j]=1;
            else
                tab[i][j]=0;
        }
    }
    dp[1][1]=1;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (tab[i][j]==1)
                dp[i][j]= dp[i][j]%MAX + dp[i-1][j]%MAX + dp[i][j-1]%MAX;
            dp[i][j]%=MAX;
        }
    }

    cout << dp[n][m]%MAX;
    return 0;
}
