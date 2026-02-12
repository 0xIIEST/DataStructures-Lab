#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct Box {
    int box_id;
    float weight;
    struct Box *next;
};

void push(struct Box **top, int id, float weight) {
    struct Box *newBox = malloc(sizeof(struct Box));
    newBox->box_id = id;
    newBox->weight = weight;
    newBox->next = *top;
    *top = newBox;
}

void pop(struct Box **top) {
    if (*top == NULL) {
        printf("stack empty... nothing to unload\n");
        return;
    }
    struct Box *temp = *top;
    printf("box unloaded -> id:%d weight:%.2f\n",
           temp->box_id, temp->weight);
    *top = temp->next;
    free(temp);
}

void peek(struct Box *top) {
    if (top == NULL) {
        printf("no box on top right now\n");
        return;
    }
    printf("top box -> id:%d weight:%.2f\n",
           top->box_id, top->weight);
}

int countLL(struct Box *top) {
    int cnt = 0;
    while (top != NULL) {
        cnt++;
        top = top->next;
    }
    return cnt;
}

void displayLL(struct Box *top) {
    if (top == NULL) {
        printf("stack is empty\n");
        return;
    }
    printf("stack status top to bottom):\n");
    while (top != NULL) {
        printf("id:%d weight:%.2f\n",
               top->box_id, top->weight);
        top = top->next;
    }
}


int arr_id[MAX];
float arr_weight[MAX];
int topArr = -1;

void pushArr(int id, float weight) {
    if (topArr == MAX - 1) {
        printf("stack full, cannot load more\n");
        return;
    }
    topArr++;
    arr_id[topArr] = id;
    arr_weight[topArr] = weight;
}

void popArr() {
    if (topArr == -1) {
        printf("stack empty, nothing to pop\n");
        return;
    }
    printf("box unloaded -> id:%d weight:%.2f\n",
           arr_id[topArr], arr_weight[topArr]);
    topArr--;
}

void peekArr() {
    if (topArr == -1) {
        printf("no box at the top\n");
        return;
    }
    printf("top box -> id:%d weight:%.2f\n",
           arr_id[topArr], arr_weight[topArr]);
}

int countArr() {
    return topArr + 1;
}

void displayArr() {
    if (topArr == -1) {
        printf("stack currently empty\n");
        return;
    }
    printf("stack status (top to bottom):\n");
    for (int i = topArr; i >= 0; i--) {
        printf("id:%d weight:%.2f\n",
               arr_id[i], arr_weight[i]);
    }
}

int main() {
    struct Box *topLL = NULL;
    int impl, choice;

    printf("select stack implementation\n");
    printf("1. linked list based stack\n");
    printf("2. array based stack\n");
    printf("enter choice: ");
    scanf("%d", &impl);

    do {
        printf("\n--- MENU ---\n");
        printf("1. load box (push)\n");
        printf("2. unload box (pop)\n");
        printf("3. check top box (peek)\n");
        printf("4. count boxes\n");
        printf("5. display stack\n");
        printf("0. exit\n");
        printf("command: ");
        scanf("%d", &choice);

        if (impl == 1) {
            int id;
            float w;
            switch (choice) {
                case 1:
                    printf("enter box id and weight: ");
                    scanf("%d %f", &id, &w);
                    push(&topLL, id, w);
                    break;
                case 2:
                    pop(&topLL);
                    break;
                case 3:
                    peek(topLL);
                    break;
                case 4:
                    printf("total boxes: %d\n", countLL(topLL));
                    break;
                case 5:
                    displayLL(topLL);
                    break;
            }
        }
        else if (impl == 2) {
            int id;
            float w;
            switch (choice) {
                case 1:
                    printf("enter box id and weight: ");
                    scanf("%d %f", &id, &w);
                    pushArr(id, w);
                    break;
                case 2:
                    popArr();
                    break;
                case 3:
                    peekArr();
                    break;
                case 4:
                    printf("total boxes: %d\n", countArr());
                    break;
                case 5:
                    displayArr();
                    break;
            }
        }

    } while (choice != 0);

    printf("program closed\n");
    return 0;
}
