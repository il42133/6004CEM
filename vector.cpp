#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    std::vector<int> v1 = {0, 1, 2 ,3, 4, 5, 6, 7, 8, 9};
    std::vector<int> v2 = {12, 23, 34, 45, 56, 67, 78, 90, 123, 456};
    std::vector<int> sum;
    int j;

    //omp_set_num_threads(5);
    auto start = high_resolution_clock::now();
    #pragma omp parallel
    {
        int i;
        #pragma omp for schedule(dynamic, 5)
        for(int i = 0; i < v1.size(); i++) {
            //#pragma omp ordered
            sum.push_back(v1[i] + v2[i]);
        }        
    }
    auto stop = high_resolution_clock::now();

    cout << "Dynamic, chunk size 5" << endl;
    cout << "Vector sum: ";
    for(j = 0; j < sum.size(); j++) {
        cout << sum.at(j) << ' ';
    }
    cout << endl;

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}