#include <stdio.h>
#include <stdlib.h>
//원형리스트를 메뉴로 조작하는 프로그램 작성
typedef int element;
typedef struct LIstNode {
	element data;
	struct LIstNode* link;
}ListNode;


ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}
ListNode* delete_first(ListNode* head) {
	if (head == NULL) {
		printf("리스트가 비어 있습니다.\n");
		return NULL;
	}
	ListNode* removed = head->link;
	if (removed == head) {
		free(removed);
		return NULL;
	}
	head->link = removed->link;
	free(removed);
	return head;
}

ListNode* delete_last(ListNode* head) {
	if (head == NULL) {
		printf("리스트가 비어 있습니다.\n");
		return NULL;
	}
	ListNode* prev = head;
	ListNode* curr = head->link;
	while (curr->link != head->link) {
		prev = curr;
		curr = curr->link;
	}
	if (prev == curr) {
		free(curr);
		return NULL;
	}
	prev->link = curr->link;
	free(curr);
	return prev;
}
void print_list(ListNode* head) {
	ListNode* p;
	if (head == NULL)return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d -> \n", p->data);
}
void menu() {
	printf("메뉴:\n");
	printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
	printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
	printf("3. 리스트 처음 노드 삭제\n");
	printf("4. 리스트 마지막 노드 삭제\n");
	printf("5. 리스트 프린트\n");
	printf("6. 종료\n");
}

int main() {
	ListNode* head = NULL;
	int choice;
	element data;
	while (1) {
		menu();
		printf("메뉴를 선택하세요: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("숫자 입력: ");
			scanf_s("%d", &data);
			head = insert_first(head, data);
			break;
		case 2:
			printf("숫자 입력: ");
			scanf_s("%d", &data);
			head = insert_last(head, data);
			break;
		case 3:
			head = delete_first(head);
			break;
		case 4:
			head = delete_last(head);
			break;
		case 5:
			print_list(head);
			break;
		case 6:
			printf("프로그램을 종료합니다.\n");
			exit(0);
		default:
			printf("잘못된 입력입니다. 다시 선택하세요.\n");
			break;
		}
	}
}

