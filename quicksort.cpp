#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int static a[1000000];
int counter = 0;
int partions(int a[], int low, int high)
{
    int key = a[low], tmp;
    while (low < high)
    {
        while (low < high && a[high] >= key)
        {
            --high;
            counter++;
        }
        tmp = a[low];
        a[low] = a[high];
        a[high] = tmp;
        counter++;
        while (low < high && a[low] <= key) 
        {
            ++low;
            counter++;
        }   
        tmp = a[high];
        a[high] = a[low];
        a[low] = tmp;
        counter++;
    }
    a[low] = key;
    return low;
}
void qsort(int a[], int low, int high)
{
    int k;
    if (low < high)
    {
        k = partions(a, low, high);
        qsort(a, low, k - 1);
        qsort(a, k + 1, high);
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    int n = 1000000;
    //scanf("%d", &n);
    for(int k=0;k<100;k++)
    {for (int i = 0;i < n;i++) 
    {
        scanf("%d", &a[i]);
    }
    qsort(a, 0, n - 1);
    // for (int i = 0;i < n;++i) 
    // {
    //     printf("%d", a[i]);
    //     printf(" ");
    // }
    printf("%d\n", counter);
    counter = 0;
    }
    return 0;
}