/*
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 * Example:
 *
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * Note:
 *
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 */

#include <bits/stdc++.h>

using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x        = y;
    y        = temp;
}

void moveZeroes(vector<int> &nums) {
    for (int i = 1, j = 0; i < nums.size(); i++) {
        if (nums[j] != 0) {
            j++;
            continue;
        }
        if (nums[j] == 0 && nums[i] != 0) {
            swap(nums[j], nums[i]);
            ++j;
            continue;
        }
    }
}

string str(vector<int> &nums) {
    stringstream s;
    switch (nums.size()) {
    case 0:
        return "{}";
    case 1:
        s << "{" << nums[0] << "}";
        return s.str();
    }

    s << "{" << nums[0];
    for (auto it = nums.begin() + 1; it != nums.end(); it++) {
        s << "," << *it;
    }
    s << "}";
    return s.str();
}

int main() {
    vector<int> arr1 = {0, 1, 0, 3, 12};
    moveZeroes(arr1);
    cout << str(arr1) << endl;
}
