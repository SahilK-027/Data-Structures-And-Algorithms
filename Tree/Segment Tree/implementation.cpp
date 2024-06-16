#include <bits/stdc++.h>
using namespace std;

class SegTree
{
public:
    int len;
    vector<int> t;

    SegTree(int l)
    {
        this->len = l;
        t.resize(4 * this->len);
    }

    // Time O(n)
    // Space O(4n + height(t))
    void build(vector<int> arr, int tl, int tr, int v)
    {
        // Base case
        // If reached leaf node
        if (tr == tl)
        {
            t[v] = arr[tr];
            return;
        }

        int tm = tl + (tr - tl) / 2;
        build(arr, tl, tm, 2 * v);
        build(arr, tm + 1, tr, 2 * v + 1);

        t[v] = t[2 * v] + t[2 * v + 1];
    }

    // Time O(log n)
    // Space O(height(t))
    int query(int v, int tl, int tr, int l, int r)
    {
        if (r < tl || l > tr)
            return 0; // No overlap
        if (l <= tl && tr <= r)
            return t[v]; // Complete overlap

        // Partial overlap
        int tm = tl + (tr - tl) / 2;

        int leftAns = query(2 * v, tl, tm, l, r);
        int rightAns = query(2 * v + 1, tm + 1, tr, l, r);

        return leftAns + rightAns;
    }

    void pointUpdate(int v, int tl, int tr, int val, int idx)
    {
        if (tl == idx && tr == idx)
        {
            t[v] = val;
            return;
        }
        if (idx < tl || idx > tr)
        {
            return; // Identity transformation
        }

        int tm = tl + (tr - tl) / 2;
        pointUpdate(2 * v, tl, tm, val, idx);
        pointUpdate(2 * v + 1, tm + 1, tr, val, idx);

        t[v] = t[2 * v] + t[2 * v + 1];
    }

    // Overriden func
    void build(vector<int> &a)
    {
        build(a, 0, this->len - 1, 1);
    }

    int query(int l, int r)
    {
        return query(1, 0, this->len - 1, l, r);
    }

    void pointUpdate(int val, int idx)
    {
        pointUpdate(1, 0, this->len - 1, val, idx);
    }
};

int main()
{
    int n = 8;
    vector<int> arr = {1, 2, 1, 4, 2, 3, 1, 1};
    SegTree *ST = new SegTree(n);
    ST->build(arr);

    // Range query
    int sum = ST->query(0, 7);
    cout << "FULL TREE SUM: " << sum << endl;
    sum = ST->query(1, 5);
    cout << "query(1, 5): " << sum << endl;

    ST->pointUpdate(10, 2);
    sum = ST->query(1, 5);
    cout << "query(1, 5): " << sum << endl;
    return 0;
}