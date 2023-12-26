
#include<iostream>
using namespace std;
void swaping(int *k,int *l)
{
    *k=*k^*l;
    *l=*k^*l;
    *k=*k^*l;
}

void display(int *a, int n) {
   for(int i = 0; i<n; i++)
      cout << a[i] << " ";
   cout << endl;
}
void selectionSort(int *a, int n) {
   int i, j, imin;
   for(i = 0; i<n-1; i++) {
      imin = i;
      for(j = i+1; j<n; j++)
         if(a[j] < a[imin])
            imin = j;
         swaping(&a[i],&a[imin]);
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int a[n];
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> a[i];
   }
   cout << "Array before Sorting: ";
   display(a, n);
   selectionSort(a, n);
   cout << "Array after Sorting: ";
   display(a, n);
}
