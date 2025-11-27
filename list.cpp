//nada khaled Said- 2002400208
#include "list.h"
#include <iostream>
using namespace std;
list::list() {
    head = cursor = prev = nullptr;
}
list::~list() {
makelistempty();
}

bool list::listIsEmppty() {
    return (head == nullptr);
}

bool list::cursorIsEmpty() {
    return (cursor == nullptr);
}

void list::toFirst() {
    cursor = head;
    prev = nullptr;
}

bool list::atFirst() {
    if (listIsEmppty()) {
        return cursorIsEmpty();
    }
    return (cursor == head);
}

void list::advance() {
    if (cursor != nullptr) {
        prev = cursor;
        cursor = cursor->next;
    }
}

void list::toEnd() {
    if (!listIsEmppty()) {
        toFirst();
        while (cursor->next != nullptr)
            advance();
    }
}

bool list::atEnd() {
    if (listIsEmppty())
        return cursorIsEmpty();
    return (cursor != nullptr && cursor->next == nullptr);
}

int list::listSize() {

    int count = 0;
    node* p = head;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}

void list::updateData(char d) {
    if (cursor != nullptr)
        cursor->data = d;
}

void list::updateKey(int k) {
    if (cursor !=nullptr)
        cursor->key = k;
}

char list::retrieveData() {
    if (cursor != nullptr)
        return cursor->data;
    return '\0';
}

void list::retrieveData(char &x) {
    if (cursor != nullptr)
        x = cursor->data;
}

int list::retrieveKey() {
    if (cursor != nullptr)
        return cursor->key;
    return -1;
}

void list::retrieveKey(int &x) {
    if (cursor != nullptr)
        x = cursor->key;
}

void list::insertFirst(int k, char d) {
    node* b = new node;
    b->key = k;
    b->data = d;
    b->next = head;
    head = b;
    cursor = head;
    prev = nullptr;
}

void list::inserAfter(int k, char d) {
    if (cursor == nullptr) {
        insertFirst(k, d);
        return;
    }

    node* b = new node;
    b->key = k;
    b->data = d;
    b->next = cursor->next;
    cursor->next = b;

    prev = cursor;
    cursor = b;
}

void list::inserbefore(int k, char d) {
    if (cursor == head || cursor == nullptr) {
        insertFirst(k, d);
        return;
    }

    node* b = new node;
    b->key = k;
    b->data = d;

    prev->next = b;
    b->next = cursor;

    cursor = b;
}

void list::inserEnd(int k, char d) {
    if (listIsEmppty()) {
        insertFirst(k, d);
    } else {
        toEnd();
        inserAfter(k, d);
    }
}

void list::deleteNode() {
    if (cursor == nullptr)
        return;

    node* p = cursor;

    if (cursor == head) {
        head = head->next;
        cursor = head;
        prev = nullptr;
        delete p;
    }
    else {
        prev->next = cursor->next;
        cursor = cursor->next;
        delete p;
    }
}

void list::deletefrist() {
    if (!listIsEmppty()) {
        toFirst();
        deleteNode();
    }
}

void list::deletend() {
    if (!listIsEmppty()) {
        toEnd();
        deleteNode();
    }
}

void list::makelistempty() {
    toFirst();
    while (cursor != nullptr) {
        deleteNode();
    }
}

bool list::search(int k) {
    if (listIsEmppty()) return false;

    toFirst();
    while (cursor != nullptr) {
        if (cursor->key == k)
            return true;
        advance();
    }
    return false;
}

void list::orderInsert(int k, char d) {

    if (listIsEmppty() || k < head->key) {
        insertFirst(k, d);
        return;
    }

    toFirst();
    while (cursor->next != nullptr && cursor->next->key < k)
        advance();

    inserAfter(k, d);
}
void list::traverse() {
    node* p = head;

    while (p != nullptr) {
        cout << "(" << p->key << ", " << p->data << ") -> ";
        p = p->next;
    }
}
