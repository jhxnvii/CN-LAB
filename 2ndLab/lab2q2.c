// WAP to extract each byte of a given no and store them in a variable and display them.

#include <stdio.h>

void extractBytes(unsigned int num) {
    unsigned char byte1 = (num & 0xFF);   //and operation
    unsigned char byte2 = ((num >> 8) & 0xFF); // no.8 bits to rightmost  and dicard the msb
    unsigned char byte3 = ((num >> 16) & 0xFF); //no. 16 bits to rightmost and discard the previous 2 bytes
    unsigned char byte4 = ((num >> 24) & 0xFF); // 

    printf("Original Number: %u\n", num);
    printf("Byte 1: %u\n", byte1);
    printf("Byte 2: %u\n", byte2);
    printf("Byte 3: %u\n", byte3);
    printf("Byte 4: %u\n", byte4);
}

int main() {
    unsigned int num;
    printf("Enter an unsigned integer: ");
    scanf("%u", &num);

    extractBytes(num);

    return 0;
}
// and operation is used to extract the relevant bites and discard relevant bites.