//jeerayoot senpanich  5630300164
#include<stdio.h>
#include<iostream>

using namespace std;

struct rec
{
	int value;
	struct rec *next;
};

int size;
struct rec *Insert(struct rec *head,int data)
{
	struct rec *node,*temp;
	if(head==NULL)
	{
		head=new rec;
		head->value=data;
		head->next=NULL;				
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			if(temp->value==data)
			{
				return head;
			}
			else if(temp->next==NULL)
			{
				node=new rec;
				node->value=data;
				node->next=NULL;
				temp->next=node;
				return head;
			}
			temp=temp->next;
		
		}
	
	}
	
		return head;	
}

struct rec *Enqueue(struct rec *head,int data)
{
	struct rec *node,*temp;
    if(head == NULL)
	{
        head = new rec;
        head->value = data;
        head->next = NULL;
    }
	else
	{
      	temp=head;
		while(temp!=NULL)
		{
			if(temp->value==data)
			{
				return head;
			}
			else if(temp->next==NULL)
			{
				node=new rec;
				node->value=data;
				node->next=NULL;
				temp->next=node;
				return head;
			}
			temp=temp->next;
		
		}
		
    }
    return head;
}

struct rec *Dequeue(struct rec *head)
{
    struct rec *tmpcell;
    if(head == NULL)
	{
        return head;
    }
	else
	{
    
        tmpcell = head;
        head = head->next;
        delete(tmpcell);
    }
    return head;
}


struct rec*BFS(int s,struct rec *G[])
{
	

	int pass[size],d[size],pred[size],v,u;
	struct rec *Q=NULL,*node;
	
	for(int i=0;i<size;i++)
	{
		pass[i]=0;
		d[i]=-1;
		pred[i]=-1;	
		
	}
		pass[s]=1;
		d[s]=0;
		pred[s]=s;
	
	
		Q=Enqueue(Q,s);
		while(Q!=NULL)
		{
			u=Q->value;
			node=G[u];	
			while(node!=NULL)
			{
				v=node->value;		
				if(pass[v]==0)
				{
					pass[v]=1;
					d[v]=d[u]+1;
					pred[v]=u;
					Q=Enqueue(Q,v);	
					
				}
				node=node->next;
			}	
			
			Q=Dequeue(Q);
			
		}
	cout<<"Distance"<<endl;	
	for(int i=0;i<size;i++)
	{
		cout<<s<<"->"<<i<<" = "<<d[i]<<endl;	
		
	}
		cout<<endl;

}




int main()
{
	
	int number;
	struct rec *linklist[size];
	
	while(true)
	{
	cout<<"========================="<<endl;
	cout<<"           Menu          "<<endl;
	cout<<"========================="<<endl;
	cout<<"1) Insert Graph "<<endl;
	cout<<"2) BFS "<<endl;
	cout<<"3) Exit "<<endl;
	cout<<"Please choose > "<<endl;
	cin>>number;
	switch(number)
	{
		case 1:
			{	
			cout<<endl;
			cout<<"Head Size > ";
			cin>>size;
			cout<<endl;
			int i,i1,data,empty;
			struct rec *temp;
			
			cout<<"Please input Graph"<<endl; 
			cout<<"if your input = 99 mean is break"<<endl;
			for(empty=0;empty<size;empty++)
			{
				linklist[empty]=NULL;			
			}
			
			for(i=0;i<size;i++)
			{
				cout<<i<<" : ";
				
				while(true)
				{
					cin>>data;
				//	if(cin.get()=='\n')
					if(data==99)
					{
						break;
					}
					else
						linklist[i]=Insert(linklist[i],data);
				}
				
				
			}
			cout<<endl;
			

			break;
			}
		case 2:
		{
			struct rec *bfs;
			int vertex;
			cout<<"Enter input source node :";
			cin>>vertex;
			bfs=BFS(vertex,linklist);
			break;
		}
		
	}
	
	}
}
