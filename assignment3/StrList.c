#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

typedef struct Node{
    char* _data;
    struct Node* _next;
}Node;

typedef struct _StrList{
    Node* _head;
    size_t _size;
}StrList;

Node* Node_alloc(const char* data, Node* next){
    Node* p = (Node*)malloc(sizeof(Node));
    if(p){
        p->_next = next;
        p->_data = (char*)malloc((strlen(data)+1)*sizeof(char));
        if(p->_data){
        strcpy(p->_data, data);
        }
        else{return 0;}
    }
    return p;
}

void Node_free(Node* p){
    if(p == NULL){return;}
    free(p->_data);
    free(p);
}

StrList* StrList_alloc(){
    StrList* str = (StrList*)malloc(sizeof(StrList));
    if(str){
        str->_head = NULL;
        str->_size = 0;
    }
    return str;
}

void StrList_free(StrList *StrList){
    if(StrList == NULL){return;}
    Node* p1 = StrList->_head;
    Node* p2;
    while(p1){
        p2 = p1;
        p1 = p1->_next;
        Node_free(p2);
    }
    free(StrList);
}

size_t StrList_size(const StrList *StrList){
    return StrList->_size;
}

void StrList_insertLast(StrList *StrList, const char *data){
    Node* p = Node_alloc(data, NULL);
    if(p == NULL){
        printf("failed\n");
        return;
    }
    if(StrList->_head == NULL){
        StrList->_head = p;
    }
    else{
    Node* p1 = StrList->_head;
    while(p1->_next){
        p1 = p1->_next;
    }
    p1->_next = p;
    }
    StrList->_size++; 
}

void StrList_insertAt(StrList *StrList, const char *data, int index){
    if(index > StrList->_size || index < 0){
        printf("index out of bounds\n");
        return;
    }
    Node* p = Node_alloc(data, NULL);
        if(p == NULL){
            printf("failed\n");
            return;
        }
    if(index){
        Node* p1 = StrList->_head;
        for(int i=0;i<index-1;i++){
            p1 = p1->_next;
        }
        p->_next = p1->_next;
        p1->_next = p;
    }
    else{
        p->_next = StrList->_head;
        StrList->_head = p;
    }
    StrList->_size++;
}

char *StrList_firstData(const StrList *StrList){
    if(StrList->_head == NULL){return NULL;}
    char* ans = (char*)malloc((strlen(StrList->_head->_data)+1)*sizeof(char));
    if(ans == NULL){
        return NULL;
    }
    strcpy(ans, StrList->_head->_data);
    return ans;
}

void StrList_print(const StrList *StrList){
    if(StrList->_head == NULL){
        printf("the list is empty\n");
        return;
        }
    Node* p = StrList->_head;
    while(p){
        printf("%s ", p->_data);
        p = p->_next;
    }    
}

void StrList_printAt(const StrList *StrList, int index){
    if(StrList->_head == NULL){return;}
    if(index >= StrList->_size || index < 0){
        printf("index out of bounds\n");
        return;
    }
    Node* p = StrList->_head;
    for(int i=0;i<index;i++){
        p = p->_next;
    }
    printf("%s\n", p->_data);
}

int StrList_printLen(const StrList *StrList){
    if(StrList->_head == NULL){return 0;}
    int sum = 0;
    Node* p = StrList->_head;
    while(p){
        sum = sum + strlen(p->_data);
        p = p->_next;
    }
    return sum;
}

int StrList_count(StrList *StrList, const char *data){
    if(StrList->_head == NULL){return 0;}
    int count = 0;
    Node* p = StrList->_head;
    while(p){
        count = count + !(strcmp(data, p->_data));
        p = p->_next;
    }
    return count;
}

void StrList_remove(StrList *StrList, const char *data){
    if(StrList->_head == NULL){return;}
    while(!strcmp(StrList->_head->_data, data)){
        Node* p2 = StrList->_head;
        StrList->_head = StrList->_head->_next;
        Node_free(p2);
        StrList->_size--;   
    }
    Node* p = StrList->_head;
    while(p->_next){
        if(!strcmp(p->_next->_data, data)){
            Node* p2 = p->_next;
            p->_next = p->_next->_next;
            Node_free(p2);
            StrList->_size--;
        }
        else{p = p->_next;}       
    }
}

void StrList_removeAt(StrList *StrList, int index){
    if(StrList->_head == NULL){return;}
    if(index<0 || index>=StrList->_size){
        printf("index out of bounds\n");
        return;
    }
    if(index){
        Node* p = StrList->_head;
        for(int i=0;i<index-1;i++){
            p = p->_next;
        }
        Node* p2 = p->_next;
        p->_next = p->_next->_next;
        Node_free(p2);
    }
    else{
        Node* p2 = StrList->_head;
        StrList->_head = StrList->_head->_next;
        Node_free(p2);
    }
    StrList->_size--;
}

int StrList_isEqual(const StrList *StrList1, const StrList *StrList2){
    if(StrList1->_head == NULL && StrList2->_head == NULL){return 1;}
    if(StrList1->_size == StrList2->_size && StrList1->_head && StrList2->_head){
        Node* p1 = StrList1->_head;
        Node* p2 = StrList2->_head;
        while(p1){
            if(strcmp(p1->_data, p2->_data)){
                return 0;
            }
            p1 = p1->_next;
            p2 = p2->_next;
        }
    return 1;
    }
    return 0;
}

StrList *StrList_clone(const StrList *Str){
    StrList* new_str = StrList_alloc();
    Node* p = Str->_head;
    while(p){
        StrList_insertLast(new_str, p->_data);
        p = p->_next;
    }
    return new_str;
}

void StrList_reverse(StrList *Str){
    Node* cur = Str->_head;
    Node* prev = NULL;
    Node* next;
    while(cur){
        next = cur->_next;
        cur->_next = prev;
        prev = cur;
        cur = next;
    }
    Str->_head = prev;
}
int compare(const void* left, const void* right){
    return strcmp(*(char**)left, *(char**)right);
}

void StrList_sort(StrList *StrList){
    if(StrList->_size <= 1){return;}
    char** arr = (char**)malloc(StrList->_size*sizeof(char*));
    if (!arr) {
        // Handle allocation failure
        return;
    }
    Node* p = StrList->_head;
    for(int i=0;i<StrList->_size;i++){
        arr[i] = p->_data;
        p = p->_next;
    }
    int(*cmp)(const void*, const void*);
    cmp = compare;
    qsort(arr, StrList->_size, sizeof(char*), cmp);
    p = StrList->_head;
    for(int i=0;i<StrList->_size;i++){
        p->_data = arr[i];
        p = p->_next;
    }
    free(arr);
}

int StrList_isSorted(StrList *StrList){
    Node* p = StrList->_head;
    while(p && p->_next){
        if(strcmp(p->_data, p->_next->_data) > 0){
            return 0;
        }
        p = p->_next;
    }
    return 1;
}

