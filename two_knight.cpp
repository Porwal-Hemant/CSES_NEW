#include <iostream>
#include <vector>
#define int long long
using namespace std;

int32_t main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            int totalWays = (i * i) * (i * i - 1) / 2;

            int numberOfWaysRejected = 4 * (i - 1) * (i - 2);

            cout << totalWays - numberOfWaysRejected << endl;
        }
    }

    return 0;
}
