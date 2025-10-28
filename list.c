#include "list.h"
#include <stddef.h>
#include <stdlib.h>

struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

struct ll_node *ll_tail(struct ll_node *head) {
    if (head == NULL) return NULL;
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

int ll_size(struct ll_node *head) {
    int count = 0;
    for (struct ll_node *p = head; p != NULL; p = p->next) {
        count++;
    }
    return count;
}

struct ll_node *ll_find(struct ll_node *head, int value) {
    for (struct ll_node *p = head; p != NULL; p = p->next) {
        if (p->data == value) return p;
    }
    return NULL;
}

int *ll_toarray(struct ll_node *head) {
    int n = ll_size(head);
    if (n == 0) return NULL;
    int *arr = (int *)malloc(sizeof(int) * n);
    if (arr == NULL) return NULL;
    int i = 0;
    for (struct ll_node *p = head; p != NULL; p = p->next) {
        arr[i++] = p->data;
    }
    return arr;
}

struct ll_node *ll_create(int data) {
    struct ll_node *node = (struct ll_node *)malloc(sizeof(struct ll_node));
    if (node == NULL) return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

void ll_destroy(struct ll_node *head) {
    while (head != NULL) {
        struct ll_node *next = head->next;
        free(head);
        head = next;
    }
}

void ll_append(struct ll_node *head, int data) {
    if (head == NULL) return;
    struct ll_node *tail = ll_tail(head);
    struct ll_node *node = ll_create(data);
    if (node == NULL) return;
    tail->next = node;
}

struct ll_node *ll_fromarray(int* data, int len) {
    if (data == NULL || len <= 0) return NULL;
    struct ll_node *head = ll_create(data[0]);
    if (head == NULL) return NULL;
    struct ll_node *tail = head;
    for (int i = 1; i < len; i++) {
        struct ll_node *node = ll_create(data[i]);
        if (node == NULL) {
            ll_destroy(head);
            return NULL;
        }
        tail->next = node;
        tail = node;
    }
    return head;
}

struct ll_node *ll_remove(struct ll_node *head, int value) {
    if (head == NULL) return NULL;
    if (head->data == value) {
        struct ll_node *new_head = head->next;
        free(head);
        return new_head;
    }
    struct ll_node *prev = head;
    struct ll_node *curr = head->next;
    while (curr != NULL) {
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}
