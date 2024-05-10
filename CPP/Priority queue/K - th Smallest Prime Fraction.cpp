#include<bits/stdc++.h>
using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
{
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({(double)arr[i] / arr.back(), {i, arr.size() - 1}});
    }

    while (--k)
    {
        auto [frac, indexes] = pq.top();
        pq.pop();
        int i = indexes.first;
        int j = indexes.second;
        if (j - 1 > i)
        {
            pq.push({(double)arr[i] / arr[j - 1], {i, j - 1}});
        }
    }

    auto [frac, indexes] = pq.top();
    return {arr[indexes.first], arr[indexes.second]};
}

int main()
{
    vector<int> arr = {1, 2, 3, 5};
    int k = 3;
    vector<int> result = kthSmallestPrimeFraction(arr, k);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}

