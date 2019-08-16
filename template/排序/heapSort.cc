void heapDown(int a[], int len, int i)
{
    assert(i >= 0);
    int k = i * 2 + 1;
    while (k < len)
    {
        if (k + 1 < len && a[k] < a[k + 1])
            k = k + 1;
        if (a[i] < a[k])
        {
            swap(a[i], a[k]);
            i = k;
            k = k * 2 + 1;
        }
    }
}

void heapSort(int a[], int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
        heapDown(a, n, i);
    for (int i = n - 1; i > 0; --i)
    {
        swap(a[0], a[i]);
        heapDown(a, i, 0);
    }
}