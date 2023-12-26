#include<bits/stdc++.h>
using namespace std;

void mergeing(int arr[],int low, int mid, int high)
{

    int n1 = mid-low+1;
    int n2 = high - mid;

    int a[n1];
    int b[n2];

    for(int i =0; i<n1; i++)
    {
        a[i] = arr[low+i];
    }
    for(int i=0; i<n2; i++)
    {
        b[i] = arr[mid+1+i];
    }

    int i =0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(a[i] < b[j])
        {
            arr[k]=a[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k]=a[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr[k]=b[j];
        j++;
        k++;
    }

}


void mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);

        mergeing(arr,low,mid,high);
    }
}
void Print_Array(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[5]={5, 4, 2 ,8,1};
    mergeSort(arr,0,4);
    Print_Array(arr,5);
}
