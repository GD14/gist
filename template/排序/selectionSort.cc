

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < i; ++i)
            if (a[i] > a[j])
                swap(a[i], a[j]);
}