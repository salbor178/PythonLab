#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TITLE_LENGTH 100
#define DIRECTOR_LENGTH 100

struct Movie
{
    char title[TITLE_LENGTH];
    int year;
    char director[DIRECTOR_LENGTH];
} Movie;

struct Node
{
    struct Movie movie;
    struct Node* next;
};

struct Node* createNode(const char *title, int year, const char *director)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocator failer\n");
        exit(1);
    }
    
    strncpy(newNode->movie.title, title, TITLE_LENGTH);
    newNode->movie.title[TITLE_LENGTH - 1] = '\0';
    newNode->movie.year = year;
    strncpy(newNode->movie.director, director, DIRECTOR_LENGTH);
    newNode->movie.director[DIRECTOR_LENGTH - 1] = '\0';
    return (newNode);
}

void insertAtBeginning(struct Node** head, char *title, int year, char *director)
{
    struct Node* newNode = createNode(title, year, director);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, char *title, int year, char *director)
{
    struct Node* newNode = createNode(title, year, director);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp-> next;
    }
    temp->next = newNode;    
}

void deleteByTitle(struct Node** head, char *title)
{
    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp != NULL && strcmp(temp->movie.title, title) != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("movie not found\n");
    }
    if (prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);    
}

int searchByTitle(struct Node* head, char *title)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->movie.title, title) == 0)
        return (1);
        
        temp = temp->next;
    }
    return (0);    
}
void displayList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("Title: %s, year: %d, director: %s\n", temp->movie.title, temp->movie.year, temp->movie.director);
        temp = temp->next;
    }    
}

void freeList(struct Node* head)
{
    struct Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void)
{
    struct Node* head = NULL;
    insertAtEnd(&head, "Inception", 2010, "Christopher Nolan");
    insertAtEnd(&head, "The Matrix", 1999, "The Wachowskis");
    insertAtBeginning(&head, "Iron Man", 2008, "Jon favreau");

    printf("Movie List:\n");
    displayList(head);

    printf("\nSearching for Inception: %s\n", searchByTitle(head, "Inception") ? "Found" : "Not Found");

    printf("\nDeleting 'The Matrix'.\n");
    deleteByTitle(&head, "The Matrix");
    displayList(head);

    freeList(head);

    system("pause");
    return (0);
}

