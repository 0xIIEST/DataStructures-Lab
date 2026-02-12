#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    int song_id;
    char title[50];
    char artist[50];
    struct Song *prev;
    struct Song *next;
};

struct Song* createSong(int id, char title[], char artist[]) {
    struct Song *newSong = malloc(sizeof(struct Song));
    newSong->song_id = id;
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->prev = NULL;
    newSong->next = NULL;
    return newSong;
}

void addSong(struct Song **head, struct Song **tail, int id, char title[], char artist[]) {
    struct Song *newSong = createSong(id, title, artist);
    if (*head == NULL) {
        *head = newSong;
        *tail = newSong;
        return;
    }

    (*tail)->next = newSong;
    newSong->prev = *tail;
    *tail = newSong;
}

void deleteSong(struct Song **head, struct Song **tail, int id) {
    if (*head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    struct Song *temp = *head;

    while (temp != NULL && temp->song_id != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song not found.\n");
        return;
    }

    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        else
            *tail = NULL;
    }
    else if (temp == *tail) {
        *tail = temp->prev;
        (*tail)->next = NULL;
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Song deleted.\n");
}

void playNext(struct Song **current) {
    if (*current == NULL) {
        printf("Playlist empty.\n");
        return;
    }

    if ((*current)->next != NULL) {
        *current = (*current)->next;
        printf("Playing: %s\n", (*current)->title);
    } else {
        printf("End of Playlist\n");
    }
}

void playPrevious(struct Song **current) {
    if (*current == NULL) {
        printf("Playlist empty.\n");
        return;
    }

    if ((*current)->prev != NULL) {
        *current = (*current)->prev;
        printf("Playing: %s\n", (*current)->title);
    } else {
        printf("Start of Playlist\n");
    }
}

void showPlaylist(struct Song *head) {
    if (head == NULL) {
        printf("Playlist empty.\n");
        return;
    }

    struct Song *temp = head;
    while (temp != NULL) {
        printf("ID: %d | %s - %s\n", temp->song_id, temp->title, temp->artist);
        temp = temp->next;
    }
}

void showReversePlaylist(struct Song *tail) {
    if (tail == NULL) {
        printf("Playlist empty.\n");
        return;
    }

    struct Song *temp = tail;
    while (temp != NULL) {
        printf("ID: %d | %s - %s\n", temp->song_id, temp->title, temp->artist);
        temp = temp->prev;
    }
}

int main() {
    struct Song *head = NULL;
    struct Song *tail = NULL;
    struct Song *current = NULL;

    int running = 1;

    while (running) {
        int cmd;
        printf("\n\n1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Play Next\n");
        printf("4. Play Previous\n");
        printf("5. Show Playlist\n");
        printf("6. Show Reverse Playlist\n");
        printf("0. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &cmd);

        switch (cmd) {
            case 0:
                running = 0;
                break;

            case 1: {
                int id;
                char title[50], artist[50];
                printf("Enter Song ID: ");
                scanf("%d", &id);
                getchar();
                printf("Enter Title: ");
                scanf("%[^\n]", title);
                getchar();
                printf("Enter Artist: ");
                scanf("%[^\n]", artist);
                addSong(&head, &tail, id, title, artist);
                if (current == NULL)
                    current = head;
                break;
            }

            case 2: {
                int id;
                printf("Enter Song ID to delete:");
                scanf("%d", &id);
                if (current != NULL && current->song_id == id)
                    current = current->next;
                deleteSong(&head, &tail, id);
                break;
            }

            case 3:
                playNext(&current);
                break;

            case 4:
                playPrevious(&current);
                break;

            case 5:
                showPlaylist(head);
                break;

            case 6:
                showReversePlaylist(tail);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
