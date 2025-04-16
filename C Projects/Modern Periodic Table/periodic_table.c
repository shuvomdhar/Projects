#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

// Structure to store element details
typedef struct {
    int atomic_number;
    char name[30];
    char symbol[5];
    float atomic_weight;
    int group;
    int period;
} Element;

void inputElements(Element elements[], int n) {
    printf("\nEnter details of %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("\nElement %d:\n", i + 1);
        printf("Atomic Number: ");
        scanf("%d", &elements[i].atomic_number);
        printf("Name: ");
        scanf("%s", elements[i].name);
        printf("Symbol: ");
        scanf("%s", elements[i].symbol);
        printf("Atomic Weight: ");
        scanf("%f", &elements[i].atomic_weight);
        printf("Group: ");
        scanf("%d", &elements[i].group);
        printf("Period: ");
        scanf("%d", &elements[i].period);
    }
}

void displayTable(Element elements[], int n) {
    printf("\n%-5s %-15s %-5s %-10s %-6s %-6s\n", "No.", "Name", "Sym", "Weight", "Group", "Period");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-15s %-5s %-10.2f %-6d %-6d\n",
               elements[i].atomic_number,
               elements[i].name,
               elements[i].symbol,
               elements[i].atomic_weight,
               elements[i].group,
               elements[i].period);
    }
}

int main() {
    int n;
    printf("Enter the number of elements to input (max %d): ", MAX_ELEMENTS);
    scanf("%d", &n);
    if (n < 1 || n > MAX_ELEMENTS) {
        printf("Invalid number of elements. Please enter between 1 and %d.\n", MAX_ELEMENTS);
        return 1;
    }

    Element elements[n];
    inputElements(elements, n);
    displayTable(elements, n);
    return 0;
}
