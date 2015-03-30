#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    // Method 1
    //double findMedianSortedArrays(int A[], int m, int B[], int n) {
    //    int i = 0;
    //    int j = 0;
    //    int m1 = -1;
    //    int m2 = -1;

    //    for (int cnt = 0; cnt <= (m+n)/2; cnt++) {
    //        if (i == m) {
    //            m1 = m2;
    //            m2 = B[j];
    //            j++;
    //            continue;
    //        } else if (j == n) {
    //            m1 = m2;
    //            m2 = A[i];
    //            i++;
    //            continue;
    //        }

    //        if (A[i] < B[j]) {
    //            m1 = m2;
    //            m2 = A[i];
    //            i++;
    //        } else {
    //            m1 = m2;
    //            m2 = B[j];
    //            j++;
    //        }
    //    }

    //    if ((m+n)%2 == 1)
    //        return m2;
    //    else
    //        return (m1+m2)/2.0;
    //}
};

int main(int argc, char *argv[]) {
    class Solution sol1;

    int arr1[] = {1, 12, 15, 26, 38};
    int arr2[] = {2, 13, 17, 30, 45};
    int arr3[] = {3, 11, 14, 28, 35, 70};

    cout << sol1.findMedianSortedArrays(arr1, 5, arr2, 5) << endl;
    cout << sol1.findMedianSortedArrays(arr1, 5, arr3, 6) << endl;

    return 0;
}

