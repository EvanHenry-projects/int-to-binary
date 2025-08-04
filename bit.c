#include <stdio.h>
#include <stdlib.h>

int min_bytes(int a);

char* itob(int a) {
    
    int bytes = min_bytes(a);

    int bits = 8 * bytes;
    char* bin = (char*)malloc(bits * sizeof(char));

    unsigned int upper = 1 << (bits-1);
    unsigned int t;

    for(int i = 0; i < bits; i++){
        t = a & (upper >> i);
        if(t){ *(bin+i) = '1'; } else { *(bin+i) = '0'; }
    }
    *(bin+bits) = '\0';

    return bin;
}

int min_bytes(int a){
    if(a == 0) return 1;

    int n = 0;
    while(a != 0){
        a = a >> 8;
        n++;
    }
    return n;
}

int main(){
    
    char* b;
    int input;

    while(1){
        printf("Enter a number to convert: ");
        scanf("%d", &input);
        if(input < 0){ printf("Goodbye :)\n\n"); return 0; }
        b = itob(input);
        printf("%s\n", b);
    }

    return 0;
}
