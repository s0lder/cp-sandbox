#include <iostream>

void Citire(int n, int v[]) {
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
}

void Sort(int n, int v[]) {
    for (int i = 1; i < n; i++) {
        int key = v[i];

        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            --j;
        }

        v[j + 1] = key;
    }
}

int caut(int n, int x, int v[]) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (x == v[mid])
            return 1;
        else if (x < v[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return 0;
}

int main() {
    int n, v[10000], w[10000];

    std::cin >> n;
    Citire(n, v);
    Citire(n, w);

    Sort(n, v);
    Sort(n, w);
    
    for (int i = 0; i < n; i++)
        if (caut(n, v[i], w))
            std::cout << v[i] << ' ';

    return 0;
}