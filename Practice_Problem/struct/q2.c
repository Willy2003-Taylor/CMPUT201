#include<stdio.h>
#include<stdlib.h>

/*Practice Problem:Consider a linked list that keeps the list of students enrolled in a course.
 The structure of each Student in the list is as given, and the head of the linked list is defined in a struct called StudentList.
 If the list is empty, then head is NULL.
 
 Write three functions for this question: createStudentList, insertStudent, and reverse.
 You must dynamically allocate memory for each node. 
 There is no maximum size for the length of each student name so student names must also
 be dynamically allocated.
 
 You can assume that any list passed to insertStudent or reverse has been created using createStudentList.*/

struct Student{
    char* name;
    float grade;
    struct Student* next;
};

struct StudentList{
    struct Student* head;
};

struct StudentList* createStudentList(){
    struct StudentList* new_list = malloc(sizeof(struct StudentList));

    new_list->head = NULL;

    return new_list;
}

struct StudentList* insertStudent(struct StudentList* studentList, char* name, float grade){
    struct Student* new_student = malloc(sizeof(struct Student));

    if(!new_student){
        printf("Initialization Error.");
        return NULL;
    }

    new_student->name = name;
    new_student->grade = grade;
    new_student->next = NULL;

    if(!studentList->head) studentList->head = new_student;

    else{
        struct Student* current = studentList->head;

        while(current->next)
            current = current->next;
    
        current->next = new_student;
    }    

    return studentList;
    
}

struct StudentList* reverse(struct StudentList* studentList){
    struct Student* current = studentList -> head;
    struct Student* next = NULL;
    struct Student* prev = NULL;

    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    studentList->head = prev;

    return studentList;

}

void printList(struct StudentList* studentList){
    struct Student* current = studentList->head;
    while(current){
        printf("%s %.1f ", current->name, current->grade);
        current = current->next;
    }

    printf("\n");
}

void delete_node(struct Student* n){
    if(!n) return;

    delete_node(n->next);

    free(n);
}

void delete_list(struct StudentList* l){
    if(!l) return;

    delete_node(l->head);

    free(l);
}

int main(){
    struct StudentList* StudentList = createStudentList();
    insertStudent(StudentList, "Alice", 3.7);
    insertStudent(StudentList, "Bob", 3.2);
    insertStudent(StudentList, "Mark", 3.6);

    reverse(StudentList);

    printf("\n");

    printList(StudentList);

    delete_list(StudentList);

    printf("Deletion is completed.\n");

    return 0;
}