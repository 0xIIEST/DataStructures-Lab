#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int roll;
    char name[50];
    float cgpa;
    struct Node *next;
};

struct Node* createNode(int roll, char name[], float cgpa){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->cgpa = cgpa;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node **head, int roll, char name[], float cgpa){
    struct Node *newNode = createNode(roll, name, cgpa);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void addAtStart(struct Node **head, int roll, char name[], float cgpa){
    struct Node *temp = createNode(roll, name, cgpa);
    temp->next = *head;
    *head = temp;
}

void display(struct Node **head){
    struct Node *temp = *head;
    system("clear");
    while (temp != NULL) {
        printf("Record Found:\n");
        printf("Roll: %d\n", temp->roll);
        printf("Name: %s\n", temp->name);
        printf("CGPA: %.2f\n", temp->cgpa);
        printf("--------------------------------\n");
        temp = temp->next;
    }
}

void search(struct Node **head, int value){
    struct Node *temp = *head;
    system("clear");
    while (temp != NULL) {
        if (temp->roll == value) {
            printf("Record Found:\n");
            printf("Name: %s\n", temp->name);
            printf("CGPA: %.2f\n", temp->cgpa);
            printf("Roll: %d\n", temp->roll);
            return;
        }
        temp = temp->next;
    }
    printf("Record not found.\n");
}

int idExists(struct Node **head, int roll){
    struct Node *temp = *head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void pop(struct Node **head, int roll){
    if (*head == NULL) {
        printf("empty lisst.\n");
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;
    if (temp->roll == roll) {
        *head = temp->next;
        free(temp);
        printf("Patient removed.\n");
        return;
    }
    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Patient not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Patient removed.\n");
}

void updateCGPA(struct Node **head, int roll, float cgpa){
    struct Node *temp = *head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            temp->cgpa = cgpa;
            return;
        }
        temp = temp->next;
    }
}

int main(){
    system("clear");
    struct Node *head = createNode(20250101, "John Doe", 9.3);
    append(&head, 20250102, "Jane", 9.97);

    int running = 1;
    printf("           Welcome To IIEST Shibpur\n");

    while (running) {
        int cmd;
        printf("\nChoose your operation: \n");
        printf("1. Display Records\n");
        printf("2. Search By ID\n");
        printf("3. New Admission\n");
        printf("4. Remove Student\n");
        printf("5. Update Student CGPA\n");
        printf("0. Quit\n");
        printf("\n\nCommand Number: ");
        scanf("%d", &cmd);

        switch (cmd) {
            case 0:
                printf("Goodbye!\n");
                running = 0;
                break;

            case 1:
                display(&head);
                break;

            case 2: {
                int temp;
                printf("Enter the ID to search: ");
                scanf("%d", &temp);
                search(&head, temp);
                break;
            }

            case 3: {
                int t_roll;
                float t_cgpa;
                char t_name[25];
                int isEmergency;

                printf("Enter Roll Number:");
                scanf("%d", &t_roll);
                getchar();

                if (idExists(&head, t_roll)) {
                    printf("Roll Number already taken!\n");
                    break;
                }

                printf("Enter name:");
                scanf("%[^\n]", t_name);
                getchar();

                printf("Enter CGPA: ");
                scanf("%f", &t_cgpa);

                printf("Is this an emergency admission? 0: NO | 1: YES");
                scanf("%d", &isEmergency);

                if (isEmergency) {
                    addAtStart(&head, t_roll, t_name, t_cgpa);
                } else {
                    append(&head, t_roll, t_name, t_cgpa);
                }
                break;
            }

            case 4: {
                int t2_roll;
                printf("Enter roll number to remove: ");
                scanf("%d", &t2_roll);
                pop(&head, t2_roll);
                break;
            }

            case 5: {
                int t3_roll;
                float t3_cgpa;
                printf("Enter student's roll number: ");
                scanf("%d", &t3_roll);

                if (!idExists(&head, t3_roll)) {
                    printf("Roll number not found!\n");
                    break;
                }

                printf("Enter new CGPA: ");
                scanf("%f", &t3_cgpa);

                if (t3_cgpa > 10 || t3_cgpa < 0) {
                    printf("Invalid value!\n");
                    break;
                }

                updateCGPA(&head, t3_roll, t3_cgpa);
                break;
            }

            default:
                printf("Enter a valid command!");
                break;
        }
    }
    return 0;
}
