#include <stdio.h>
#include <stdint.h>

// Function to check the endianness of the host machine
int isLittleEndian() {
    uint16_t num = 0x0001;
    uint8_t *ptr = (uint8_t *)&num;
    return (*ptr == 0x01);
}

// Function to convert Little Endian to Big Endian and vice-versa
uint32_t swapEndianness(uint32_t num) {
    return ((num >> 24) & 0xFF) | ((num >> 8) & 0xFF00) | ((num << 8) & 0xFF0000) | ((num << 24) & 0xFF000000);
}

int main() {
    uint32_t num;
    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Bytes in memory (in hexadecimal representation):\n");
    uint8_t *ptr = (uint8_t *)&num;

    // Print the content of each byte location
    for (int i = 0; i < sizeof(num); i++) {
        printf("Byte %d: 0x%02X\n", i, ptr[i]);
    }

    if (isLittleEndian()) {
        printf("\nThe host machine is Little Endian.\n");
    } else {
        printf("\nThe host machine is Big Endian.\n");
    }

    // Convert the endianness
    num = swapEndianness(num);

    printf("\nConverted number: %u\n", num);

    return 0;
}