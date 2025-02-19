#include <iostream>
#include "Timer.hpp"

using namespace std;

void A(int arr[], int n) {
    int agg = 0;
    for (int i = 0; i < n; i++) {
        agg += arr[i];
    }

    cout << agg;
}

void B(int n) {
    int *arr = new int[n];
    cout << "Array Contains: ";

    //Array Loading
    for (int i = 0; i < n; i++) {
        arr[i] = i;

        //printing
        if (i != n-1) {
            cout << arr[i] << ", ";
        } else {
            cout << arr[i] << endl;
        }
    }

    // Passing arr[] to A
    A(arr, n);
    delete[] arr;
}

void C() {
    int n;
    cout << "Enter a Number: ";
    cin >> n;
    B(n);
}

void func2(int n) {
    int* arr = new int[n];
    int holder = 0;
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[i] > arr[j]) {
                holder = arr[i];
                arr[i] = arr[j];
                arr[j] = holder;
            }
        }
    }

    delete[] arr;
}

void func3(int n) {
    int iterations = 0;
    for (int i = 0; i < n; i++) {
        if (i%2 == 0) {
            i++;
        }
        iterations++;
    }
}

static int func4(int n) {
    int arr[10000];
    for (int i = 0; i < 10000; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
    for (int k = 0; k < n; k++) {
    for (int l = 0; l < n; l++) {
    for (int m = 0; m < n; m++) {
        if (arr[m] == 0) {
            return 0;
        }
    }
    }
    }
    }
    }
}

int main() {
    int x = 1;

    ofstream test_file;
    test_file.open("func4_1000.csv");
    test_file << "n, time (in micro)\n";
    while (x <= 50) {
        int n = 1000 * x;
        test_file << n << "," ;

        // {
        //     Timer for_func1("func1_100000", test_file);
        //     C();
        // }
        // break;

        // {
        //     Timer for_func2("func2_1000", test_file);
        //     func2(n);
        // }

        // {
        //     Timer for_func3("func3_1000", test_file);
        //     func3(n);
        // }

        {
            Timer for_func4("func4_1000", test_file);
            func4(n);
        }

        x++;
    }

    test_file.close();

}