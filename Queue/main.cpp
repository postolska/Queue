//Tablicowa implementacja kolejki
#include <iostream>
#include <cstdlib>
using namespace std;

int const LIMIT = 7;
struct Queue
{
    int tab[LIMIT];
    int rear; //indeks ostatniego elementu kolejki
    int front; //indeks pierwszego elementu kolejki
    int n; //liczba elementów w kolejce
};

//Tworzy kolejke pusta - ustawia rear na -1, front na 0, n na 0
void makeNull(Queue &q)
{
    q.rear=-1;
    q.front=0;
    q.n=0;
}

//Sprawdza czy kolejka jest pusta
bool isEmpty(Queue q)
{
    return (q.n==0);
}

//Sprawdza czy kolejka jest pelna
bool isFull(Queue q)
{
return (q.n==LIMIT);
}

//Wstawia element x na koniec kolejki Q
void enqueue(Queue &q,int x)
{
    if (!isFull(q))
    /* {
        if(q.rear==LIMIT-1)
            q.rear=0;
        else
            q.rear++;
        }
    */
    {
        q.rear = (q.rear + 1) % LIMIT;
        q.tab[q.rear] = x;
        ++q.n;
    }
}

//Usuwa element z poczatku kolejki
void dequeue(Queue &q)
{
    if(!isEmpty(q))
    {
        q.front=(q.front+1)%LIMIT;
        q.n--;
    }
}

//Zwraca element z poczatku kolejki
int first(Queue q)
{
    if(!isEmpty(q))
    {
        return q.tab[q.front];
    }
    else return -1000;
}

//wypisuje kolejke
void print(Queue q)
{
    if (!isEmpty(q))
    {
    int i = q.front;
    while (i != q.rear) {
        cout << q.tab[i] << ", ";
        i = (i + 1) % LIMIT;
    }
        cout << q.tab[q.rear] << endl;
    }
    else cout<<"Queue is empty!"<<endl;
}

int main()
{
Queue q;
    makeNull(q);
    enqueue(q,2);
    dequeue(q);
    enqueue(q,5);
    enqueue(q,13);
    enqueue(q,3);
    enqueue(q,12);
    enqueue(q,9);
    enqueue(q,10);
    enqueue(q,4);
    print(q);
    return 0;
}
