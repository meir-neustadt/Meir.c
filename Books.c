#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in the linked list
struct Node {
    char Book[18];
    char Author[18];
    char Language;
    int Volumes;
    int Price;
    struct Node* next;
};

// Function to insert a node at the end of the linked list
struct Node* InsertToEnd(struct Node* head, char* B, char* A, char L, int V, int P) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->Book, B);
    strcpy(newNode->Author, A);
    newNode->Language = L;
    newNode->Volumes = V;
    newNode->Price = P;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to display the elements of the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%s |  %s |  %c |  %d |  %d\n", current->Book, current->Author, current->Language, current->Volumes, current->Price);
        current = current->next;
    }
    printf("End\n");
}

int main() {

    struct Node* head = NULL;

    head = InsertToEnd(head,"Politiah", "Platon", 'E', 1, 15);
    head = InsertToEnd(head,"Moreh Han'vuchim", "Maimonides", 'H', 3, 45);
    head = InsertToEnd(head,"Ethics Today", "M. Neustadt", 'E', 1, 30);

    // Display the elements of the linked list
    printf("Books List: \n");
    displayList(head);

    return 0;
}
