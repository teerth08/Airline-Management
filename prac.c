#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Student{
    char name[20];
    int id;
    float marks;
    struct Student *next;
};

struct Student *read_new_student(char name[], int id, float marks){
    struct Student *s1 = (struct Student*) malloc (sizeof(struct Student));
    strcpy(s1->name, name);
    s1->id = id;
    s1->marks = marks;
    s1->next = NULL;
    return s1;
}

struct Student *insert_student_byid(struct Student *head, struct Student *newNode){
    struct Student *currNode = head;
    if (head == NULL){
        head = newNode;
    }
    else{
        while(currNode->next != NULL){
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
    return head;
}

void sortLL(struct Student *head){
    char tempname[20];
    int tempid;
    float tempmarks;
    struct Student *newNode=head;
    struct Student *idx=NULL;
    if (head==NULL){
        return;
    }
    else{
        while(newNode!=NULL){
            idx=newNode->next;
            while(idx!=NULL){
                if (newNode->id > idx->id){
                    tempid=newNode->id;
                    tempmarks=newNode->marks;
                    strcpy(tempname, newNode->name);
                    newNode->id=idx->id;
                    newNode->marks=idx->marks;
                    strcpy(newNode->name, idx->name);
                    idx->id=tempid;
                    idx->marks=tempmarks;
                    strcpy(idx->name, tempname);
                }
                idx=idx->next;
            }
            newNode=newNode->next;
        }
    }
}

struct Student *delete_student(struct Student *head, int id){
    struct Student *currNode=head;
    if (head==NULL){
        return head;
    }
    if (currNode->id == id){
        head = head->next;
        free(currNode);
        return head;
    }
    while(currNode->next!=NULL){
        if (currNode->next->id==id){
            struct Student *nodeToDelete = currNode->next;
            currNode->next = nodeToDelete->next;
            free(nodeToDelete);
            break;
        }
        currNode=currNode->next;
    }
    return head;
}

void print_student_list(struct Student *head){
    struct Student *currNode = head;
    while(currNode!=NULL){
        printf("%s %d %.2f\n", currNode->name, currNode->id, currNode->marks);
        currNode = currNode->next;
    }
}

int main(){
    struct Student *head=NULL;
    int n;
    scanf("%d", &n);
    while(n--){
        char name1[20];
        int id1;
        float marks1;
        scanf("%s %d %f", name1, &id1, &marks1);
        struct Student *s1 = read_new_student(name1, id1, marks1);
        head = insert_student_byid(head, s1);
    }
    sortLL(head);
    print_student_list(head);
    int i;
    scanf("%d", &i);
    while(i!=0){
        head = delete_student(head, i);
        print_student_list(head);
        scanf("%d", &i);
    }
    return 0;
}
