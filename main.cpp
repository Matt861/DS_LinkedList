// Authors: Matt Windham 51 & Kevin Kim
// Due date: 3/8/17
// Programming Assignment Number 4
// Spring 2017 - CS 3358 - Section Number 2
//
// Instructor: Husain Gholoom
//
//


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class IntList
{
private:
    struct IntNode
    {
        int integer;
        IntNode *next;
    };
    
    IntNode *head, *tail;
    
public:
    IntList();
    ~IntList();
    
    //int mainList(int);
    int count();
    void insert(int);
    void addToFront(int);
    void insertNew(int, int);
    void append(int);
    bool remove(int);
    void removeElement(int);
    void deleteNode(int);
    int search(int);
    void removeDuplicates();
    void reverse();
    void display();
    void sort();
    void deleteList();
};

int main()
{
  
    IntList iList;
    
    int number;
    
    srand(time(0));
    for(int i=0; i<19; i++)
    {
        number = rand() % (20-10) + 10;
    
        iList.insert(number);
    }
    
    iList.sort();
    
    cout << "A sorted main list of 19 random integer numbers that are between "
    << " 10 and 20 are as follows: " << endl;
    iList.display();
    cout << endl;
    
    iList.addToFront(-100);
    cout << "Main List after inserting new number -100 at the beginning: ";
    cout << endl;
    iList.display();
    cout << endl;
    
    iList.insertNew(15,3);
    cout << "Main List after inserting new number 15 at the third location: ";
    cout << endl;
    iList.display();
    cout << endl;
    
    iList.append(1000);
    cout << "Main list after appending new number 1000: ";
    cout << endl;
    iList.display();
    cout << endl;
    
    iList.remove(5);
    cout << "Main list after removing number 5: ";
    cout << endl;
    iList.display();
    cout << endl;
    
    iList.deleteNode(2);
    cout << "Main list after removing second element: ";
    cout << endl;
    iList.display();
    cout << endl;
    
    iList.search(17);
    cout << endl;
    iList.display();
    cout << endl;
    
    iList.reverse();
    cout << "Displaying the main list backward: ";
    cout << endl;
    iList.display();
    cout << endl;
    
    iList.removeDuplicates();
    cout << "Main list after removing duplicate numbers: ";
    cout << endl;
    iList.display();
    cout << endl;
    
    cout << iList.count() << endl << endl;
    
    iList.deleteList();
    cout << "Delete the entire main list.";
    cout << endl;
    iList.display();
    cout << endl;
    
    return 0;
}

IntList::IntList()
{
    head = NULL;
}

IntList::~IntList()
{
    IntNode *p;
    IntNode *n;
    
    p = head;
    
    while (p)
    {
        n = p->next;
        delete p;
        p = n;
    }
}


int IntList::count()
{
    int cnt = 0; //counter
    IntNode *p = head;
    //traverse the list
    while (p != NULL)
    {
        //Update the counter
        cnt++;
        //move along to the next node
        p = p->next;
    }
    return cnt;
}

void IntList::insert(int value)
{
    IntNode *newNode = new IntNode;
    
    newNode->integer = value;
    newNode->next = NULL;
    
    if (head == NULL)
        head = newNode;
    
    else
    {
        IntNode *p = head;
        
        while (p->next)
            p = p->next;
        
        p->next = newNode;
    }
}

void  IntList::addToFront(int value)
{
    IntNode *temp = new IntNode();
    
    temp->integer = value;
    temp->next = head;
    head = temp;
}

void IntList::insertNew(int value, int pos)
{
IntNode *prev = new IntNode();
IntNode *curr = new IntNode();
IntNode *newNode = new IntNode();
newNode->integer = value;

int tempPos = 0;   // Traverses through the list

curr = head;      // Initialize current to head;
if(head != NULL)
{
    while(curr->next != NULL && tempPos != pos)
    {
        prev = curr;
        curr = curr->next;
        tempPos++;
    }
 
        if(pos > tempPos+1)
        cout << " Position is out of bounds " << endl;
        //Position not valid
        
        else
        {
            prev->next = newNode;
            newNode->next = curr;
            cout << "Node added at position: " << pos << endl;
        }
        }
        else
        {
            head = newNode;
            newNode->next = NULL;
            cout << "Added at head as list is empty! " << endl;
        }
}

