#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        if (m == 1)
        {
            cout << "NO\n";
            continue;
        }

        if (n <= m)
        {
            if (k >= n - 1)
            {
                cout << "NO\n";
                continue;
            }
            else
            {
                cout << "YES\n";
                continue;
            }
        }

        else
        {
            int ans = (m - 1) * (n / m);
            if (n % m > 0)
            {
                ans += (n % m) - 1;
            }

            if (k >= ans)
            {
                cout << "NO\n";
                continue;
            }
            else
            {
                cout << "YES\n";
                continue;
            }
        }
    }
}