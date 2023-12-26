#include<iostream>


using namespace std;





void swapping(int *k,int *l)
{
    *k=*k^*l;
    *l=*k^*l;
    *k=*k^*l;
}

void bubbleSort(int *a , int n){
    for(int i = 0 ; i < n-1 ; i++){

        for(int j = 0 ; j < n - i - 1 ; j++){

            if(a[j] > a[j+1]) swapping(&a[j] , &a[j+1]) ;
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

    bubbleSort(a,n);
    cout<<"sorted array:";
    for(int i=0;i<n;i++) cout<<a[i];


    return 0;
}
