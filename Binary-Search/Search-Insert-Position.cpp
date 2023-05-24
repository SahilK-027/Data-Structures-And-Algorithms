int searchInsert(vector<int> &arr, int t)
{
    int s = 0;
    int e = arr.size() - 1;
    int m = s + (e - s) / 2;
    int ans = 0;
    while (s <= e)
    {
        if (arr[m] == t)
        {
            return m;
        }
        else if (arr[m] < t)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
        m = s + (e - s) / 2;
    }
    return s;
}