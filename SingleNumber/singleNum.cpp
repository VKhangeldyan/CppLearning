#include <iostream>

int main () {

    int arr [] = {1, 2, 5, 7, 2, 1, 9, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int singleNum = 0;

    for (int i = 0; i < n; i ++)
        singleNum ^= arr[i];
        
    std::cout << "Single number is: " << singleNum << std::endl;
    return 0;
}