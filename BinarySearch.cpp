#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Driver code
    int binarySearch(vector<int> nums, int x)
    {
        int n = nums.size();
        int result = search(nums, 0, n - 1, x);
        if (result == -1){
            cout << "Element is not present in array\n";
        }
        else{
            cout << "Element is present at index " << result << endl;
        }
        return 0;
    }

private:
    // An iterative binary search function.
    int search(vector<int>& nums, int l, int r, int x)
    {
        while (l <= r) {
            int m = l + (r - l) / 2;
     
            // Check if x is present at mid
            if (nums[m] == x)
                return m;
     
            // If x greater, ignore left half
            if (nums[m] < x)
                l = m + 1;
     
            // If x is smaller, ignore right half
            else
                r = m - 1;
        }
     
        // If we reach here, then element was not present
        return -1;
    }
     
};

/*
int main(){
        Solution bin;
        vector<int> vec={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
        bin.binarySearch(vec,15);

        return 0;
}
*/

