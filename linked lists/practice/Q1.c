#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int id;
    char name[100];
    float salary;
    struct employee* next;
};

struct employee* head = NULL; // Initialize head to NULL

void create() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        struct employee* temp = (struct employee*)malloc(sizeof(struct employee));

        printf("Enter the ID of employee %d: ", i + 1);
        scanf("%d", &temp->id);
        printf("Enter the name of employee %d: ", i + 1);
        scanf("%s", temp->name);
        printf("Enter the salary of employee %d: ", i + 1);
        scanf("%f", &temp->salary);

        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            struct employee* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = temp;
        }
    }
}

void view() {
    struct employee* temp = head;
    while (temp != NULL) {
        printf("Employee ID: %d, Name: %s, Salary: %.2f\n", temp->id, temp->name, temp->salary);
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("Enter 1 to create, 2 to view, or any other key to exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                view();
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
