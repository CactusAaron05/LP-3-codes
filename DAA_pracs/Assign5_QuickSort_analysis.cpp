//Analyze Quick Sort using deterministic and randomized variants. 
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Partition using the last element as pivot
int partitionArray(vector<int>& a, int low, int high, long long& comparisons) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

// 1. Deterministic Quick Sort
void quickSort(vector<int>& a, int low, int high, long long& comparisons) {
    if (low < high) {
        int p = partitionArray(a, low, high, comparisons);

        quickSort(a, low, p - 1, comparisons);
        quickSort(a, p + 1, high, comparisons);
    }
}

// 2. Randomized Quick Sort
void randomizedQuickSort(vector<int>& a, int low, int high, long long& comparisons) {
    if (low < high) {
        int randomIndex = low + rand() % (high - low + 1);

        // Move random pivot to the end
        swap(a[randomIndex], a[high]);

        int p = partitionArray(a, low, high, comparisons);

        randomizedQuickSort(a, low, p - 1, comparisons);
        randomizedQuickSort(a, p + 1, high, comparisons);
    }
}

// Display array
void display(vector<int>& a) {
    for (int x : a)
        cout << x << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size.\n";
        return 0;
    }

    vector<int> original(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> original[i];

    vector<int> a = original;
    vector<int> b = original;

    long long comparisons1 = 0;
    long long comparisons2 = 0;

    srand(static_cast<unsigned int>(time(0)));

    quickSort(a, 0, n - 1, comparisons1);
    randomizedQuickSort(b, 0, n - 1, comparisons2);

    cout << "\nDeterministic Quick Sort:\n";
    display(a);
    cout << "Comparisons: " << comparisons1 << endl;

    cout << "\nRandomized Quick Sort:\n";
    display(b);
    cout << "Comparisons: " << comparisons2 << endl;

    return 0;
}