#include <iostream>
using namespace std;

// Function to create a new array that is twice the size of the argument array
int* doubleArraySize(int*& arr, int& size) {
    // Calculate new size
    int new_size = 2 * size;

    // Create a new array that is twice the size of the argument array
    int* new_arr = new int[new_size];

    // Copy contents of the argument array to the new array
    for (int i = 0; i < size; ++i) {
        new_arr[i] = arr[i];
    }

    // Initialize the remaining elements of the new array with 0
    for (int i = size; i < new_size; ++i) {
        new_arr[i] = 0;
    }

    // Update original array pointer and size
    delete[] arr; // Free memory of original array
    arr = new_arr; // Update pointer to new array
    size = new_size; // Update size of the array

    // Return pointer to the new array
    return new_arr;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter " << size << " elements for the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Call the function to double the size of the array
    int* new_arr = doubleArraySize(arr, size);

    // Output the original array
    cout << "Original array: ";
    for (int i = 0; i < size / 2; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Output the new array
    cout << "New array (twice the size): ";
    for (int i = 0; i < size; ++i) {
        cout << new_arr[i] << " ";
    }
    cout << endl;

    // Don't forget to delete the dynamically allocated arrays to free memory
    delete[] arr;
    delete[] new_arr;

    return 0;
}
