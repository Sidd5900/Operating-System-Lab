#include <stdio.h>

// Function to find and print xor of two numbers
void XOR(int a, int b) {
    int answer = 0;
    int multiplier=1;
    int num1=a;
    int num2=b;

    while (1) {
        if(a==0 && b==0)
            break;
        int lsba= a%2;
        int lsbb= b%2;    
        int lsbxor = lsba * !(lsbb) + !(lsba) * lsbb;
        answer += lsbxor * multiplier;
        a /= 2;
        b /= 2;
        multiplier *= 2;
    }
    printf("XOR of %d and %d = %d\n", num1, num2, answer);
}

// Main function
int main(int argc, char* argv[]) {

    if (argc != 3) printf("Error: Invalid number of arguments(2 required)");
    else {
        int a, b;
        sscanf(argv[1], "%d", &a);
        sscanf(argv[2], "%d", &b);
        // Find and print XOR
        XOR(a, b);
    }
}

