#include <iostream>
#include <random>
#include <limits>
#include <vector>

using namespace std;

template<typename IntegerType>
void radix_sort(vector<IntegerType>& elems, size_t max = numeric_limits<IntegerType>::max(), size_t base = 256) {
    vector<vector<IntegerType>> buckets(base);

    for (size_t b = 1; b < max; b *= base) {
        for (auto& bucket : buckets) {
            bucket.clear();
        }

        for (auto cur : elems) {
            buckets[(cur / b) % base].push_back(cur);
        }

        elems.clear();

        for (auto& bucket : buckets) {
            elems.insert(elems.end(), bucket.begin(), bucket.end());
        }
    }
}

// An example of usage
int main() {
    vector<int> elems;

    // Fill elems with random data
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(1, 100);

    cout << "Massive: ";

    for (size_t i = 0, size = 24; i < size; ++i) {
        elems.push_back(dist(mt));
        cout << elems[i] << ' ';
    }

    cout << endl << endl << "Sorted massive: ";

    radix_sort(elems);

    for (auto x : elems) {
        cout << x << ' ';
    }

    cout << endl;

    return 0;
}
