// Problem link: https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1
// level : very easy
// topic : bitwise 

bool checkKthBit(int n, int k)
{
    // Create a bitmask with only the k-th bit set to 1
    // Shift the binary representation of 1 to the left by k positions
    int bitmask = 1 << k;

    // Use the bitwise AND operator to isolate the k-th bit of n
    // If the k-th bit is 1, bitmask & n will be greater than 0
    // If the k-th bit is 0, bitmask & n will be equal to 0
    int result = n & bitmask;

    // Check if the result of the AND operation is equal to 0
    if (result == 0) {
        // If it is 0, it means the k-th bit of n is 0, so return false
        return false;
    } else {
        // If it's not 0, it means the k-th bit of n is 1, so return true
        return true;
    }
}
