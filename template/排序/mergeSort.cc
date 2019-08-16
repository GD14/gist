
void merge(int a[], int l, int m, int r)
{
    int tmp[r - l + 1];
    int i = l, j = m + 1;
    int idx = 0;
    while (i < m && j < r)
        if (a[i] < a[j])
            tmp[idx++] = a[i++];
        else
            tmp[idx++] = a[j++];
    while (i < m)
        tmp[idx++] = a[i++];
    while (j < r)
        tmp[idx++] = a[j++];

    for (i = 0; i < idx; ++i)
        a[l + i] = tmp[i];
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}