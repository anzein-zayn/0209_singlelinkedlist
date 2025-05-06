#include<iostream>
using namespace std;
#include <string.h>

class node
{
public:
    int noMhs;
    Node *next;
};

class LinkedList
{
    node *start;

public :
    LinkedList()
    {
        start = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;

        node *nodeBaru = new node;
        nodeBaru->noMhs = nim;
        
        if (start == NULL || nim <= start->noMhs)
        {
            if ((start != NULL) && (nim == start->noMhs))
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            nodeBaru->next = start;
            start=nodeBaru;
            return;
        }
        node *previous=start;
        node *current=start;

        while ((current !=NULL)&&(nim >= current ->noMhs))
        {
            if ( nim == current ->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            previous=current;
            current = current->next;
        }
    }
    bool listempty()
    {
        return (start == NULL);
    }
    bool Search (int nim,node **previous, node **current)
    {
        *previous=start;
        *current = start;

        while ((*current !=NULL)&&(nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }
        return ( *current !=NULL);
    }
    bool delNode (int nim)
    {
        node *current, *previous;
        if (!Search(nim, &previous, &current))
        return false;

        if (current ==start)
            start = start -> next;
        else
        previous ->next = current ->next;
        delete current;
        return true;
    }

    void traverse()
    {
        if (listempty())
        {
            cout << "\nList Kosong\n";
        }
        else
        {
            cout << "\nData didalam list adalah :\n";
            node *currentNode = start;
            while (currentNode !=NULL)
            {
                cout << currentNode->noMhs <<endl;
                currentNode = currentNode->next;
            }
            cout <<endl;
        }
    }


};