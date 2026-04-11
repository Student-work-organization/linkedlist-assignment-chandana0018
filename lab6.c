#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Insert at end (for testing)
void insert(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

// 1. Delete node with given data (first occurrence)
void delete_node(int data) {
    if(head == NULL) {
        printf("List empty\n");
        return;
    }

    struct node *temp = head;

    // find node
    while(temp != NULL && temp->data != data)
        temp = temp->next;

    if(temp == NULL) {
        printf("Data not found\n");
        return;
    }

    // if first node
    if(temp == head) {
        head = temp->next;
        if(head != NULL)
            head->prev = NULL;
    }
    else {
        temp->prev->next = temp->next;
        if(temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
}

// 2. Delete end node
void delete_end() {
    if(head == NULL) {
        printf("List empty\n");
        return;
    }

    struct node *temp = head;

    // only one node
    if(temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// 3. Delete node with given data (same as 1)
void delete_given(int data) {
    delete_node(data);
}

// 4. Traverse backward
void traverse_backward() {
    if(head == NULL) {
        printf("List empty\n");
        return;
    }

    struct node *temp = head;

    // go to last node
    while(temp->next != NULL)
        temp = temp->next;

    // traverse backward
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main
int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    traverse_backward();

    delete_node(20);
    traverse_backward();

    delete_end();
    traverse_backward();

    delete_given(10);
    traverse_backward();

    return 0;
}