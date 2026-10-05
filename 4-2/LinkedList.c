#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

// ... (007~082행 생략 : 예제 4-1의 insertLinkedList.c 구현 부분)

// 리스트에서 노드 p를 삭제하는 연산
void deleteNode(linkedList_h* L, listNode* p) {
    listNode* pre;                    // 삭제할 노드의 선행자 노드를 나타낼 포인터
    if (L->head == NULL) return;      // 공백 리스트라면 삭제 연산 중단
    if (L->head->link == NULL) {     // 리스트에 노드가 한 개만 있는 경우
        free(L->head);                // 첫 번째 노드를 메모리에서 해제
        L->head = NULL;               // 리스트 시작 포인터를 NULL로 설정
        return;
    }
    else if (p == NULL) return;       // 삭제할 노드가 없다면 삭제 연산 중단
    else {                            // 삭제할 노드 p의 선행자 노드를 포인터 pre를 이용해 찾음
        pre = L->head;
        while (pre->link != p) {
            pre = pre->link;
        }
        pre->link = p->link;          // 삭제할 노드 p의 선행자 노드와 다음 노드를 연결
        free(p);                      // 삭제 노드의 메모리 해제
    }
}

// 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(linkedList_h* L, char* x) {
    listNode* temp;
    temp = L->head;
    while (temp != NULL) {
        if (strcmp(temp->data, x) == 0) return temp;
        else temp = temp->link;
    }
    return temp;
}

// 리스트의 노드 순서를 역순으로 바꾸는 연산
void reverse(linkedList_h* L) {
    listNode* p;
    listNode* q;
    listNode* r;

    p = L->head;                      // 포인터 p를 첫 번째 노드에 설정
    q = NULL;
    r = NULL;

    // 리스트의 첫 번째 노드부터 링크를 따라 다음 노드로 이동하면서 노드 간의 연결을 바꿈
    while (p != NULL) {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    L->head = q;
}
