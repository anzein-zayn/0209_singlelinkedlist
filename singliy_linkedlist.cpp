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
    }
};