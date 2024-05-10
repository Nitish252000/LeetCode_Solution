#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                   int k)
{
    vector<vector<int>> ans;

    int m = nums1.size();
    int n = nums2.size();

    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        minHeap;
//-------------This approach will give Memory Limit Exceeded---------
    /*for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            minHeap.push({nums1[i]+nums2[j], {nums1[i], nums2[j]}});
        }
    }

    while(k>0 && !minHeap.empty()){
        auto top = minHeap.top();
        minHeap.pop();
        ans.push_back({top.second.first, top.second.second});
        k--;
    }
    return ans;*/
//------------------------------------------------------------------
    for (int i = 0; i < m && i < k; i++)
    {
        minHeap.push({nums1[i] + nums2[0], {i, 0}});
    }

    while (k-- && !minHeap.empty())
    {
        auto top = minHeap.top();
        minHeap.pop();
        int i = top.second.first;
        int j = top.second.second;
        ans.push_back({nums1[i], nums2[j]});
        if (j + 1 < n)
        {
            minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
        }
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};

    int k = 3;
    vector<vector<int>> result = kSmallestPairs(nums1, nums2, k);

    cout << "[";
    for (int i = 0; i < result.size(); ++i)
    {
        cout << "[" << result[i][0] << ", " << result[i][1] << "]";
        if (i < result.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
    cout << endl;

    return 0;
}
