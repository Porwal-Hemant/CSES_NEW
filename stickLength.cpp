#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int n;    // number of sticks
    cin >> n; // Taking input for number of elements

    vector<int> numbers;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        numbers.push_back(x);
    }

    sort(numbers.begin(), numbers.end());

    int number = numbers[n / 2];

    int count = 0;

    for (int i = 0; i < numbers.size(); i++)
    {
        count = count + abs(number - numbers[i]);
    }

    cout << count << endl;

    return 0;
}

