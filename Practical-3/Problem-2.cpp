#include <iostream>
using namespace std;


int findMax(int arr[], int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}


void countingSort(int arr[], int n)
{
    int max = findMax(arr, n);

    int count[max + 1] = {0};


    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    
    int index = 0;

    for (int i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}

int main()
{
    int n;

    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements(0,1,2): ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    countingSort(arr, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}