// C++ program to implement min max selection
// sort.
#include <iostream>
using namespace std;




void swapping(int *k,int *l)
{
    *k=*k^*l;
    *l=*k^*l;
    *k=*k^*l;
}

void minMaxSelectionSort(int* arr, int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int min = arr[i], max = arr[i];
        int min_i = i, max_i = i;
        for (int k = i; k <= j; k++)  {
            if (arr[k] > max) {
                max = arr[k];
                max_i = k;
            } else if (arr[k] < min) {
                min = arr[k];
                min_i = k;
            }
        }

        swapping(&arr[i], &arr[min_i]);


        if (arr[min_i] == max)
           swapping(&arr[j], &arr[min_i]);
        else
            swapping(&arr[j], &arr[max_i]);
    }
}


int main()
{
     int n;
    cout<<"enter array size:";
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    minMaxSelectionSort(arr,n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
