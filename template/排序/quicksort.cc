#include <algorithm>

//version 1 
void quickSort(int *a, int l, int r)
{
    int i = l;
    int j = r;
    int mid = a[(i + j) / 2];

    while (i <= j)
    {
        while (a[i] < mid) ++i;
        while (a[j] > mid) --j;
        if (i <= j)
        {
            swap(a[i], a[j]);
            ++i;    --j;
        }
    }

    if(i<r) quickSort(a,i,r);
    if(l<j) quickSort(a,l,j);
}



// version 2
int partition(int *a,int l,int r)
{
    int pivot=a[r];
    int i=(l-1);

    for(int j=l;j<=r-1;j++)
    {
       if (a[j]<=pivot) 
       {
           i++;
           swap(a[i],a[j]);
       }
    }
    swap(a[i+1],a[r]);
    return i+1;
}
void quickSort2(int *a,int l,int r)
{
    if(l<r){
        int pos=partition(a,l,r);
        quickSort2(a,l,pos-1);
        quickSort2(a,pos+1,r);
    }
}
