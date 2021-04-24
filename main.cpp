//
// Created by yang on 4/24/21.
//
#include "algorithm.hpp"
#include <iostream>
#include <random>

using namespace std;

int main() {
    int max = 25;
    default_random_engine random_engine(time(nullptr));
    uniform_int_distribution<int> uid(100,1000);
    int *nums = new int[max];
    for (int i = 0; i < max; i++) {
        nums[i] = uid(random_engine);
    }

    cout << "Before quick sort:" << endl;
    for (int i = 0; i < max; i++) {
        cout << nums[i] << ' ';
    }

    cout << endl << "---------------------------" << endl;

    cout << "After quick sort:" << endl;
    Quick_Sort()(nums, max);
    for (int i = 0; i < max; i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;

    delete[] nums;
    return 0;
}

