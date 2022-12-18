#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};
// INSERT AT START
struct node *insertatstart(struct node *head, int key)
{
  struct node *new = (struct node *)malloc(sizeof(struct node));

  new->data = key;
  new->next = head;
  head = new;
}
// INSERT AT ANY POSITION
struct node *insertatvariable(struct node *prev, int pos, int data)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  for (int i = 0; i < pos - 1; i++)
  {
    prev = prev->next;
  }
  newnode->data = data;
  newnode->next = prev->next;
  prev->next = newnode;
}

// INSERT AT END------------------------------->
struct node *insertatend(struct node *prev, int data)
{
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->data = data;
  while (prev->next != NULL)
  {
    prev = prev->next;
  }

  prev->next = new;
  new->next = NULL;
}

// TRAVELLING LINKED LIST
void traversal(struct node *ptr)
{
  while (ptr != NULL)
  {
    printf("%d\t", ptr->data);
    ptr = ptr->next;
  }
}

struct node *insertafterindex(struct node *prev, int pos, int data)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  for (int i = 0; i < pos; i++)
  {
    prev = prev->next;
  }
  newnode->data = data;
  newnode->next = prev->next;
  prev->next = newnode;
}










int main()
{
  struct node *head = (struct node *)malloc(sizeof(struct node));
  struct node *second = (struct node *)malloc(sizeof(struct node));
  struct node *third = (struct node *)malloc(sizeof(struct node));
  struct node *fourth = (struct node *)malloc(sizeof(struct node));
  struct node *fifth = (struct node *)malloc(sizeof(struct node));
  struct node *sixth = (struct node *)malloc(sizeof(struct node));

  head->data = 1;
  second->data = 2;
  third->data = 3;
  fourth->data = 4;
  fifth->data = 5;
  sixth->data = 6;
  head->next = second;
  second->next = third;
  fourth->next = fifth;
  third->next = fourth;
  sixth->next = NULL;
  fifth->next = sixth;

  traversal(head);
head=insertatstart(head, 98);
  insertatvariable(head, 2, 100);
  insertafterindex(head,4,453);
insertatend(third,33611);
  printf("\n");
  traversal(head);
  return 0;
}