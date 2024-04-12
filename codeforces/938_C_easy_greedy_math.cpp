#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;
        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }

        long long half1 = 0;
        long long half2 = 0;
        if (k % 2 == 1)
        {
            half2 = (k - 1) / 2;
            half1 = half2 + 1;
        }
        else
        {
            half2 = k / 2;
            half1 = half2;
        }

        int ans = 0;
        for (int i = 0; i < n && half1 > 0; i++)
        {
            if (v[i] > half1)
            {
                v[i] -= half1;
                half1 = 0;
            }
            else
            {
                half1 -= v[i];
                v[i] = 0;
                ans++;
            }
        }

        for (int i = n - 1; i >= 0 && half2 > 0; i--)
        {
            if (v[i] == 0)
            {
                break;
            }
            if (v[i] > half2)
            {
                v[i] -= half2;
                half2 = 0;
            }
            else
            {
                half2 -= v[i];
                v[i] = 0;
                ans++;
            }
        }

        cout << ans << "\n";
    }
}