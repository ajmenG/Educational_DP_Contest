#include <bits/stdc++.h>
using namespace std;

int64_t n, w, maxi, weight[105], value[105], dp[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin >> n >> w;
    for (int i=1; i<=n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    // dla kazdego przedmiotu
    // ide po kolei po wagach mozliwych do osiagniecia od tylu (od waga max) do wagi danego przedmiotu
    // jezeli jestem w szufladce waga tego przedmiotu to dodaje do niej jego wartosc, lub jak jakas waga nie jest rowna zero to rowniez dodaje
    // w kazdej szufladce trzymam wtedy maksymalna wartosc dla danej wagi

    for (int i=1; i<=n; i++)
    {
        for (int j=w; j>=weight[i]; j--)
        {
            if (dp[j-weight[i]] != 0 || j-weight[i] == 0)
            {
                dp[j] = max(dp[j-weight[i]]+value[i], dp[j]);
                maxi = max(dp[j], maxi);
            }

        }
    }

    cout << maxi;

    return 0;
}
