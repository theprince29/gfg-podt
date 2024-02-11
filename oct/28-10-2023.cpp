problem link:https://practice.geeksforgeeks.org/problems/bleak-numbers1552/1
level: medium 



class solution{

public:
       
int is_bleak(int n){
    for(int x = n- ceil (log2(n)); x<=n; x++)
        if(x+countbits(x) == n) 
            return 0;
    return 1;
}


int countbits(int n){
    if(n==0 ) return 0;
    return (n&1) + countbits(n>>1);
}
};
