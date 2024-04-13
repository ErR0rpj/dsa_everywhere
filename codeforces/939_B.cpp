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
        set<int> s;
        int zero = n;
        int one = 0;
        int two = 0;
        for (int i = 0; i < n; i++)
        {
            int in;
            cin >> in;

            if (s.find(in) != s.end())
            {
                one--;
                two++;
            }
            else
            {
                one++;
                zero--;
            }
            s.insert(in);

            a.push_back(in);
        }

        int nturns = 2 * zero;
        int npoints = zero;

        int mturns = 2 * two;
        int mypoints = two;

        cout << mypoints << "\n";
    }
}