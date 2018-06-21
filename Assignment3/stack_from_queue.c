

/*
 * This is the file in which you'll write the functions required to implement
 * a stack using two queues.  Make sure to add your name and @oregonstate.edu
 * email address below:
 *
 * Name: Sheng Bian
 * Email: bians@oregonstate.edu
 */
#ifndef TYPE
#define TYPE int
#endif

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/* All by yourself */

//The following code comes from worksheet 18
struct link {
    TYPE value;
    struct link *next;
};

struct listQueue {
    struct link *firstLink;
    struct link *lastLink;
};

void listQueueInit (struct listQueue *q) {
    struct link *lnk = (struct link *) malloc(sizeof(struct link));
    assert(lnk != 0);
    lnk->next = 0;
    q->firstLink = q->lastLink = lnk;
}

void listQueueAddBack (struct listQueue *q, TYPE e) {
    struct link * newLink = (struct link *) malloc(sizeof(struct link));
    assert (newLink != 0);
    q->lastLink->next = newLink;
    q->lastLink = newLink;
    newLink->value = e;
    newLink->next = NULL;
}

TYPE listQueueFront (struct listQueue *q) {
    assert (q->firstLink != q->lastLink);
    return q->firstLink->next->value;
}

void listQueueRemoveFront(struct listQueue *q){
    assert(q->firstLink != q->lastLink);
    struct link *temp = q->firstLink->next;
    if(q->firstLink->next == q->lastLink){
        q->lastLink = q->firstLink;
        q->firstLink->next = NULL;
    }else{
        q->firstLink->next = q->firstLink->next->next;
    }
    free(temp);
    temp = NULL;
}

int listQueueIsEmpty (struct listQueue *q) {
    if (q->firstLink == q->lastLink){
        return 1;
    }else{
        return 0;
    }
}

//The following code is going to implement all the stack functions using above queue functions
void listQueueStackInit(struct listQueue *q){
    listQueueInit(q);
}
int listQueueStackIsEmpty(struct listQueue *q){
    return listQueueIsEmpty(q);
}
struct listQueue* createListQueue(){
    struct listQueue *q = (struct listQueue*)malloc(sizeof(struct listQueue));
    listQueueStackInit(q);
    return q;
}
TYPE listQueueStackTop(struct listQueue *q){
    assert(! listQueueStackIsEmpty(q));
    return q->lastLink->value;
}

void listQueueStackPop(struct listQueue *q){
    assert(! listQueueIsEmpty(q));
    struct link *temp = q->lastLink;
    struct link *current = q->firstLink->next;
    while (current != q->lastLink){
        current = current->next;
    }
    q->lastLink = current;
    current->next = NULL;
    free(temp);
    temp = 0;
}

void listQueueStackFree(struct listQueue *q){
    while (q->firstLink != q->lastLink){
        listQueueStackPop(q);
    }
}

void listQueueStackPush(struct listQueue *q, TYPE d){
    listQueueAddBack(q, d);
}

void print(struct listQueue *q){
    struct link *current = q->firstLink->next;
    while (current != q->lastLink){
        printf("%d\n", current->value);
        current = current->next;
    }
    free(current);
    current = 0;
}


int main() {
    struct listQueue *q = createListQueue();
    listQueueStackPush(q, (TYPE)1);
    listQueueStackPush(q, (TYPE)2);
    listQueueStackPush(q, (TYPE)3);
    printf("This is top: %d\n", listQueueStackTop(q));
    listQueueStackPop(q);
    print(q);
    return 0;
}

