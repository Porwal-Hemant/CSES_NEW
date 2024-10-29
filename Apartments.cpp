#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main()
{

    int n;

    cin >> n; // number of applicants for the desired apartments

    int m;
    cin >> m; // number of apartments

    int k;
    cin >> k; // maximium allowed difference

    vector<int> desiredApartments;

    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;

        desiredApartments.push_back(x);
    }

    vector<int> apartments;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        apartments.push_back(x);
    }

    sort(apartments.begin(), apartments.end());
    sort(desiredApartments.begin(), desiredApartments.end());

    int firstIndex = 0;
    int secondIndex = 0;

    int count = 0;

    while (firstIndex < n && secondIndex < m)
    {
        int firstValue = desiredApartments[firstIndex] - k;
        int secondValue = desiredApartments[firstIndex] + k;

        if (secondValue < apartments[secondIndex])
        {
            firstIndex = firstIndex + 1;
            // no increment in secondindex
        }
        else if ((apartments[secondIndex] <= secondValue) && (apartments[secondIndex] >= firstValue))
        {
            count = count + 1;
            firstIndex = firstIndex + 1;
            secondIndex = secondIndex + 1;
        }
        else
        {
            secondIndex = secondIndex + 1;
        }
    }

    cout << count << endl;
}