#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <time.h>
#include<ctime>
#include<chrono>
#include <iomanip>

using namespace std;

class Sorter
{
public:
    virtual void Sort(int* array,int size) = 0;
};
class SelectionSort :public Sorter
{
public:
    void Sort(int* array, int size) {
        for (int step = 0; step < size - 1; step++) {
            int min_idx = step;
            for (int i = step + 1; i < size; i++) {

                if (array[i] < array[min_idx])
                    min_idx = i;
            }

            // put min at the correct position
            swap(array[min_idx], array[step]);
        }
    }
};
class QuickSort:public Sorter
{
public:
    int partition(int* array, int low, int high) {

        // select the middle element as pivot
        int pivot = array[(low + high) / 2];

        // pointer for least element
        int i = low;
        // pointer for greater element
        int j = high;

        while (i <= j) {
            while (array[i] < pivot)
                i++;

            while (array[j] > pivot)
                j--;

            if (i <= j) {
                swap(array[i++], array[j--]);
            }
        };
        return i;
    }

    void quickSort(int* array, int low, int high) {
        if (low < high) {

            // find the pivot element
            int pi = partition(array, low, high);

            // recursive call on the left of pivot
            quickSort(array, low, pi - 1);

            // recursive call on the right of pivot
            quickSort(array, pi, high);
        }
    }
    void Sort(int* array, int size)
    {
        quickSort(array, 0, size-1);
    }
};

class Testbed
{
public:
    int * GenerateRandomList(int min, int max, int size)
    {
        int* array = new int[size];
        int i = 0;
        srand(time(0));
        while (size--)
        {
            int num = min+( rand() % (max - min + 1));
            array[i++] = num;

        }
        return array;
    }
    int * GenerateReverseOrderedList(int min, int max, int size)
    {
        int *arr = GenerateRandomList(min, max, size);
        for (int i = 0; i < size / 2; i++) {
            swap(arr[i], arr[size - i - 1]);

        }
        return arr;

    }
    double RunOnce(Sorter *sort, int* data, int size)
    {

        clock_t start, end;
        double totalTime=0;
        start = clock();
        sort->Sort(data, size);
        end = clock();
        //cout << "start" << start << " " << endl;
        //cout <<"end" << end << " " << endl;

        totalTime = ((double)(end - start)) / CLOCKS_PER_SEC;
        return totalTime;

    }

    double RunAndAverage(Sorter* sort, string type, int min, int max, int size, int sets_num)
    {
        double times = 0;
        for (int i = 0; i < sets_num; i++)
        {
            int* arr;
            if (type == "Random")
                arr = GenerateRandomList(min, max, size);
            else
                arr = GenerateReverseOrderedList(min, max, size);

            times += RunOnce(sort, arr, size);
        }
        return times / (double)sets_num;
    }


    void RunExperient(Sorter *sort, string type,int  min,int  max,int  min_val, int max_val, int sets_num, int step)
    {

        cout << "size" << setw(10) << "Averge" << endl;
        for (int i = min_val; i <= max_val; i+=step) {
            double avg = 0;
            avg=RunAndAverage(sort, type, min, max, i, sets_num);
            cout << i << setw(10) << avg << endl;
        }

    }
};
int main()
{
    Testbed ob;
    Sorter* s1 = new QuickSort;
    Sorter* s2 = new SelectionSort;

    cout << "QuickSort (Reverse Case)" << endl;
    ob.RunExperient(s1, "Reverse", 1, 1000000, 1000,10000,100,1000);
    cout << endl;

    cout << "QuickSort (Random Case)" << endl;
    ob.RunExperient(s1, "Random", 1, 1000000, 1000, 10000, 100, 1000);
    cout << endl;


    cout << "SelectionSort (Reverse Case)" << endl;
    ob.RunExperient(s2, "Reverse", 1, 1000000, 1000, 10000, 100, 1000);
    cout << endl;

    cout << "SelectionSort (Random Case)" << endl;
    ob.RunExperient(s2, "Random", 1, 1000000, 1000, 10000, 100, 1000);
    cout << endl;


    return 0;
}
