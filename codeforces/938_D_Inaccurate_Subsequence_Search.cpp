// Learnings
//  I was first creating an array of length 10^6 and initializing it with 0. I thought that it will help query in O(1). But actually creating
//  that array in every testcase was much more time consuming and I got a TLE. Finally, I tried using Map and stored only the counts of the
// ones which are required. And this helped solved the problem even thought the query was of O(logn)

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

        vector<int> a;
        vector<int> b;
        map<int, int> isb;
        map<int, int> ccount;

        for (int i = 0; i < n; i++)
        {
            int in;
            cin >> in;
            a.push_back(in);
        }
        for (int i = 0; i < m; i++)
        {
            int in;
            cin >> in;
            b.push_back(in);
            if (isb.find(in) == isb.end())
            {
                isb[in] = 1;
            }
            else
            {
                isb[in]++;
            }
        }

        int first = 0;
        int last = m;
        int ans = 0;
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            if (isb.find(a[i]) != isb.end() && isb[a[i]] > 0)
            {
                if (ccount.find(a[i]) == ccount.end())
                {
                    ccount[a[i]] = 1;
                }
                else
                {
                    ccount[a[i]]++;
                }

                if (ccount[a[i]] <= isb[a[i]])
                {
                    count++;
                }
            }
        }
        if (count >= k)
        {
            ans++;
        }

        while (last < n)
        {
            if (isb.find(a[last]) != isb.end() && isb[a[last]] > 0)
            {
                if (ccount.find(a[last]) == ccount.end())
                {
                    ccount[a[last]] = 1;
                }
                else
                {
                    ccount[a[last]]++;
                }

                if (ccount[a[last]] <= isb[a[last]])
                {
                    count++;
                }
            }

            if (isb.find(a[first]) != isb.end() && isb[a[first]] > 0)
            {

                ccount[a[first]]--;
                if (ccount[a[first]] < isb[a[first]])
                {
                    count--;
                }
            }
            if (count >= k)
            {
                ans++;
            }

            last++;
            first++;
        }

        cout << ans << "\n";
    }
}