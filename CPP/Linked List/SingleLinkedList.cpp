#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList
{
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList()
    {
        head = tail = nullptr;
        size = 0;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            tail = head = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }
        // Case 1: delete head
        if (index == 0)
        {
            Node *to_del = head;
            head = head->next;
            if (head == NULL)
                tail = NULL;
            delete to_del;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            Node *to_del = temp->next;
            temp->next = to_del->next;
            if(to_del==tail){ // if deleting tail
                tail = temp;
            }
            delete to_del;
        }
        size--;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val;
            if (temp->next != NULL)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    list.addAtHead(20);
    list.addAtHead(10);
    list.addAtTail(30);
    list.addAtTail(40);

    list.print();

    // list.deleteAtIndex(2);
    list.deleteAtIndex(0);
    // list.deleteAtIndex(3);

    list.print();
    return 0;
}
