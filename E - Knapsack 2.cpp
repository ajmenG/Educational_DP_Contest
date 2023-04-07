#include <bits/stdc++.h>
using namespace std;

const int64_t CENA=1e5, INF=1e9+9;
int64_t n, w, maxi, weight[105], value[105], dp[CENA+5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin >> n >> w;
    for (int i=1; i<=n; i++)
    {
        cin >> weight[i] >> value[i];
    }


    dp[0] = 0;
    for (int i=1; i<=CENA; i++)
    {
        dp[i]=INF;
    }

    // ustawiam dp[od 1 do CENA] na infinity bo bede minowac wage
    // dla kazdego przedmiotu
    // ide po kolei od maksymalnej ceny do ceny przedmiotu
    // do szufladki o wartosci mojego przedmiotu lub do nie pustej proboje dodac moja wartosc i sprawdzic czy uzyskalem nizsza wage
    // kazda szufladka okresla minimalna wage do osiagniecia danej ceny


    for (int i=1; i<=n; i++)
    {
        for (int j=100000; j>=value[i]; j--)
        {
            if (dp[j-value[i]] != INF || j-value[i] == 0)
            {
                dp[j] = min(dp[j-value[i]]+weight[i], dp[j]);
                if (maxi <= j && dp[j] <= w)
                {
                    maxi = j;
                }
            }
        }
    }

    cout << maxi;

    return 0;
}
