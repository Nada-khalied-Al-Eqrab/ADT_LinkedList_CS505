//nada khaled Said- 2002400208
#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

class list {
//----------- data members -----------
private:
    class node {
    public:
        int key;
        char data;
        node* next;
    };
    node* head = nullptr ;
    node* cursor = nullptr ;
    node* prev = nullptr ;
//----------- function members ---------
public:
    list();
    ~list();
    bool listIsEmppty();
    bool cursorIsEmpty();
    void toFirst();
    bool atFirst();
    void advance();
    void toEnd();
    bool atEnd();
    int listSize();
    void updateData(char d);
    void updateKey(int k);
    char retrieveData();
    void retrieveData(char &);
    int retrieveKey();
    void retrieveKey(int &);
    void insertFirst(int, char);
    void inserAfter(int, char);
    void inserbefore(int, char);
    void inserEnd(int, char);
    void deleteNode();
    void deletefrist();
    void deletend();
    void makelistempty();
    bool search(int k);
    void orderInsert(int k, char d);
    void traverse();
};

#endif // LIST_H_INCLUDED
