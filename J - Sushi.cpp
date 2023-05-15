/// https://atcoder.jp/contests/dp/tasks/dp_j

#include <bits/stdc++.h>
using namespace std;

long double dp[305][305][305];
int n, ile[5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a;

    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a;
        ile[a]++;
    }

    dp[0][0][0] = 0;
    for (int trojki = 0; trojki <= n; trojki++)
    {
        for (int dwojki = 0; dwojki <= n; dwojki++)
        {
            for (int jedynki = 0; jedynki <= n; jedynki++)
            {
                int zera = n - trojki - dwojki - jedynki;

                if (trojki+dwojki+jedynki > n || zera == n)
                {
                    continue;
                }

                long double pom = 1;

                if (trojki) pom += dp[trojki-1][dwojki+1][jedynki] * ((long double) trojki / n);
                if (dwojki) pom += dp[trojki][dwojki-1][jedynki+1] * ((long double) dwojki / n);
                if (jedynki) pom += dp[trojki][dwojki][jedynki-1] * ((long double) jedynki / n);

                dp[trojki][dwojki][jedynki] = pom / (1 - ((long double) zera / n));
            }
        }
    }

    cout << fixed << setprecision(15) << dp[ile[3]][ile[2]][ile[1]] << '\n';

    return 0;
}

