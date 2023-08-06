int countPrimes(int n){
    if(n <= 2) return 0;

    int length = n;
    bool b[length];

    for (int i = 0; i < sizeof(b) / sizeof(b[0]); ++i) {
        b[i] = true;
    }
    b[0] = false;
    b[1] = false;

    for (int i = 0; i < sizeof(b) / sizeof(b[0]); ++i) {
        if (b[i] == true) {
            for (int j = 2*i; j < sizeof(b) / sizeof(b[0]); j += i) {
                b[j] = false;

            }
        }
    }

    int count = 0;
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); ++i) {
        if (b[i] == true) {
            count++;
        }
    }

    return count;
}
