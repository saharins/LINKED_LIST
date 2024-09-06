#include <iostream>
#define MAXSTK 100
using namespace std;

void PUSH(int STACK[], int &TOP, int ITEM) 
{
    if (TOP == MAXSTK - 1) 
    {
        cout << "OVERFLOW" << endl;
        return;
    } 
    else 
    {
        TOP = TOP + 1;
        STACK[TOP] = ITEM;
    }
}

int main() 
{
    int STACK[MAXSTK]; 
    int TOP = -1;
    int numItems;

    cout << "Enter the number of items to push onto the stack: ";
    cin >> numItems;

    for (int i = 0; i < numItems; i++) 
    {
        int ITEM;
        cout << "Enter item " << i + 1 << ": ";
        cin >> ITEM;
        PUSH(STACK, TOP, ITEM);
    }

    cout << "Stack contents: ";
    for (int i = 0; i <= TOP; i++) 
    {
        cout << STACK[i] << " ";
    }
    cout << endl;

    return 0;
}