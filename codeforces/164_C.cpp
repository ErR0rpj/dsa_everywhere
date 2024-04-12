#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string x;
        string y;

        cin >> x;
        cin >> y;

        string ansx = "";
        string ansy = "";

        bool foundfirst = false;

        for (int i = 0; i < x.length(); i++)
        {
            char xchar = x[i];
            char ychar = y[i];

            int xint = int(xchar) - 48;
            int yint = int(ychar) - 48;

            // cout << xint << " " << yint << "\n";

            if (foundfirst)
            {
                ansx += to_string(min(xint, yint));
                ansy += to_string(max(xint, yint));
            }
            else if (yint > xint || xint > yint)
            {
                ansx += to_string(max(xint, yint));
                ansy += to_string(min(xint, yint));
                foundfirst = true;
            }
            else
            {
                ansx += to_string(xint);
                ansy += to_string(yint);
            }
        }

        cout << ansx << "\n";
        cout << ansy << "\n";
    }
}