void IntList::append(int value)
{
    struct IntNode *temp,*right;
    
    temp = (struct IntNode *)malloc(sizeof(struct IntNode));
    temp->integer = value;
    right=(struct IntNode *)head;
    
    while(right->next != NULL)
        right=right->next;
        right->next = temp;
        right=temp;
        right->next = NULL;
}

bool IntList::remove(int value)
{
    IntNode *p, *prev;
    p = head;
    while (p != NULL)
    {
        if (p->integer == value)
        {
            if (p == head)
            {
                // removing first
                head = p->next;
                delete(p);
                return true;
            }
            
            else
            {
                // removing others
                prev->next = p->next;
                delete(p);
                return true;
            }
            
        }
        prev = p;
        p = p->next;
    }
    return false;
}

void IntList::removeElement(int value)
{
    IntNode *prev = head; // empty header
    IntNode *curr = head->next; // the first valid node
    
    while(curr != NULL)
    {
        if(curr->integer == value)
        {
            break;
        }
        else
        {
            cout << "Value " << curr->integer << " does not match " << value << ".\n";
            prev = curr;
            curr = curr->next; // go to next value
        }
    }
    if(curr == NULL)
    {
        // if we reached end of list or the list is empty
        cout << "Can't remove value: no match found.\n";
    }
    else
    {
        cout << "Deleting: " << curr << "\n";
        prev->next = curr->next; // unlink the node you remove
        delete curr; // delete the node
    }
}

void IntList::deleteNode(int pos)
{
    int i, cnt = 0;
    
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    struct IntNode *s, *p;
    
    s = head;
    
    if (pos == 1)
    {
        head = s->next;
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            cnt++;
        }
        if (pos > 0 && pos <= cnt)
        {
            s = head;
            for (i = 1;i < pos;i++)
            {
                p = s;
                s = s->next;
            }
            p->next = s->next;
        }
        else
        {
            cout << "Position out of range" << endl;
        }
        free(s);
        cout << "Element Deleted" << endl;
    }
}

void IntList::reverse()
{
    if(head == NULL) return;
    
    IntNode *prev = NULL, *curr = NULL, *next = NULL;
    
    curr = head;
    
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    //Now let the head point at the last node (prev)
    head = prev;
}

void IntList::display()
{
    IntNode *p = head;
    
    while (p)
    {
        cout << p->integer << " ";
        p = p->next;
    }
    cout << endl;
}

int IntList::search(int value)
{
    IntNode *curr = head;
        
    while(curr != NULL)
    {
        if(curr->integer == value)
        {
            // Found it
            cout << "Value found!";
            return 0;
        }
        // Try the next string in the list
        curr = curr->next;
    }
    // Reached the end, but still could not
    // find the string you are looking for
    cout << "Value not found";
    return 0;
}


void IntList::removeDuplicates()
{
    IntNode *curr = head;
    
    while (curr)
    {
        IntNode *head = curr->next;
        IntNode *tail = curr;
        
        while (head)
        {
            if (head->integer == curr->integer)
            {
                // duplicated item found.
                tail->next = head->next;
            }
            else
                tail = tail->next;
                head = head->next;
        }
        curr = curr->next;
    }
}

void IntList::sort()
{
    
    IntNode *newHead = NULL;
    
    while(head)
    {
        IntNode *c = head;
        head = head->next;
        
        IntNode *p = newHead;
        IntNode *n = NULL;
        
        while(p!=NULL && p->integer<c->integer)
        {
            n = p;
            p = p->next;
        }
        
        if(p==newHead)
        {
            newHead = c;
            c->next = p;
        }
        
        else
        {
            n->next = c;
            c->next = p;
        }
    }
    head = newHead;
}

void IntList::deleteList()
{
    IntNode *del = head;
    
    //Traverse the list and delete the node one by one from the head
    while (del != NULL)
    {
        //take out the head node */
        head = head->next;
        delete del;
        //update the head node
        del = head;
    }
    //Reset the head and tail node
    tail = head = NULL;
}



//Also a delete function but is not deleting last item
/*{
    IntNode *temp = head;
    while(temp->next)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}*/