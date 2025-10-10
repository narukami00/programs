#ifndef PCPART_H
#define PCPART_H

typedef struct {
    char part[50];
    char manufacturer[50];
    char model[50];
    float price;
} PCPart;

int askContinue();
void addPart(PCPart parts[], int *count);
void viewParts(PCPart parts[], int count);
void searchPart(PCPart parts[], int count);
void editPart(PCPart parts[], int count);
void calculateTotal(PCPart parts[], int count);
void saveToFile(PCPart parts[], int count);

#endif // PCPART_H
