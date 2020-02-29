#include <stdio.h>  
#include <LinkedList.h>
//Represent a node of singly linked list  
struct node{  
    int data;  
    struct node *next;  
};      
   
//Represent the head and tail of the singly linked list  
struct node *head, *tail = NULL;  
   
//addNode() will add a new node to the list  
void addNode(int data){  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->next = NULL;  
      
    //Checks if the list is empty  
    if(head == NULL) {  
        //If list is empty, both head and tail will point to new node  
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;  
        //newNode will become new tail of the list  
        tail = newNode;  
    } 
} 
 
   
//countNodes() will count the nodes present in the list  
int countNodes() {  
    int count = 0;  
    //Node current will point to head  
    struct node *current = head;  
      
    while(current != NULL) {  
        //Increment the count by 1 for each node  
        count++;  
        current = current->next;  
    }  
    return count;  
}  
      
//display() will display all the nodes present in the list  
void display() {  
    //Node current will point to head  
    struct node *current = head;  
      
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    printf("Nodes of singly linked list: \n");  
    while(current != NULL) {  
        //Prints each node by incrementing pointer  
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
const int v1 = D4;//it signifies the number of cars passing through a specific point at certain instant
const int w1= D3;//width of the road
const int w2=D2;
const float t1=5.0;//here the time is given in seconds
int q1,q2; 
int vstate1,widthstate1,widthstate2;
void setup()
{
  Serial.begin(9600);
  pinMode(v1,INPUT);
  pinMode(w1,INPUT);
  pinMode(w2,INPUT);
  //adding nodes to the linkedlist
addNode(q1);
addNode(q2);
display();
printf( "count the nodes:%d",countNodes());
 
}
void loop()
{
  vstate1=digitalRead(v1);
  widthstate1=digitalRead(w1);
  widthstate2=digitalRead(w2);
  q1 = v1/t1;
  if(w2*q1<w2*q2)
  {
    q2=q1;
    }
   else
    printf("side cars to slow down");
}



  
  
  
