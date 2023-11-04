// Problem Link: https://www.geeksforgeeks.org/problems/find-transition-point-1587115620/1

// Given a sorted array containing only 0s and 1s, find the transition point, i.e., the first index where 1 was observed, and before that, only 0 was observed.


class Solution
{
public:    
    int transitionPoint(int arr[], int n) {
        int start = 0;         // Initialize the start index to 0.
        int end = n - 1;       // Initialize the end index to the last element of the array.

        if (arr[end] == 0) {   // Check if the last element is 0. If yes, there is no transition point.
            return -1;
        }

        if (arr[start] == 1) { // Check if the first element is 1. If yes, the transition point is at the start.
            return start;
        }

        while (start <= end) { // Perform binary search until the start index is less than or equal to the end index.
            int mid = start + (end - start) / 2; // Calculate the middle index to divide the search range in half.

            if (arr[mid] == 1 && arr[mid - 1] != 1 && mid - 1 >= 0) {
                // If the current element is 1 and the previous element is not 1, return the current index as the transition point.
                return mid;
            }
            if (arr[mid - 1] == 1) {
                // If the element before the middle is 1, adjust the end index to search in the left half of the array.
                end = mid - 1;
            }
            if (arr[mid] == 0) {
                // If the current element is 0, adjust the start index to search in the right half of the array.
                start = mid + 1;
            }
        }
        
        return -1; // If no transition point is found in the entire array, return -1.
    }
};
