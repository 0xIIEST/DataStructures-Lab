#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
                int ID;
                char name[25];
                int age;
                char gender; //M / F
                int priority;
                struct Node *next;
        };

struct Node* createNode(int ID, char name[], int age, char gender, int priority){
	struct Node *newNode= malloc(sizeof(struct Node));
	newNode->ID=ID;
	strcpy(newNode->name,name);
	newNode->age=age;
	newNode->gender=gender;
	newNode->priority=priority;
	newNode->next=NULL;

	return newNode;
}

void append(struct Node **head, int ID, char name[], int age, char gender, int priority){
	struct Node *newNode = createNode(ID,name,age,gender,priority);

	struct Node *temp = *head;
	while(temp->next !=NULL){
		temp=temp->next;
	}
	temp->next=newNode;
}

void addAtStart(struct Node **head, int ID, char name[], int age, char gender, int priority){
	struct Node *temp = createNode(ID,name,age,gender,priority);
	
	temp->next=*head;
	*head=temp;
}

void display(struct Node **head){
	struct Node *temp = *head;
	system("clear");
	while(temp !=NULL){
		printf("Record Found:\n");
        printf("ID: %d\n", temp->ID);
        printf("Name: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Gender: %c\n", temp->gender);
        printf("Priority: %d\n", temp->priority);
		printf("--------------------------------\n");
		temp=temp->next;
	}
	printf("Record Found:\n");
}

void search(struct Node **head, int value) {
    struct Node *temp = *head;
	system("clear");
    while (temp != NULL) {
        if (temp->ID == value) {
            printf("Record Found:\n");
            printf("ID: %d\n", temp->ID);
            printf("Name: %s\n", temp->name);
            printf("Age: %d\n", temp->age);
            printf("Gender: %c\n", temp->gender);
            printf("Priority: %d\n", temp->priority);
            return;
        }
        temp = temp->next;
    }
    printf("Record not found.\n", value);
}

void priorityInsert(struct Node **head, int ID, char name[], int age,char gender, int priority){
    struct Node *newNode = createNode(ID, name, age, gender, priority);
    if (*head == NULL || priority > (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL && temp->next->priority >= priority) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
	return;
}

int idExists(struct Node **head, int ID){
	struct Node *temp=*head;
	int flag=0;
	while(temp!=NULL){
		if(temp->ID==ID){
			flag=1;
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}

void pop(struct Node **head, int ID) {
    if (*head == NULL) {//empty head
        printf("empty lisst.\n");
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;
    if (temp->ID == ID) {
        *head = temp->next;
        free(temp);//remove the node ffrom memory
        printf("Patient removed.\n", ID);
        return;
    }
    while (temp != NULL && temp->ID != ID) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Patient not found.\n", ID);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Patient removed.\n", ID);
}




int main(){
	system("clear");
	struct Node *head = createNode(1, "John Doe", 18, 'M', 2);
	append(&head, 2, "Jane", 21, 'F', 1);
	
	
	int running=1;	
	printf("           Welcome To XYZ Hospital\n");
	//Control Panel
	while(running){
		int cmd;
		printf("\nChoose your operation: \n");
		printf("1. Display Records\n");
		printf("2. Search By ID\n");
		printf("3. New Entry\n");
		printf("4. Remove by ID: \n");
		printf("0. Quit\n");
		//more functions
		printf("\n\nCommand Number: ");
		scanf("%d",&cmd);
	
		switch(cmd) {
			case 0:
				printf("Goodbye!\n");
				running=0;
				break;
		
			case 1:
				display(&head);
				break;
			case 2:
				printf("Enter the ID to search: ");
				int temp;
				scanf("%d",&temp);
				search(&head,temp);
				break;
			case 3://new entry
				int t_ID, t_priority, t_age;
				char t_name[25], t_gender;
				printf("Enter Patient ID:");
				scanf("%d",&t_ID);
				getchar();
				printf("Enter name:");
				scanf("%[^\n]", &t_name);
				getchar();
				printf("Enter Age: ");
				scanf("%d",&t_age);
				printf("Enter Gender: ");
				scanf("%c",&t_gender);
				getchar();
				printf("Enter Priority: ");
				scanf("%d",&t_priority);
				if(idExists(&head,t_ID)){
					printf("ID Already Exists! \n");
					break;
				}
				priorityInsert(&head, t_ID, t_name, t_age, t_gender, t_priority);
				break;
			case 4:
				int t2_ID;
				printf("Enter patient id to remove: ");
				scanf("%d",&t2_ID);
				pop(&head,t2_ID);
				break;
	
			default:
				printf("Enter a valid command!");
				break;
		}
	}
	return 0;
}
