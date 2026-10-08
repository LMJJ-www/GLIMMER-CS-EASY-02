#include <stdio.h>
#include <stdlib.h>
 struct Node
   {
      int data;
    struct Node *next;
   };

struct Node *createNode(int data)
{
   struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

void headinsert(struct Node **head, int data)
{
   struct Node *newNode = createNode(data);
   newNode->next = *head;
   *head = newNode; 
}

void endinsert(struct Node **head, int data)
{
   struct Node *newNode = createNode(data);
   if(*head == NULL)
   {
      *head = newNode;
   }
   else{
      struct Node *p = *head;
      while(p->next != NULL)
      {
         p = p->next;
      }
      p->next = newNode;
   }

}
void printlist(struct Node *head)
{
   struct Node *t = head;
   while(t != NULL)
   {
      printf("%d", t->data);
      t = t->next;
   }
   printf("\n");
}

void findNode(struct Node *head, int data)
{
   struct Node *f = head;
   int j = 0;
   for( ;f != NULL && f->data != data;j++)
   {
      f = f->next;
   }
   if(f == NULL)
   {
      printf("false\n");
   }
   else
   {
      printf("%d\n",j+1);
   }
}

void deleteNode(struct Node **head, int rank)
{
   struct Node *p = *head;
   struct Node *pre = NULL;

   for(int i = 1;p != NULL && i < rank; i++)
   {
      pre = p;
      p = p->next;
   }
   if(p == NULL)
   {
      printf("false\n");
   }
   else if(pre == NULL)
   {
      *head = p->next;
      printf("true\n");
   }
   else
   {
      pre->next = p->next;
      printf("true\n");
   }
   free(p);
   p = NULL;
}

void reverselist(struct Node **head)
{
   struct Node *p = *head;
   struct Node *pre = NULL;
   while(p != NULL)
   {
      struct Node *n = p->next;
      p->next = pre;
      pre = p;
      p = n;
   }
   *head = pre;

}

int main()
{
  
   struct Node a , *head;
   head = &a;
   a.data = 0;
   a.next = NULL;
   createNode(1);
   headinsert(&head, -1);
   endinsert(&head, 1);
   endinsert(&head, 2);
   endinsert(&head, 3);
   endinsert(&head, 3);
   endinsert(&head, 4);
   printlist(head);
   findNode(head, 3);
   findNode(head, 5);
   deleteNode(&head, 6);
   printlist(head);
   reverselist(&head);
   printlist(head);
   return 0;
}