#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        int ans = 0;
        int multiplier = 1;

        if (b > a * 2)
        {
            b = a;
            multiplier = 2;
        }

        while (n > 0)
        {
            if (n >= 2)
            {
                n = n - 2;

                ans += multiplier * b;
            }
            else
            {
                n = n - 1;
                ans += a;
            }
        }

        cout << ans << "\n";
    }
}