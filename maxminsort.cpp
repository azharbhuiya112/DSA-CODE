#include<iostream>



using namespace std;

void swaping(int *k,int *l)
{
    *k=*k^*l;
    *l=*k^*l;
    *k=*k^*l;
}

void minmaxselectionsort(int* a,int n)
{
    for(int i=0,j=n-1;i<j;i++,j--)
    {
        int minima=a[i];
        int maxxa=a[i];
        int min_index=i;
        int max_index=i;

        for(int k=i+1;k<=j;k++)
        {
            if(a[k]>maxxa)
            {
                maxxa=a[k];
                max_index=k;
            }
            else if(a[k]<minima)
            {
                minima=a[k];
                min_index=k;
            }
        }


        swap(a[i], a[min_index]);

        if(a[min_index]==maxxa) {
                swap(a[j], a[min_index]);

        }

        else
        swap(a[j], a[max_index]);
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

    minmaxselectionsort(a,n);
    cout<<"sorted array:";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
