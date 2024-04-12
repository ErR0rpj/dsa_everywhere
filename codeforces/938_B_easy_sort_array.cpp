#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c, d;
        cin >> n >> c >> d;

        vector<int> given;
        int a = INT_MAX;

        for (int i = 0; i < n * n; i++)
        {
            int k;
            cin >> k;
            given.push_back(k);

            a = min(a, k);
        }
        sort(given.begin(), given.end());

        vector<int> created;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                given[(i * n) + j] -= a;
                int toAdd = i * c + j * d;
                created.push_back(toAdd);
            }
        }
        sort(created.begin(), created.end());

        string ans = "Yes";
        for (int i = 0; i < n * n; i++)
        {
            if (given[i] != created[i])
            {
                ans = "No";
                break;
            }
        }

        cout << ans << "\n";
    }
}