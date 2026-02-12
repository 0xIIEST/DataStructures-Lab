```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int transactionId;
    long long dateTime;
    char transactionType;
    double amount;
    double balance;
    struct Node *next;
};

struct Node* createTransaction(int transactionId, long long dateTime,
                               char transactionType, double amount, double balance) {
    struct Node *node = malloc(sizeof(struct Node));
    node->transactionId = transactionId;
    node->dateTime = dateTime;
    node->transactionType = transactionType;
    node->amount = amount;
    node->balance = balance;
    node->next = NULL;
    return node;
}

double getLastBalance(struct Node *ledger) {
    if (ledger == NULL)
        return 0;

    while (ledger->next != NULL)
        ledger = ledger->next;

    return ledger->balance;
}

void newTrans(struct Node **ledger, int transactionId,
              long long dateTime, char transactionType, double amount) {

    double previousBalance = getLastBalance(*ledger);
    double newBalance;

    if (transactionType == 'C')
        newBalance = previousBalance + amount;
    else
        newBalance = previousBalance - amount;

    struct Node *newTransaction =
        createTransaction(transactionId, dateTime,
                          transactionType, amount, newBalance);

    if (*ledger == NULL || dateTime < (*ledger)->dateTime) {
        newTransaction->next = *ledger;
        *ledger = newTransaction;
        return;
    }

    struct Node *current = *ledger;
    while (current->next != NULL && current->next->dateTime <= dateTime) {
        current = current->next;
    }

    newTransaction->next = current->next;
    current->next = newTransaction;
}

void displayLedger(struct Node *ledger) {
    if (ledger == NULL) {
        printf("No transactions exist.\n");
        return;
    }

    printf("\nTransaction History:\n");
    while (ledger != NULL) {
        printf("ID: %d | DateTime: %lld | Type: %c | Amount: %.2lf | Balance: %.2lf\n",
               ledger->transactionId, ledger->dateTime,
               ledger->transactionType, ledger->amount, ledger->balance);
        ledger = ledger->next;
    }
}

int isHighValue(struct Node *ledger, double threshold) {
    while (ledger != NULL) {
        if (ledger->amount > threshold)
            return 1;
        ledger = ledger->next;
    }
    return 0;
}

void lenTypes(struct Node *ledger) {
    int creditCount = 0;
    int debitCount = 0;

    while (ledger != NULL) {
        if (ledger->transactionType == 'C')
            creditCount++;
        else if (ledger->transactionType == 'D')
            debitCount++;
        ledger = ledger->next;
    }

    printf("Num of Credit transactions: %d\n", creditCount);
    printf("Num of Debit transactions: %d\n", debitCount);
}

int main() {
    struct Node *ledger = NULL;
    int choice;

    while (1) {
        printf("\n1.add transaction\n");
        printf("2.display ledger\n");
        printf("3.check highvalue transaction\n");
        printf("4.count credit and debit transactions\n");
        printf("0.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 0)
            break;

        if (choice == 1) {
            int transactionId;
            long long dateTime;
            char transactionType;
            double amount;

            printf("Transaction ID: ");
            scanf("%d", &transactionId);
            printf("DateTime (YYYYMMDDHHMM): ");
            scanf("%lld", &dateTime);
            printf("Transaction type(C/D): ");
            scanf(" %c", &transactionType);
            printf("Amt: ");
            scanf("%lf", &amount);

            newTrans(&ledger, transactionId, dateTime, transactionType, amount);
        }
        else if (choice == 2) {
            displayLedger(ledger);
        }
        else if (choice == 3) {
            double threshold;
            printf("Enter threshold amount: ");
            scanf("%lf", &threshold);

            if (isHighValue(ledger, threshold))
                printf("At least one transaction exceeds the threshold.\n");
            else
                printf("No transaction exceeds the threshold.\n");
        }
        else if (choice == 4) {
            lenTypes(ledger);
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
```