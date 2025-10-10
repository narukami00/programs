#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct
{
    char name[100];
    int age;
    char country[50];
    float heightinmeter;
} Wicket_Keeper;

void writeFile(FILE *fptr, Wicket_Keeper *wk, int size);
void readFile(FILE *fptr, int size);

int main()
{
    FILE *fptr;
    int wknum = 5;
    Wicket_Keeper wk[wknum];

    if ((fptr = fopen("2207033.txt", "w")) == NULL)
    {
        printf("File cannot be opened for writing.\n");
        exit(1);
    }
    for (int i = 0; i < wknum; i++)
    {
        fflush(stdin);
        printf("Enter details for wicket keeper of ICC CWC %d\n", i + 1);
        printf("Name: ");
        fgets(wk[i].name, 100, stdin);
        wk[i].name[strcspn(wk[i].name, "\n")] = 0;
        printf("Age: ");
        scanf("%d", &wk[i].age);
        printf("Country: ");
        fflush(stdin);
        fgets(wk[i].country, 50, stdin);
        wk[i].country[strcspn(wk[i].country, "\n")] = 0;
        printf("Height in meter: ");
        scanf("%f", &wk[i].heightinmeter);
    }

    writeFile(fptr, wk, wknum);
    fclose(fptr);

    if ((fptr = fopen("2207033.txt", "r")) == NULL)
    {
        printf("File cannot be opened for reading.\n");
        exit(1);
    }

    printf("\n\nReading File\n\n");
    readFile(fptr, wknum);
    fclose(fptr);

    printf("Wicket Keepers records saved and read successfully.\n");
    return 0;
}

void writeFile(FILE *fptr, Wicket_Keeper *wk, int size)
{
    for (int i = 0; i < size; i++)
    {
        fprintf(fptr, "Name: %s\n", wk[i].name);
        fprintf(fptr, "Age: %d\n", wk[i].age);
        fprintf(fptr, "Country: %s\n", wk[i].country);
        fprintf(fptr, "Height in meter: %.2f\n", wk[i].heightinmeter);
    }
}

void readFile(FILE *fptr, int size)
{
    char buffer[255];
    while (fgets(buffer, 255, fptr) != NULL)
    {
        printf("%s", buffer);
    }
}
