#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; i++)
        {
            int in;
            cin >> in;
            a.push_back(in);
        }

        int v = 0;
        int ans = INT_MAX;
        int boss = a[0];

        for (int i = 0; i < n; i++)
        {
            if (a[i] == boss)
            {
                v++;
            }
            else
            {
                ans = min(ans, v);
                v = 0;
            }
        }

        ans = min(ans, v);

        if (v == n)
        {
            ans = -1;
        }

        cout << ans << "\n";
    }
}