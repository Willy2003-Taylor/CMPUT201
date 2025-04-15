#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct Node{
    int data;
    struct Node* next;
};

struct List{
    struct Node* head;
    size_t length;
};

struct List* createList(){
    struct List* new_list = malloc(sizeof(struct List));

    new_list->head = NULL;
    new_list->length = 0;

    return new_list;
}

struct List* addToFront(struct List* l, int value){
    struct Node* new_node = malloc(sizeof(struct Node));

    new_node->data = value;
    new_node->next = l->head;
    l->head = new_node;
    l->length += 1;

    return l;
}

int ith_element(struct List* l, int index){
    assert(index < l->length);

    struct Node* current = l->head;
    for(int i = 0; i < index; ++i, current = current->next);

    return current->data;

}

int set_ith_Elem(struct List* l, int index, int value){
    assert(index < l->length);

    struct Node* current = l->head;
    for(int i = 0; i < index; ++i, current = current->next);

    current->data = value;

    return current->data;
}

struct List* remove_ith_Elem(struct List* l, int index){
    assert(index < l->length);

    if(index == 0){
        struct Node* tmp = malloc(sizeof(struct Node));

        tmp = l->head;

        l->head = tmp->next;

        free(tmp);

        l->length -= 1;

        return l;
    }

    struct Node* current = l->head;
    struct Node* prev = NULL;

    for(int i = 0; i < index; ++i, current = current->next);

    prev = current;
    prev->next = current->next;

    free(current);

    l->length -= 1;

    return l;
}

void delete_node(struct Node* n){
    if(!n) return;

    delete_node(n->next);

    free(n);
}

void delete_list(struct List* l){
    if(!l) return;

    delete_node(l->head);

    free(l);
}

int main(){
    struct List* l = createList();

    printf("Input the number of nodes: ");

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i)
        addToFront(l, n - 1 - i);

    for(int i = 0; i < l->length; ++i)
        printf("The %dth element is: %d ", i+1, ith_element(l, i));

    delete_list(l);

    printf("\n");

    printf("Deletion is completed.");

    printf("\n");

    return 0;
}