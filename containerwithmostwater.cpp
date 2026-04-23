#include <iostream>
using namespace std;

int maxArea(int height[], int n) {
    int left = 0;
    int right = n - 1;
    int maxWater = 0;

    while (left < right) {
        int h = min(height[left], height[right]);
        int width = right - left;
        int area = h * width;

        if (area > maxWater) {
            maxWater = area;
        }

       
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int height[n];
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int result = maxArea(height, n);
    cout << "Maximum Water: " << result << endl;

    return 0;
}