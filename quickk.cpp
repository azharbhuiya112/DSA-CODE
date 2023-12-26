#include<bits/stdc++.h>
using namespace std;

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}



int Partition(int *arr, int low, int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;

    while(j>=i)
    {
        while(arr[i]<pivot) {i++;}
        while(arr[j]>pivot) {j--;}
        if(j>i){swap(arr[i],arr[j]); }
        else break;
    }
    swap(arr[j],arr[low]);
    return j;
}

void Quick_sort(int *arr, int low, int high)
{
    if(high>low)
    {
        int pi=Partition(arr,low,high);
        Quick_sort(arr,low,pi-1);
        Quick_sort(arr,pi+1,high);
    }
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    QuickSort(a,0,n);

    for(int i=0; i<n; i++)
    {
        cout<<" "<<a[i];
    }
    return 0;

}

