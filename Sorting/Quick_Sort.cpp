#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout<<"debugging - "<<x<<endl;
#define ull unsigned long long
#define ll long long


int parti(int A[],int left,int right)
{
  int x = A[right];
  int i = left -1;

  for(int j=left; j<right; j++)
  {
     if(A[j] < x)
     {
       i++;
       swap(A[i], A[j]);
     }
   }
   swap(A[i+1], A[right]);
   return i+1;
}

void quick(int A[], int left, int right)
{
    if(left < right)
    {
      int q = parti(A, left, right);
      cout<<"q "<<q<<endl;
      quick(A, left, q-1);
      quick(A, q+1, right);
    }
}

int quickParti(int A[],int left,int right)
{
    int p = rand() % right + left;
    swap(A[p], A[right]);
    return parti(A, left, right);
}

void randQuick(int A[], int left, int right)
{
    if(left < right)
    {
      int q = quickParti(A, left, right);
      cout<<"q "<<q<<endl;
      quick(A, left, q-1);
      quick(A, q+1, right);
    }
}



int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5};

    randQuick(arr, 1, 5);

    for(int i=1; i<6; i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}
