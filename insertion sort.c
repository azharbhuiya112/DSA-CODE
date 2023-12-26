#include<iostream>


using namespace std;
void swapping(int *k,int *l)
{
    *k=*k^*l;
    *l=*k^*l;
    *k=*k^*l;
}
void insertionsorting(int *a,int n)
{
   for(int i=1;i<n;i++)
   {
       int current=a[i];
       j=i-1;
       while(a[j]>current && j>=0)
       {
           swapping(&a[j+1],&a[j]);
           j--;
       }
   }

}

int main()
{
    int n;
    cout<<"enter array size";
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
