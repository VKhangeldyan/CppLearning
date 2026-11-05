#include <iostream>

int main() {

    int arr[] = {3, 4, 6, 8, 8, 3, 1, 7, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int firstSingle = 0;
    int secondSingle = 0;
    int singlesXor = 0;

    for(int i = 0; i < n; i++) {
        singlesXor ^= arr[i];
    }

    int differentBit = singlesXor & (-singlesXor);

    for(int i = 0; i < n; i++) {
        if(arr[i] & differentBit) {
            firstSingle ^= arr[i];
        } else {
            secondSingle ^= arr[i];
        }
    }

    std::cout << "Are the non-repeating numbers " << firstSingle << " and " << secondSingle << std::endl;

    return 0;
}