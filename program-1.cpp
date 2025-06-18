#include <iostream>
#include <vector>
using namespace std;
class Categorizing
{
public:
    // Displaying The Array 
    void DisplayArray(vector<int> &array)
    {
        cout << endl
             << "🔦📊 Current Array Is :- ";
        for (int i = 0; i < array.size(); i++)
        {
            cout << array.at(i) << " ";
        }
        cout << endl;
    }

    //  🔁 Selection Sort Algorithm
    void SelectionSort(vector<int> &array, int start, int end)
    {
        int minimum;
        for (int i = 0; i < array.size(); i++)
        {
            minimum = i;
            for (int j = i + 1; j < array.size(); j++)
            {
                if (array[minimum] > array[j])
                {
                    minimum = j;
                }
                swap(array[i], array[minimum]);
            }
        }
        cout << endl
             << "✅ The Selection Sort Sucessfully Executed" << endl;
    }

    //  🔀 Merge helper for Merge Sort
    void Merge(vector<int> &array, int start, int mid, int end)
    {
        vector<int> temp;
        int i = start, j = mid + 1;

        while (i <= mid && j <= end)
        {
            if (array[i] < array[j])
            {
                temp.push_back(array[i++]);
            }
            else
            {
                temp.push_back(array[j++]);
            }
        }

        while (i <= mid)
        {
            temp.push_back(array[i++]);
        }

        while (j <= end)
        {
            temp.push_back(array[j++]);
        }

        for (int k = 0; k < temp.size(); k++)
        {
            array[start + k] = temp[k];
        }
    }

    // 🧠 Merge Sort Recursive Algorithm
    void MergeSort(vector<int> &array, int start, int end)
    {
        if (start >= end)
            return;

        int mid = start + (end - start) / 2;

        MergeSort(array, start, mid);
        MergeSort(array, mid + 1, end);
        Merge(array, start, mid, end);
    }

    // 🔍 Linear Search
    int LinearSearch(vector<int> &array, int target)
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

    // 🔍 Binary Search (Sorted Only)
    int BinarySearch(vector<int> &array, int target)
    {
        if (Sortchecker(array))
        {
            int start = 0;
            int end = array.size();

            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                if (array[mid] == target)
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
        else
        {
            return -2;
        }
    }

    // ☑️ Sort Checker To Check If The Array Is Sorted Or Not
    bool Sortchecker(vector<int> & array)
    {
        for (int i = 0; i < array.size(); i++)
        {
            for (int j = i + 1; j < array.size(); j++)
            { 
                if (array[i] > array[j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Categorizing obj;

    cout << endl
         << "🎯 Welcome To Algorithm Checker." << endl;

    int size, num, key, index;

    cout << "🔢 Enter The Number Of Elemnts You Want In The Array :- ";
    cin >> size;

    vector<int> array;

    cout << endl
         << "📩 Enter " << size << " Elements :- " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Array[" << i << "] :- ";
        cin >> num;
        array.push_back(num);
    }

    int choice;
    do
    {
        cout << endl
             << "========== Menu ==========" << endl;
        cout << endl
             << "1️⃣. Selection Sorting." << endl;
        cout << "2️⃣. Merge Sortng." << endl;
        cout << "3️⃣. Linear Search." << endl;
        cout << "4️⃣. Binary Search." << endl;
        cout << "5️⃣. Display." << endl;
        cout << "0️⃣. Exit The Program." << endl;

        cout << "📌Enter Your Choice :- ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << endl
                 << "👋Your Program Is Sucessfully Exucuted ----" << endl;
            cout << endl << "Press Enter To Exit....";
            cin.ignore();
            cin.get();
            break;

        case 1:
            obj.SelectionSort(array, 0, array.size() - 1);
            break;

        case 2:
            obj.MergeSort(array, 0, array.size() - 1);
            cout << endl
                 << "✅ Merge Sort Is Sucessfully Executed." << endl;
            break;

        case 3:
            obj.DisplayArray(array);
            cout << "🔎 Enter An Element Element To Search (Linear) :- ";
            cin >> key;

            index = obj.LinearSearch(array, key);
            
            if (index >= 0)
            {
                cout << endl
                     << "🎉 The Element " << key << " Is Founded At Index " << index;
            }
            else
            {
                cout << "❌ The Element " << key << " Is Not Avaible In The Given Array";
            }
            break;

        case 4:
            obj.DisplayArray(array);
            cout << endl
                 << "🗒️ Note :- " << endl
                 << "🔍 To Search In Binary The Array Must Be Sorted." << endl;

            cout << "🔎 Enter An Element To Search (Binary) :- ";
            cin >> key;

            index = obj.BinarySearch(array,key);

            if (index >= 0 && index < array.size())
            {
                cout << endl
                     << "🎊 The Element " << key << " Is Founded At Index " << index;
            }
            else if (index == -2)
            {
                cout << endl << "👎 The Array Is Not Sorted Please Sort It First." << endl;
            }
            else            
            {
                cout << "❌ The Element " << key << " Is Not Avaible In The Given Array";
            }
            break;

        case 5:
            obj.DisplayArray(array);
            break;

        default:
            cout << endl
                 << "⚠️ Invaild Option Please Try Again....!" << endl;
            break;
            
        }
    } while (choice != 0);

    return 0;
}
