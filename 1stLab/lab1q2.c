/*
 q2. WAP to store n number of student details such as roll number, gender, mobile number mark in three subjects PHY, chem and math and assisting the student list 
in the following formate

SL.no 
Roll number
Name
Gender
Mobile number
Phy mark
Chem mark
Math mark
*/

#include <stdio.h>
#include <stdlib.h>

struct Student {
    int sno, roll;
    char name[100];
    char gender; // F - Female, M - Male
    long mobile;
    int phy, chem, math; // Marks
};

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    struct Student* stud[n];
    for( int i = 0; i < n; i++ ){
        struct Student* temp = (struct Student*)malloc( sizeof(struct Student*) );
        temp->sno = i+1;
        printf("Enter roll, name, gender(M/F), mobile no, phy, chem, math marks: \n");
        scanf("%d %s %c %ld %d %d %d",
                &temp->roll, 
                temp->name, 
                &temp->gender, 
                &temp->mobile,
                &temp->phy,
                &temp->chem,
                &temp->math );
        stud[i] = temp;
    }

    printf("\nPrinting stud info: \n");
    printf("\tSno.\tRoll\tName\tGender\tMobile\tPhy\tChem\tMath\n");
    for( int i = 0; i < n; i++ ){
        struct Student* temp = stud[i];
        printf("\t%3d\t%d\t%s\t%c\t%ld\t%d\t%d\t%d\n", 
                temp->sno, temp->roll, 
                temp->name, temp->gender, 
                temp->mobile,
                temp->phy, temp->chem, temp->math );
    }
}