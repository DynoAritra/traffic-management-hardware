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
const int v1 = 14;//it signifies the number of cars passing through a specific point at certain instant
const int w1= 13;//width of the road at point 1
const int w2=12;//width of the road at point 2
const float t1=5.0;//here the time is given in seconds
int q1,q2;//no of cars passing at a point within the time given
int relay = 8;
volatile byte relayState = LOW;
int PIRInterrupt = 2;

 long lastDebounceTime=0;//the last time the motion was detected 
 long debouncedelay=10000;//how much time the car should be awake
int vstate1,widthstate1,widthstate2;//states of the variable , manually passed 
void setup()
{
  Serial.begin(9600);
  pinMode(v1,INPUT);
  pinMode(w1,INPUT);
  pinMode(w2,INPUT);
  pinMode(relay,OUTPUT);//relay module set as output
  digitalWrite(relay,HIGH);//the time car(relay switch) should be kept off 
  pinMode(PIRInterrupt,INPUT);//PIR sensor helps to  detect the motion
  attachInterrupt(digitalPinToInterrupt(PIRInterrupt),detectMotion,RISING);//we see that if the car(here the relay) is speeding for 10 seconds then turn it off 
  Serial.begin(9600);
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
  q1 = v1/t1;//the continuity of the variable 
  if(vstate1==HIGH && widthstate1==HIGH && widthstate2== HIGH)
  {
  if(w1*q1<= w2*q1)
  {
    q2=q1;//continuity principle satisfied
    }
   //if the vehicle is speeding for more than 10 secs the car (here the relay) would be turned off 
   if((millis()-lastDebounceTime)>debouncedelay && relayState==HIGH)
   {
    digitalWrite(relay,HIGH);
    relayState=LOW;
    Serial.println("OFF");
   }
   delay(5000);
    
}
}

void detectMotion()//when the detectMotion function is triggred it sets the relay on again  
{
  Serial.println("motion");
  if(relayState == LOW)
      digitalWrite(relay,LOW);
  relayState = HIGH;
  Serial.println("on");
  lastDebounceTime = millis();
}


  
  
  
