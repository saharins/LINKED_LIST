#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;

    Node(int value) 
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList 
{
public:
    Node* head;

    LinkedList() 
    {
        head = nullptr;
    }

    void append(int data) 
    {
        Node* newNode = new Node(data);
        if (!head) 
        {
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next) 
        {
            last = last->next;
        }
        last->next = newNode;
    }

    void deleteNode(int loc) 
    {
        if (!head) return;

        Node* start = head;
        Node* locp = nullptr;

        
        if (loc == 0)
        {
            head = start->next;
            delete start;
            return;
        }

        for (int i = 0; start != nullptr && i < loc; i++) 
        {
            locp = start;
            start = start->next;
        }

        if (!start) return;

        locp->next = start->next;
        delete start;
    }

    void printList() 
    {
        Node* temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() 
{
    LinkedList list;
    int n, data, loc;

    cout << "Enter the number of elements in the list: ";
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> data;
        list.append(data);
    }

    cout << "Original List:" << endl;
    list.printList();

    cout << "Enter the position of the node to delete (starting from 0): ";
    cin >> loc;

    list.deleteNode(loc);
    cout << "\nList after deleting node at position " << loc << ":" << endl;
    list.printList();

    return 0;
}