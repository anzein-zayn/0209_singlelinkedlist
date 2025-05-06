#include<iostream>
using namespace std;

//Membuat struct node
struct node
{
    int noMhs;
    node *next;
};

//set value Start=Null
node *start = NULL;