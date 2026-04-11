#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at end (for testing)
void insert(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL) {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

// 1. Delete from beginning
void delete_from_beginning() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);
}

// 2. Delete end node
void delete_end() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// 3. Delete node with given data
void delete_given(int data) {
    if(head == NULL) {
        printf("List empty\n");
        return;
    }

    // if first node
    if(head->data == data) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL && temp->next->data != data)
        temp = temp->next;

    if(temp->next == NULL) {
        printf("Data not found\n");
        return;
    }

    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
}

// 4. Traverse
void traverse() {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main
int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    traverse();

    delete_from_beginning();
    traverse();

    delete_end();
    traverse();

    delete_given(20);
    traverse();

    return 0;
}