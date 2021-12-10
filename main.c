#include <stdio.h>
#include <malloc.h>
#include <time.h>

#define M 7
#define MaxKey 100;


static struct node{
    int key;
    struct node *next;
};

static struct node *koepfe[M], *ende;

void hashlistinitialize(){
    srand(time(NULL));
    int i;

    ende = (struct node *) malloc (sizeof *ende);
    ende->next = ende; ende->key = -1;
    for (i = 0; i < M; i++){
        koepfe[i] = (struct node *) malloc (sizeof *ende);
        koepfe[i]->next = ende;
    }
}

unsigned hash (int i){
    return i%M;
}

void hashInsert(int i){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->key = i;
    newNode->next = ende;

    struct node* tmp = koepfe[hash(i)]->next;

    if (tmp->key == -1){
        koepfe[hash(i)]->next = newNode;
        return;
    }

    while (tmp->next->key != -1){
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

void printList(){
    for(int i = 0; i<M; i++){

        struct node* tmp = koepfe[i]->next;
        printf("%i: ",i);
        while (tmp->key != -1){
            printf("%i",tmp->key);
            printf(" -> ");
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void printStats(){

}

unsigned randomNumber(){
    return rand()%MaxKey;
}

int main() {
    hashlistinitialize();
    for (int i = 0; i<50; i++){
        hashInsert(randomNumber());
    }
    printList();
}


