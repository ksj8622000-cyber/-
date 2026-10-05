#pragma once

// 이중 연결 리스트의 노드 구조체 정의
typedef struct ListNode {
    struct ListNode* llink;  // 왼쪽(이전) 노드에 대한 링크
    char data[4];
    struct ListNode* rlink;  // 오른쪽(다음) 노드에 대한 링크
} listNode;

// 리스트 시작을 나타내는 head 노드 구조체 정의
typedef struct {
    listNode* head;
} linkedList_h;

// 함수 선언
linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* DL);
void insertNode(linkedList_h* DL, listNode* pre, char* x);
void deleteNode(linkedList_h* DL, listNode* old);
listNode* searchNode(linkedList_h* DL, char* x);
