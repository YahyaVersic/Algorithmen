int fib(int n){

    if (n < 2){
        return n;
    }

    int l1 = 1;
    int l2 = 1;
    int temp;
    for(int i = 2; i < n; i++){
        temp = l2 + l1;
        l1 = l2;
        l2 = temp;
    }

    return l2;

}
