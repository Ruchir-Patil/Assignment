#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct linkedList{
	char arr[100];
	struct linkedList *next;
}list;
struct group
{
	int count;
	char words[100][100];
};
struct temp
{
	int count;
	char words[100][100];
};
list * sorted;


list * newNode()
{
	list *l1;
l1=(list *)malloc(sizeof(list));
l1->next=NULL;
return l1;
}
void displayList(list *head, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n%s",head->arr);
		head=head->next;
	}
	scanf("%d",&n);
}
list * copyLinkedlist(list *head, int n)
{
int i;
list *HeadSorted;
	sorted=newNode();
	HeadSorted=sorted;
		for(i=0;i<n;i++){
		
			strcpy(sorted->arr,head->arr);
			sorted->next=newNode();
			sorted=sorted->next;
			head=head->next;
		}
		head->next=NULL;
		return HeadSorted;	
}

list * sortedList(int n){
    char temp;
    int i,j,len1,len2;
    list * HeadSorted;
    HeadSorted=sorted;
	while(HeadSorted->next!=NULL)
	{
		len1=strlen(HeadSorted->arr);
		for(i=0;i<len1-1;i++){
				len2=strlen(HeadSorted->arr);
		    for(j=0;j<(len2-i-1);j++){

			   if((int)HeadSorted->arr[j]>(int)HeadSorted->arr[j+1])
				{
				
					temp = HeadSorted->arr[j];
					HeadSorted->arr[j] = HeadSorted->arr[j+1];
					HeadSorted->arr[j+1] = temp;
				}
			}
		}
		HeadSorted=HeadSorted->next;	
	}
	return sorted;
}
function_Test()
{
	if(sortedList(10)==sorted){
		printf("Pass : return value Test 1");
	}
	else{
		printf("Fail : return value is not refrenced properly");
	}
}
/*function_Test_2(){
	if(copyLinkedlist(10,10))
	{
		printf("sdfsdf");
	}
}*/
/*function_test_3()
{
	head=10;	
}*/
int main()
{
	list *l1,*head;
	int n,i,j;
	
	char arr[100],a[100][100],store[100][100];
	l1=newNode();
	head=l1;
	
	printf("\n\tPlease enter number of strings to be inserted :");
	scanf("%d",&n);
	/*if(n==(char)n)
	{
		printf("Fail invalid input");
		system("pause");
	}*/
	if(n==0);
	{
		printf("0 strings cannot be generated");
		system("pause");
	}
	printf("Input");
	for(i=0;i<n;i++)
	{
		scanf("%s",arr);
		strcpy(l1->arr,arr);
		l1->next=newNode();
		l1=l1->next;
		l1->next=NULL;
	}
	sorted=copyLinkedlist(head,n);
	sorted=sortedList(n);
	for(i=0;i<n;i++)
	{
		strcpy(a[i],sorted->arr);
		sorted=sorted->next;
		if(sorted==NULL)
			break;
	}
	for(i=0;i<n;i++)
	{
		strcpy(store[i],head->arr);
		head=head->next;
		//head=funtction_test_3();
		if(head==NULL)
			break;
	}

	int q,k,tag[100]={0},counterone=0,count=0;
	struct group setone[100],settwo[100];			
	while(1)
	{
		for(i=0 ; i<n ; i++)
		{
			if(tag[i]==0)
			{
				counterone++; 
				tag[i] = 1;
				count = 1;
				for(j=i+1 ; j<n ; j++)
				{
					if(tag[j]==0)
					{
						if(strcmp(a[i] , a[j]) == 0)
						{
							tag[j]=1;
							count++;
						}
					}
				}
				setone[i].count = count;
				q=0;
				for(k=i ; k<n ; k++ )
				{
					if(tag[k]==1)
					{
						tag[k]=2;
						strcpy( setone[i].words[q], store[k]);
						q++;
					}
				}
			}
		}
		for(i=0 ; i <counterone-1 ; i++)
		{
			for(j=0 ; j <counterone-j-1 ; j++)
			if(setone[j].count< setone[j+1].count)
			{
			            
			    memcpy(&settwo[0], &setone[j], sizeof settwo[0]);
				memcpy(&setone[j], &setone[j + 1], sizeof setone[j]);
				memcpy(&setone[j + 1], &settwo[0], sizeof setone[j + 1]);
			}
		}
		/*printf("output\n");
		for(k=0; k<=counterone; k++ )
		{
			if(setone[k].count !=0)
			{
					
				printf("%d: ",setone[k].count);
				for( q=0 ; q<=setone[k].count ; q++ )
				{
						printf("%s ",setone[k].words[q]);
				}
				printf("\n");	
			}
			
		} */
		break;
		
	}
	function_Test();
//	variable_Test();
//function_Test_2();
	system("pause");
}


/*OutPut: Test 1
	

        Please enter number of strings to be inserted :2
Input
qwe
wqe
Pass : return value Press any key to continue . . .

Test 2 :
	
	
        Please enter number of strings to be inserted :s
Fail invalid inputPress any key to continue . . .

Test 3 :


        Please enter number of strings to be inserted :2
Input
qwe
wqe
Pass : return value Test 1
--------------------------------
Process exited after 10.98 seconds with return value 3221225477
Press any key to continue . . .*/
