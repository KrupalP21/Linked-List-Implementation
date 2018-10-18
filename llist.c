#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LLNode 
{ 
    int data; 
    struct LLNode* next; 
};

struct LLNode* insert(struct LLNode *root, int value);
struct LLNode* delete(struct LLNode *root, int value);


int main() {
int size = 0, value;
char operation;
struct LLNode *root = NULL;
while (scanf("%c %d", &operation, &value) != EOF) {
    size = 0;
    if (operation == 'i') {
        root = insert(root, value);
        struct LLNode *currentNode1 = root;
    struct LLNode *currentNode2 = root;
    while (currentNode2 != NULL) {
        size = size + 1;
        currentNode2 = currentNode2 -> next;
    }
    printf("%d :", size);
    while(currentNode1 != NULL) {
        printf(" %d", currentNode1 -> data);
        currentNode1 = currentNode1 -> next;
    }
printf("\n");
}
if (operation == 'd') {
root = delete(root, value);
struct LLNode *currentNode3 = root;
struct LLNode *currentNode4 = root;
while (currentNode3 != NULL) {
size = size + 1;
currentNode3 = currentNode3 -> next;
}
printf("%d :", size);
while (currentNode4 != NULL) {
printf(" %d", currentNode4 -> data);
currentNode4 = currentNode4 -> next;
}
printf("\n");
}
operation = '#';
}
return 0;
}


struct LLNode* insert(struct LLNode* root, int value) {
    struct LLNode *currentNode = root;
    struct LLNode *currentNode2 = root;
   // struct LLNode *prevNode = NULL;
    struct LLNode *newNode = (struct LLNode*)malloc(sizeof(struct LLNode));
    newNode -> data = value;
    newNode -> next = NULL;
    if (root == NULL) {
        root = newNode;
        return root;
    }
    if ((root -> data) == value){
    return root;
    }
    if (root -> data > value) {
        newNode -> next = root;
        root = newNode;
        return root;
    }
    while (currentNode2 -> next != NULL && currentNode2 -> data < value) {
        currentNode2 = currentNode2 -> next;
    }
    if (value > currentNode2 -> data) {
        currentNode2 -> next = newNode;
        return root;
    }
//	struct LLNode *prevNode = NULL;
    /* if input belongs in between two numbers */
// struct LLNode *prevNode = NULL;  
 while (currentNode -> next != NULL && currentNode -> next -> data < value ) {
        currentNode = currentNode -> next;
        }
        newNode -> next = currentNode -> next;
        currentNode -> next = newNode;
	return root;  
}

struct LLNode* delete(struct LLNode* root, int value) {
//delete root
//delete random element
//nothing to delete
if (root == NULL) {
return root;
}
if (root -> data == value) {
root = root -> next;
return root;
}
root -> next = delete((struct LLNode*)root-> next,value);
return root;
}
