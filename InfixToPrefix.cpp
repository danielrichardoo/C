//Daniel Richardo - 2201744531

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	
	char data;
	struct node *next;
	
}*top=NULL,*head=NULL;


void insert(char ch){
	
	struct node *temp,*newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->next=NULL;
    newNode->data=ch;
    temp=head;

    if(head==NULL){
    	head=newNode;
    }
    else{
    	newNode->next=head;
    	head=newNode;
    }
    
}

void push (char opr){

    struct node *newNode;
    newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data=opr;
 
    if(top==NULL){
		top=newNode;
    	newNode->next=NULL;
    }else{
    	newNode->next=top;
    	top=newNode;
    }
}

char  pop(){

	struct node *temp;
	char a;

	temp=top;
	top=top->next;
	a=temp->data;
	free(temp);
	temp=NULL;
	
	return a;
}

void print(){
    struct node* temp;
    if(head==NULL){
		printf("No Data!");
	}else{
    	temp=head;
    	while(temp!=NULL){
        	printf("%c",temp->data);
        	temp=temp->next;
 	   }

    }
}

int precedence(char ch){
	
	if(ch=='^'){
		return (4);
	}
	else if(ch=='*' || ch== '/' || ch=='%'){
		return (3);
	}else if(ch== '+' || ch== '-'){
		return (2);
	}
	else{
		return (1);
	}
	
}

void intopost(char infix[]){

    int len;
    int index=0;
    char opr,temp;
    len= strlen(infix);
    while(len>index){
    	
        opr=infix[index];

        switch(opr){

        	case ')': push(opr); break;

        	case '(': temp=pop(); 
			
			while(temp!=')'){
				insert(temp);
				temp=pop();
			}
			break;
			
        	case '+':
        	case '-':
        	case '*':
       		case '/':
       		case '%':
       		case '^':
        	
        	if(top==NULL){
       		    push(opr);
     	   }
   		    else{
   	    		while(top!=NULL && (precedence(top->data)>=precedence(opr))){
    	       		temp=pop();
    	        	insert(temp);
   		     	}
        
     		   	push(opr);

   	    	}
        
			break;
        
			default: insert(opr);

    	}
        index=index+1;
		print();
		printf("\n");

    }
    while(top!=NULL){
    	
   		temp=pop();
		insert(temp);

    }
    
}


int main(){
	
	char infix[50];
	printf("infix	: ");
	scanf("%[^\n]", &infix);
	printf("\n");
	
	printf("prefix	: ");
	intopost(strrev(infix));
	print();
	
	return 0;
	
}

// A%B/C+(D+E*F-G)*H-I
