#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Person
typedef struct {
    char name[50];
    int age;
    double height;
} Person;

// Funciones de comparación
int compare_by_name(const void *a, const void *b) {
    return strcmp(((Person *)a)->name, ((Person *)b)->name);
}

int compare_by_age(const void *a, const void *b) {
    return ((Person *)a)->age - ((Person *)b)->age;
}

int compare_by_height(const void *a, const void *b) {
    if (((Person *)a)->height > ((Person *)b)->height) return 1;
    else if (((Person *)a)->height < ((Person *)b)->height) return -1;
    return 0;
}

// Función para imprimir el arreglo de personas
void print_people(Person people[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Age: %d, Height: %.1f cm\n",
               people[i].name, people[i].age, people[i].height);
    }
}

int main() {
    // Arreglo de personas
    Person people[] = {
        {"Gabriel", 25, 165.5},
        {"Adrian", 23, 172.3},
        {"Reychell", 20, 160.0},
        {"Julio", 10, 110.2},
        {"Victor", 27, 158.7}
    };
    int size = sizeof(people) / sizeof(people[0]);

    // Orden original
    printf("\nOrden Original: \n");
    print_people(people, size);

    // Ordenar por nombre
    printf("\nSorted by Name:\n");
    qsort(people, size, sizeof(Person), compare_by_name);
    print_people(people, size);

    // Ordenar por edad
    printf("\nSorted by Age:\n");
    qsort(people, size, sizeof(Person), compare_by_age);
    print_people(people, size);

    // Ordenar por altura
    printf("\nSorted by Height:\n");
    qsort(people, size, sizeof(Person), compare_by_height);
    print_people(people, size);

    return 0;
}

