#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

template <class dataType>
int binarySearch (dataType *arr , int sz , int first , int last , dataType x)
{
    if (last < 0  )
        return 0 ;
    int mid = (first+last)/2 ;
    if (arr[mid] >= x && arr[mid-1] <= x)
        return mid ;
    else if (arr[mid] > x)
        binarySearch(arr, sz, first , mid-1 , x) ;
    else
        binarySearch(arr, sz, mid+1 , last , x) ;

}

template <class dataType>
void insertionSort2 (dataType *arr , int sz )
{
    for (int i=1 ; i<sz ; i++)
    {
        dataType temp =arr[i] ;
        int q= binarySearch(arr , sz, 0 , i, temp) ;
        for (int j=i ; j>q ; j--)
                arr[j]=arr[j-1] ;

        arr[q] = temp ;
    }
}
template <class dataType>
void insertionSort (dataType *arr , int sz )
{
    for (int i=1 ; i<sz ; i++)
    {
        dataType temp =arr[i] ;
        int j=i ;
        for ( ; j>0 && temp<arr[j-1] ; j--)
                arr[j]=arr[j-1] ;

        arr[j] = temp ;
    }
}

int main()
{
    const int sz = 100000;
    double time_used , advanced_time_used ;
    clock_t start, stop;
    int arr[sz] , arr2[sz] ;
    for (int j=0 ; j<sz ;j++)
        arr[j]=arr2[j]=rand()%10000 ;

    start = clock() ;
    insertionSort(arr, sz) ;
    stop = clock() ;
    time_used =(double) (stop-start)/CLOCKS_PER_SEC;

    start = clock() ;
    insertionSort2(arr2,sz) ;
    stop = clock() ;
    advanced_time_used = (double) (stop-start)/CLOCKS_PER_SEC;

    cout << "time taken by sequential search = " << time_used << " second(s)\n" ;
    cout << "time taken by binary search =     " << advanced_time_used << " second(s)\n" ;

    return 0;
}
