#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <limits.h>

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
            tmp->next->key != -1 ? printf(" -> ") : printf("");
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void printStats(){
    int max = 0;
    int countMax = 0;

    int min = INT_MAX;
    int countMin = 0;

    double avg = 0;


    for(int i = 0; i<M; i++){
        int curLength = 0;
        struct node* tmp = koepfe[i]->next;
        while (tmp->key != -1){
            curLength++;
            tmp = tmp->next;
        }
        if(curLength > max){
            countMax = 1;
            max = curLength;
        } else if (curLength == max){
            countMax++;
        }
        if(curLength<min){
            countMin = 1;
            min = curLength;
        } else if (curLength == min){
            countMin++;
        }
        avg = (double) curLength + avg;

    }
    avg = (double) avg / M;

    printf("Max: %i, Count: %i\n", max, countMax);
    printf("Min: %i, Count: %i\n", min, countMin);
    printf("Avg: %f", avg);
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
    printStats();
}


