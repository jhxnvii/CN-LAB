//WAP to modify the program no. 3 to regenerate original numbers
//from the structure member and also display the total number

# include <stdio.h>

struct Packet {   //STORE EXTRACTED AND REMADE BYTES
    char a1;
    char a2[2];
    char a3;
};

int main(){
    struct Packet ch;

    int c = 0x0000FFFF;
    ch.a1 = (c >> 24) & 0xFF;  //EXTRACTS MSB
    ch.a2[0] = ( c >> 16 ) & 0xFF;// EXTRACTS 1ST MIDDLE BYTE
    ch.a2[1] = ( c >> 8 ) & 0xFF;// EXTRACTS 2ND MIDDLE BYTE
    ch.a3 = c & 0xFF;// EXTRACTS LSB

    int regain = ( (ch.a1 << 24) | (ch.a2[0] << 16) | (ch.a2[1] << 8) | ch.a3 ); //BITWISE OR USED IN THIS.

    printf("Bytes are: %d %d %d %d\n", ch.a1, ch.a2[0], ch.a2[1], ch.a3);
    printf("Original: %d; Remade: %d\n", c, regain);
    return 0;
}
