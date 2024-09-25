#include <iostream>
#include <vector>
#include <random>
using namespace std;

void random_num(vector<double>& arr, int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-1000, 1000);

    arr.resize(n);

    for (int i = 0; i < n; ++i) {
        arr[i] = dis(gen);
    }
}

void Merge_sort(vector<double>& arr, int left, int mid, int right) {
    int size_1 = mid - left + 1;
    int size_2 = right - mid;

    vector<double> left_vector(size_1);
    vector<double> right_vector(size_2);

    for (int i = 0; i < size_1; ++i) {
        left_vector[i] = arr[left + i];
    }
    for (int i = 0; i < size_2; ++i) {
        right_vector[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < size_1 && j < size_2) {
        if (left_vector[i] <= right_vector[j]) {
            arr[k] = left_vector[i];
            i++;
        }
        else {
            arr[k] = right_vector[j];
            j++;
        }
        k++;
    }

    while (i < size_1) {
        arr[k] = left_vector[i];
        i++;
        k++;
    }

    while (j < size_2) {
        arr[k] = right_vector[j];
        j++;
        k++;
    }
}

void recursion_Mergesort(vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        recursion_Mergesort(arr, left, mid);

        recursion_Mergesort(arr, mid + 1, right);

        Merge_sort(arr, left, mid, right);
    }
}

int Binary_search(vector<double>& arr, double search_val) {
    int left = 0, right = arr.size() - 1;
    bool found = false;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == search_val) {
            cout << "Search number index: " << mid << "\n";
            found = true;
            break;
        }
        if (search_val > arr[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    if (!found) {
        cout << "Target not found in array" << "\n";
        return -1;
    }

    return 0;
}

int main() {
    double search_val;
    vector<double> arr;
    int n;

    cout << "n = ";
    cin >> n;

    random_num(arr, n);

    int left = 0;
    int right = n - 1;

    recursion_Mergesort(arr, left, right);
    
    cout << "Sorted array: ";
    for (const double& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Search number: ";
    cin >> search_val;

    Binary_search(arr, search_val);

    return 0;
}