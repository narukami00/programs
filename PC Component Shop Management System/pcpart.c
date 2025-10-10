#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pcpart.h"

int askContinue() {
    char response[10];
    printf("Do you want to continue? (yes/no): ");
    fgets(response, 10, stdin);
    response[strcspn(response, "\n")] = 0;
    return strcmp(response, "yes") == 0;
}

void addPart(PCPart parts[], int *count) {
    if(*count < 10) {
        printf("Input the name of the part: ");
		fgets(parts[*count].part, 50, stdin);
		parts[*count].part[strcspn(parts[*count].part, "\n")] = 0;

		printf("Input the name of the manufacturer: ");
		fgets(parts[*count].manufacturer, 50, stdin);
		parts[*count].manufacturer[strcspn(parts[*count].manufacturer, "\n")] = 0;

		printf("Input the name of the model: ");
		fgets(parts[*count].model, 50, stdin);
		parts[*count].model[strcspn(parts[*count].model, "\n")] = 0;

		printf("Input the price of the model: ");
		scanf("%f", &parts[*count].price);
		getchar();

        (*count)++;
    } else {
        printf("No more space to add parts.\n");
    }
}

void viewParts(PCPart parts[], int count) {
    for(int i = 0; i < count; i++) {
        printf("%s (%s %s): %.2f\n", parts[i].part, parts[i].manufacturer, parts[i].model, parts[i].price);
    }
}

void searchPart(PCPart parts[], int count) {
    char search[50];
    printf("Enter part name to search: ");
    fgets(search, 50, stdin);
    search[strcspn(search, "\n")] = 0;
    for(int i = 0; i < count; i++) {
        if(strcmp(parts[i].part, search) == 0) {
            printf("%s (%s %s): %.2f\n", parts[i].part, parts[i].manufacturer, parts[i].model, parts[i].price);
            return;
        }
    }
    printf("Part not found.\n");
}

void editPart(PCPart parts[], int count) {
    char search[50];
    printf("Enter part name to edit: ");
    fgets(search, 50, stdin);
    search[strcspn(search, "\n")] = 0;
    for(int i = 0; i < count; i++) {
        if(strcmp(parts[i].part, search) == 0) {
            printf("Enter new manufacturer: ");
            fgets(parts[i].manufacturer, 50, stdin);
            parts[i].manufacturer[strcspn(parts[i].manufacturer, "\n")] = 0;
            printf("Enter new model: ");
            fgets(parts[i].model, 50, stdin);
            parts[i].model[strcspn(parts[i].model, "\n")] = 0;
            printf("Enter new price: ");
            scanf("%f", &parts[i].price);
            getchar();
            return;
        }
    }
    printf("Part not found.\n");
}

void saveToFile(PCPart parts[], int count) {
    FILE *file = fopen("pcparts.txt", "w");
    fprintf(file, "PC Parts\n");
	fprintf(file, "\n");
    fprintf(file, "%-20s %-20s %-20s %-10s\n", "Name of Component", "Manufacturer", "Model No", "Price");
	fprintf(file, "\n");
    float total = 0.0;
    for(int i = 0; i < count; i++) {
        fprintf(file, "%-20s %-20s %-20s %-10.2f\n", parts[i].part, parts[i].manufacturer, parts[i].model, parts[i].price);
        total += parts[i].price;
    }
    fprintf(file, "%-20s %-20s %-20s Total cost: %.2f\n", "", "", "", total);
    fclose(file);
}
void calculateTotal(PCPart parts[], int count) {
    float total = 0.0;
    for(int i = 0; i < count; i++) {
        total += parts[i].price;
    }
    printf("Total cost: %.2f\n", total);
}
