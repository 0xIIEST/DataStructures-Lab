#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Participant {
    int roll;
    char name[50];
    struct Participant *next;
};

struct Participant* createNode(int roll, char name[]) {
    struct Participant *newNode = malloc(sizeof(struct Participant));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->next = newNode;
    return newNode;
}

void registerParticipant(struct Participant **head, struct Participant **current, int roll, char name[]) {
    struct Participant *newNode = createNode(roll, name);

    if (*head == NULL) {
        *head = newNode;
        *current = newNode;
        return;
    }

    struct Participant *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

void passTurn(struct Participant **current) {
    if (*current == NULL) {
        printf("No participants.\n");
        return;
    }
    *current = (*current)->next;
    printf("Activity passed to %s\n", (*current)->name);
}

void deleteParticipant(struct Participant **head, struct Participant **current, int roll) {
    if (*head == NULL) {
        printf("No participants.\n");
        return;
    }

    struct Participant *temp = *head;
    struct Participant *prev = NULL;

    do {
        if (temp->roll == roll)
            break;
        prev = temp;
        temp = temp->next;
    } while (temp != *head);

    if (temp->roll != roll) {
        printf("Student not found.\n");
        return;
    }

    if (temp->next == temp) {
        free(temp);
        *head = NULL;
        *current = NULL;
        return;
    }

    if (temp == *head) {
        struct Participant *last = *head;
        while (last->next != *head)
            last = last->next;
        *head = temp->next;
        last->next = *head;
    }

    if (temp == *current)
        *current = temp->next;

    if (prev != NULL)
        prev->next = temp->next;

    free(temp);
}

void viewRotation(struct Participant *current) {
    if (current == NULL) {
        printf("No students.\n");
        return;
    }

    struct Participant *temp = current;
    do {
        printf("Roll: %d | Name: %s\n", temp->roll, temp->name);
        temp = temp->next;
    } while (temp != current);
}
int idExists(struct Participant **head, int roll){
    if (*head == NULL)
        return 0;

    struct Participant *temp = *head;
    do {
        if (temp->roll == roll)
            return 1;
        temp = temp->next;
    } while (temp != *head); // untill temp reaches head again
    return 0;
}


int main() {
    struct Participant *head = NULL;
    struct Participant *current = NULL;

    int running = 1;

    while (running) {
        int cmd;
        printf("\n1. Register Participant\n");
        printf("2. Pass Turn\n");
        printf("3. Remove Participant\n");
        printf("4. View Rotation Order\n");
        printf("0. Quit\n");
        printf("Enter command: ");
        scanf("%d", &cmd);

        switch (cmd) {
            case 0:
                running = 0;
                break;

            case 1: {
                int roll;
                char name[50];
                printf("Enter roll: ");
                scanf("%d", &roll);
                getchar();
                if(idExists(roll)){
                    printf("Roll already exists!\n");
                    break;
                }
                printf("Enter name: ");
                scanf("%[^\n]", name);
                registerParticipant(&head, &current, roll, name);
                break;
            }

            case 2:
                passTurn(&current);
                break;

            case 3: {
                int roll;
                printf("Enter roll to remove: ");
                scanf("%d", &roll);
                deleteParticipant(&head, &current, roll);
                break;
            }

            case 4:
                viewRotation(current);
                break;

            default:
                printf("Invalid command.\n");
        }
    }
    return 0;

