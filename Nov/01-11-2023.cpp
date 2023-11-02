// Problem Link: https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1






int minDist(int a[], int n, int x, int y) {
    int minDist = INT_MAX;  // Initialize minDist to a large value
    int xIndex = -1;        // Initialize xIndex
    int yIndex = -1;        // Initialize yIndex

    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            xIndex = i;
            if (yIndex != -1) {
                minDist = min(minDist, abs(xIndex - yIndex));
            }
        } else if (a[i] == y) {
            yIndex = i;
            if (xIndex != -1) {
                minDist = min(minDist, abs(yIndex - xIndex));
            }
        }
    }

    if (xIndex == -1 || yIndex == -1) {
        return -1;  // Either x or y is missing in the array
    }

    return minDist;
}
