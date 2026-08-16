#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSorting(int No[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (No[j] > No[j + 1])
            {
                int temp = No[j];
                No[j] = No[j + 1];
                No[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort
void insertionSorting(int No[], int n)
{
    int key, j;

    for (int i = 1; i < n; i++)
    {
        key = No[i];
        j = i - 1;

        while (j >= 0 && No[j] > key)
        {
            No[j + 1] = No[j];
            j--;
        }

        No[j + 1] = key;
    }
}

void selectionSorting(int No[],int n){
 
    for(int i=0; i<n-1; i++){
        int minIndex = i;

        for(int j=i+1; j<n; j++)
        {
            if(No[j] < No[minIndex]){
                minIndex = j;
            }
        }

        int temp = No[i];
        No[i] = No[minIndex];
        No[minIndex] = temp;

    }
}

int main()
{
    int n;

    cout << "Enter Total number of student answer sheet: " << endl;
    cin >> n;

    int No[n];

    cout << "Enter answer sheet number which is written on answer-sheet: ";

    for (int i = 0; i < n; i++)
    {
        cin >> No[i];
    }

    bubbleSorting(No, n);

    cout << "Arranged Student Answer Sheet (Bubble Sorting): ";

    for (int i = 0; i < n; i++)
    {
        cout << No[i] << " ";
    }

    cout << endl;

    insertionSorting(No, n);

    cout << "Arranged Student Answer Sheet (Insertion Sorting): ";

    for (int i = 0; i < n; i++)
    {
        cout << No[i] << " ";
    }
     cout << endl;

    selectionSorting(No,n);
    cout<<"Arrenged Student Answer Sheet(Selection sorting):";

    for(int i=0; i<n; i++)
    {
        cout<<No[i]<<" ";
    }
     cout << endl;

    return 0;
}