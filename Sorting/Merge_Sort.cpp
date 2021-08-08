    #include <bits/stdc++.h>
using namespace std;

void merge(int left, int right, int arr[])
{
    int mid = (left+right)/2;
    int arr1[mid-left+1];
    int arr2[right-mid];

    for(int i=left, oogabooga=0; i<=mid; i++, oogabooga++)
    {
        arr1[oogabooga] = arr[i];
    }

    for(int i=mid+1, oogabooga=0; i<=right; i++, oogabooga++)
    {
        arr2[oogabooga] = arr[i];
    }

    int indexA=0, indexB=0, indexCurr=left;
    while(indexCurr <= right)
    {
        if (indexA > mid-left)
        {
            arr[indexCurr] = arr2[indexB];
            indexB++;
            indexCurr++;
        }
        else if (indexB >= right-mid){

            arr[indexCurr] = arr1[indexA];
            indexA++;
            indexCurr++;
        }
        else if(arr1[indexA] <= arr2[indexB])
        {
            arr[indexCurr] = arr1[indexA];
            indexA++;
            indexCurr++;
        }
        else if (arr1[indexA] > arr2[indexB]){
            arr[indexCurr] = arr2[indexB];
            indexB++;
            indexCurr++;
        }

    }
}

void divideAndSort(int left, int right, int arr[])
{
    if (left >= right) return;

    int mid = (left+right)/2;

    divideAndSort(left, mid, arr);
    divideAndSort(mid+1, right, arr);
    merge(left, right, arr);
}




int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i] = n-i;
    }

    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    divideAndSort(0, n-1, arr);

    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;

}
