#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleLinkedList.h"

// 공백 이중 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
    linkedList_h* DL;

    DL = (linkedList_h*)malloc(sizeof(linkedList_h));
    DL->head = NULL;

    return DL;
}

// 이중 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* DL) {
    listNode* p;

    printf(" DL = (");

    p = DL->head;

    while (p != NULL) {
        printf("%s", p->data);

        p = p->rlink;

        if (p != NULL)
            printf(", ");
    }

    printf(")\n");
}

// pre 뒤에 노드를 삽입하는 연산
void insertNode(linkedList_h* DL, listNode* pre, char* x) {
    listNode* newNode;

    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);

    // 빈 리스트이거나 맨 앞에 삽입하는 경우
    if (DL->head == NULL || pre == NULL) {
        newNode->llink = NULL;
        newNode->rlink = DL->head;

        if (DL->head != NULL)
            DL->head->llink = newNode;

        DL->head = newNode;
    }
    else {
        // pre 뒤에 새 노드 연결
        newNode->rlink = pre->rlink;
        newNode->llink = pre;

        if (pre->rlink != NULL)
            pre->rlink->llink = newNode;

        pre->rlink = newNode;
    }
}

// 이중 연결 리스트에서 노드를 삭제하는 연산
void deleteNode(linkedList_h* DL, listNode* old) {
    if (DL->head == NULL || old == NULL)
        return;

    // 삭제할 노드가 첫 번째 노드인 경우
    if (old == DL->head) {
        DL->head = old->rlink;
    }

    // 이전 노드와 연결
    if (old->llink != NULL)
        old->llink->rlink = old->rlink;

    // 다음 노드와 연결
    if (old->rlink != NULL)
        old->rlink->llink = old->llink;

    // 삭제 노드 메모리 해제
    free(old);
}

// 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(linkedList_h* DL, char* x) {
    listNode* temp;

    temp = DL->head;

    while (temp != NULL) {
        if (strcmp(temp->data, x) == 0)
            return temp;
        else
            temp = temp->rlink;
    }

    return temp;
}
