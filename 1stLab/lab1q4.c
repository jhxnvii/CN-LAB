/*q4. */
#include <stdio.h>

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    struct pkt packet;
    printf("Enter a number: ");
    scanf("%c%c%c", &packet.ch1, &packet.ch2[0], &packet.ch2[1]);
    getchar(); 

    printf("\nContent of each member of the structure:\n");
    printf("ch1: %c\n", packet.ch1);
    printf("ch2[0]: %c\n", packet.ch2[0]);
    printf("ch2[1]: %c\n", packet.ch2[1]);
    printf("ch3: %c\n", packet.ch3);

    
    unsigned int num = (packet.ch1 << 24) | (packet.ch2[0] << 16) | (packet.ch2[1] << 8) | packet.ch3;
    printf("\nOriginal number: %u\n", num);

    return 0;
}