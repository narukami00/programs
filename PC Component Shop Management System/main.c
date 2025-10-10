#include <stdio.h>
#include <stdlib.h>
#include "pcpart.h"

int main() {
    PCPart parts[10];
    int count = 0;
    int choice;
    do {
        printf("\n1. Add part\n2. View parts\n3. Search for part\n4. Edit part\n5. Calculate total\n6. Save to file\n7. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1:
                addPart(parts, &count);
                break;
            case 2:
                viewParts(parts, count);
                break;
            case 3:
                searchPart(parts, count);
                break;
            case 4:
                editPart(parts, count);
                break;
            case 5:
                calculateTotal(parts, count);
                break;
            case 6:
                saveToFile(parts, count);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 7 && askContinue());

    return 0;
}
