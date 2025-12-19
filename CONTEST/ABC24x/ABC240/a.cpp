#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;

    bool ok = false;

    if(abs(a-b) == 1)
    {
        ok = true;
    }
    else
    {
        if(a == 10 || b == 10)
        {
            if(a % 9 == b % 9 )
            {
                ok = true;
            }
        }
    }

    if(ok)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}