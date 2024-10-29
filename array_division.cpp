#include <bits/stdc++.h>
#define int long long
using namespace std;
// k is showing number of required partitions
// bool isPossible(int mid , int k )
// {
//     int
// }

int32_t main()
{

    int n;

    cin >> n;

    vector<int> numbers;

    int k;
    cin >> k;

    for (int i = 0; i <= n - 1; i++)
    {

        int x;
        cin >> x;
        numbers.push_back(x);
    }

    int maximium = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maximium = max(maximium, numbers[i]);
    }

    long long low = maximium;

    long long high = 1e18; // 10^18

    long long maximiumSum = 1e18; //  this is the value i want to minimise

    while (low <= high)
    {

        long long mid = high + (low - high) / 2;

        int blocks = 1;

        long long sum = 0;

        for (int i = 0; i < n; i++)
        {

            if (sum + numbers[i] > mid)
            {
                sum = 0;
                blocks++;
            }

            sum = sum + numbers[i];
        }

        if (blocks > k)
        {
            low = mid + 1;
        }
        else
        {
            if (mid < maximiumSum)
            {
                maximiumSum = mid;
            }
            high = mid - 1;
        }
    }

    cout << maximiumSum << endl;
}

/*




        if (isPossible(mid , k))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1 ;


        }

    int maximium = INT_MIN;

    if (n % k == 0)
    {
        int firstIndex = 0;

        int secondIndex = k - 1;

        int sumCount = 0;
        while (secondIndex < n)
        {
            for (int i = firstIndex; i <= secondIndex; i++)
            {
                sumCount = sumCount + numbers[i];
            }
            maximium = max(maximium, sumCount);
            firstIndex = secondIndex + 1;
            secondIndex = (k - 1) + firstIndex;
        }

        cout << maximium;
    }
    else
    {

    }

*/