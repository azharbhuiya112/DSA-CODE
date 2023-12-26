#include<iostream>


using namespace std;
void swapping(int *k,int *l)
{
    *k=*k^*l;
    *l=*k^*l;
    *k=*k^*l;
}
void   insertionsorting(int *arr, int n)
{
    for(int i=1; i<n; i++)
    {
        int j=i-1;
        while(j>=0&&arr[j+1]<arr[j])
        {
            swap(arr[j],arr[j+1]);
            j--;
        }
    }
}

int main()
{
    int n;
    cout<<"enter array size:";
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    insertionsorting(a,n);
    cout<<"sorted array";
    for(int i=0;i<n;i++) cout<<a[i];

    return 0;
}

