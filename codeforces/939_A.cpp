#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int k, q;
        cin >> k >> q;

        vector<int> a;
        vector<int> n;

        for (int i = 0; i < k; i++)
        {
            int in;
            cin >> in;

            a.push_back(in);
        }

        for (int i = 0; i < q; i++)
        {
            int in;
            cin >> in;

            n.push_back(in);
        }

        vector<int> ans;

        for (int i = 0; i < q; i++)
        {
            int now = n[i];
            int j = 0;

            while (j < k && now >= a[j])
            {
                while (j < k && now >= a[j])
                {
                    now--;
                    j++;
                }
                j = 0;
            }

            ans.push_back(now);
        }

        for (int i = 0; i < q; i++)
        {

            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}