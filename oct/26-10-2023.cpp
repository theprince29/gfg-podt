link : https://practice.geeksforgeeks.org/problems/find-optimum-operation4504/1


int minOperation(int n)
    {
        bitset<32> b(n);
        return b.count() + log2(n);
    }
