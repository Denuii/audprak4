#include <stdio.h>
#include <malloc.h>

#define M 7


static struct node
{
    int key;
    struct node *next;
};

static struct node *koepfe[M], *ende;

void hashlistinitialize()
{
    int i;

    ende = (struct node *) malloc (sizeof *ende);
    ende->next = ende; ende->key = -1;
    for (i = 0; i < M; i++)
    {
        koepfe[i] = (struct node *) malloc (sizeof *ende);
        koepfe[i]->next = ende;
    }
}

unsigned hash (int i)
{
    return i%M;
}

void hashInsert(int i){
    //TODO
}

void printWithStats(){
    //TODO
}



int main() {

}


