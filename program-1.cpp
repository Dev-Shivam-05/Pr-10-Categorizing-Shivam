#include <iostream>
#include <vector>
using namespace std;

void SelectionSort(vector<int> &array, int start, int end)
{
    int minimum;
    for (int i = 0; i < array.size() - 1; i++)
    {
        minimum = i;
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[minimum] > array[j])
            {
                minimum = j;
            }
            swap(array[minimum], array[i]);
        }
    }
}

void Merge(vector<int> &array, int start, int mid, int end)
{
    vector<int> temp;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (array[i] <= array[j])
        {
            temp.push_back(array[i]);
        }
        else
        {
            temp.push_back(array[j]);
        }
    }

    while (i <= mid)
    {
        temp.push_back(array[i]);
    }

    while (j <= end)
    {
        temp.push_back(array[j]);
    }

    for (int k = 0; k < temp.size(); k++)
    {
        array.at(start + k) = temp.at(k);
    }

}

void MergeSort(vector<int> &array, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    MergeSort(array, start, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, start, mid, end);
}

int LinearSearch(vector<int> &array,int target)
{
    for (int i = 0; i < array.size(); i++)
    {
        if (array.at(i) == target)
        {
            return i;
        }
    }
    return -1;
}

int BinarySearch(vector<int> &array,int target)
{
    int start = 0;
    int end = array.size();

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (mid == target)
        {
            return mid;
        }
        else if (target < mid)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }        
    }

    return -1;
}

void DisplayArray(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array.at(i) << " ";
    }
    cout << endl;
}

int main()
{
    int size;

    cout << "Enter The Size Of The Array :- ";
    cin >> size;

    vector<int> array;

    cout << endl << "Enter " << size << " Elements :- ";
    for (int i = 0; i < size; i++)
    {
        cout << "Array[" << i << "] :- ";
        cin >> array[i];
    }

    int choice;
    do
    {
        cout << endl << "==== Program's ====" << endl;
        cout << endl << "Press 1 To Perform Selection Sorting." << endl;
        cout << "Press 2 To Perform Merge Sortng." << endl;
        cout << "Press 3 To Perform Linear Search." << endl;
        cout << "Press 4 To Perform Binary Search." << endl;
        cout << "Press 5 To Perform Display." << endl;
        cout << "Press 0 To Exit The Program." << endl;

        cout << "Enter Your Choice :- ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << endl
                 << "---- Your Program Is Sucessfully Exucuted" << endl;
            break;

        case 1:
            SelectionSort(array,0,array.size()-1);
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        default:
            cout << endl
                 << "Wrong Choice....!" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}