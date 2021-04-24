/**
 * Insertion sort.
 */
#include <functional>

class Insertion_Sort {
public:
    template<typename T>
    void operator()(T arr[], int length);
};

template<typename T>
void Insertion_Sort::operator()(T arr[], int length) {
    // Validity check.
    if (length < 2 || arr == nullptr) {
        return;
    }

    // Select one element and insert it into previous ordered list.
    T tmp;
    for (int i = 1; i < length; i++) {
        int j;
        tmp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > tmp; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}

template<typename T>
void bubble_sort(T arr[], int length) {
    // Validity check.
    if (length < 2 || arr == nullptr) {
        return;
    }

    bool flag;
    for (int i = 0; i < length - 1; i++) {
        flag = true;
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T e = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = e;
                flag = false;
            }
        }
        // If there is no swap in one loop, directly jump over the for-loop.
        if (flag) {
            break;
        }
    }
}

class Quick_Sort {
public:
    template<typename T>
    void operator()(T arr[], int length);

private:
    template<typename T>
    void q_sort(T arr[], int left, int right);

    template<typename T>
    T median3(T arr[], int left, int right);

    template<typename T>
    void swap(T &u, T &v) {
        T tmp = u;
        u = v;
        v = tmp;
    }

private:
    const int cutoff = 3;
};

template<typename T>
void Quick_Sort::operator()(T arr[], int length) {
    q_sort(arr, 0, length - 1);
}

template<typename T>
void Quick_Sort::q_sort(T arr[], int left, int right) {
    if (left + cutoff <= right) {
        T pivot = median3(arr, left, right);
        int i = left, j = right - 1;

        while (true) {
            while (arr[++i] < pivot) {
            }
            while (arr[--j] > pivot) {
            }
            if (i < j) {
                swap(arr[i], arr[j]);
            } else {
                break;
            }
        }

        swap(arr[i], arr[right - 1]);

        q_sort(arr, left, i - 1);
        q_sort(arr, i + 1, right);
    } else {
        Insertion_Sort()(arr + left, right - left + 1);
    }
}

template<typename T>
T Quick_Sort::median3(T arr[], int left, int right) {
    int center = (left + right) / 2;

    if (arr[left] > arr[center]) {
        swap(arr[left], arr[center]);
    }
    if (arr[left] > arr[right]) {
        swap(arr[left], arr[right]);
    }
    if (arr[center] > arr[right]) {
        swap(arr[center], arr[right]);
    }

    swap(arr[center], arr[right - 1]);
    return arr[right - 1];
}