#include <stdio.h>
#include <stdlib.h>

struct packet{
    int packet_id;
    int datasize;
};

struct packet* createPacket(int id, int dataSize){
    struct packet *newNode = malloc(sizeof(struct packet));
    newNode->packet_id = id;
    newNode->datasize = dataSize;
    return newNode;
}



void display(struct packet* buffer[], int size){
    printf("\nBuffer State:\n");
    for(int i = 0; i < size; i++){
        if(buffer[i] == NULL){
            printf("Slot %d: EMPTY\n", i);
        } else {
            printf("Slot %d -> ID: %d | Size: %d\n",
                   i,
                   buffer[i]->packet_id,
                   buffer[i]->datasize);
        }
    }
}

void enqueue(struct packet* buffer[], int size, int *front, int *rear, struct packet *data){
    if((*front == 0 && *rear == size - 1) ||
       (*rear + 1 == *front)){
        printf("Buffer FULL! Packet dropped.\n");
        return;
    }

    

    if(*front == -1){
        *front = 0;
        *rear = 0;
    }
    else{
        *rear = (*rear + 1) % size;
    }

    buffer[*rear] = data;
}

void dequeue(struct packet* buffer[], int size, int *front, int *rear){
    if(*front == -1){
        printf("Buffer EMPTY\n");
        return;
    }

    free(buffer[*front]);
    buffer[*front] = NULL;

    if(*front == *rear){
        *front = -1;
        *rear = -1;
    }
    else{
        *front = (*front + 1) % size;
    }
}

int main(){
    int size = 5;
    struct packet* buffer[5];

    for(int i = 0; i < size; i++)
        buffer[i] = NULL;

    int front = -1, rear = -1;



	//MENU
	system("clear");
	printf("----ROUTER 192.168.0.1----\n");
	int cmd;
	printf("0. EXIT PROGRAM\n");
	printf("1. Display packet queue\n");
	printf("2. Register a new packet\n");
	printf("3. Process a packet\n");
	
	int running=1;
	while(running){
		printf("Enter your choice: ");
		scanf("%d",&cmd);
		getchar();

		switch (cmd) {
			case 0:
				printf("Bye !\n");
				running=0;
				break;
			case 1:
				display(buffer,size);
				break;
			case 2:
				int t_ID,t_size;
				printf("Enter the packetID: ");
				scanf("%d", &t_ID);
				printf("Enter datasize: ");
				scanf("%d", &t_size);
				enqueue(buffer, size, &front, &rear, createPacket(t_ID, t_size));
				printf("Packet Enqueued Successfully!\n");
				display(buffer, size);
				break;
			case 3:
				dequeue(buffer, size, &front, &rear);
				printf("Packet Processed!!\n");
				display(buffer, size);
				break;


		}
	}

	/*
    enqueue(buffer, size, &front, &rear, createPacket(1, 1024));
    enqueue(buffer, size, &front, &rear, createPacket(2, 2048));
    enqueue(buffer, size, &front, &rear, createPacket(3, 512));

    display(buffer, size);

    dequeue(buffer, size, &front, &rear);
    display(buffer, size);

    enqueue(buffer, size, &front, &rear, createPacket(4, 10));
    enqueue(buffer, size, &front, &rear, createPacket(5, 20));
    */
    return 0;
}

