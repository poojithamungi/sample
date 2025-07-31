#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void reverseArray(std::vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        swap(arr[left++], arr[right--]);
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::cout << "before reversed array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    reverseArray(arr);
    std::cout << "Reversed Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}