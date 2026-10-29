#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedlist
{
private:
    node *head;

public:

    // Constructor
    DoublyLinkedlist()
    {
        head = nullptr;
    }

    // Insert at end
    void insert(int val)
    {
        node *p = new node(val);

        if (head == nullptr)
        {
            head = p;
        }
        else
        {
            node *q = head;

            while (q->next != nullptr)
            {
                q = q->next;
            }

            q->next = p;
            p->prev = q;
        }
    }

    // Delete a node
    void remove(int val)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        node *p;
        node *q = head;

        // Delete first node
        if (q->data == val)
        {
            p = head;
            head = head->next;

            if (head != nullptr)
            {
                head->prev = nullptr;
            }

            delete p;
            return;
        }

        // Delete other nodes
        while (q->next != nullptr)
        {
            if (q->next->data == val)
            {
                p = q->next;

                q->next = p->next;

                if (p->next != nullptr)
                {
                    p->next->prev = q;
                }

                delete p;
                return;
            }

            q = q->next;
        }

        cout << "Value " << val
             << " not found in the list" << endl;
    }

    // Display forward
    void displayForward()
    {
        node *q = head;

        cout << "Forward: ";

        while (q != nullptr)
        {
            cout << q->data << " <-> ";
            q = q->next;
        }

        cout << "NULL" << endl;
    }

    // Display backward
    void displayBackward()
    {
        node *q = head;

        if (q == nullptr)
        {
            cout << "Backward: NULL" << endl;
            return;
        }

        // Go to last node
        while (q->next != nullptr)
        {
            q = q->next;
        }

        cout << "Backward: ";

        // Move backward
        while (q != nullptr)
        {
            cout << q->data << " <-> ";
            q = q->prev;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    DoublyLinkedlist list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    list.displayForward();
    list.displayBackward();

    list.remove(20);

    list.displayForward();
    list.displayBackward();

    return 0;
}


/*PS D:\sagar> cd "d:\sagar\" ; if ($?) { g++ doubly_linked_list.cpp -o doubly_linked_list } ; if ($?) { .\doubly_linked_list }
Forward: 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL
Backward: 50 <-> 40 <-> 30 <-> 20 <-> 10 <-> NULL
Forward: 10 <-> 30 <-> 40 <-> 50 <-> NULL
Backward: 50 <-> 40 <-> 30 <-> 10 <-> NULL
PS D:\sagar> 

*/