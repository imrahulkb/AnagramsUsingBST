#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node* left,*right;
};

struct nord
{
    int data;
    struct nord* next;
};

struct nord* insert1(struct nord* root,int data);

struct node* newnode(int data)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->right=new->left=NULL;
    return new;
}

struct nord* newnode1(int data)
{
    struct nord *new;
    new=(struct nord *)malloc(sizeof(struct nord));
    new->data=data;
    new->next=NULL;
    return new;
}

void inorder(struct node * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void inorder2(struct node * root,struct nord * head)
{
    if(root!=NULL)
    {
        inorder2(root->left,head);
        insert1(head,root->data);
        inorder2(root->right,head);
    }
}
 void order(struct nord * head)
 {
     if(head!=NULL)
     {
         printf("%d ",head->data);
         order(head->next);
     }
 }
struct node* insert(struct node* root,int data)
{
    if(root==NULL)
    {
        return newnode(data);
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>=root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
}

struct nord* insert1(struct nord* root,int data)
{
    if(root==NULL)
    {
        return newnode1(data);
    }
    root->next=insert1(root->next,data);
    return root;
}

void anagrams(struct nord*head1,struct nord*head2)
{
    struct nord *p1,*p2;
    p1=head1;
    p2=head2;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data!=p2->data)
        {
            printf("NOT ANAGRAMS!!");
            return;
        }
        p1=p1->next;
        p2=p2->next;
    }
    printf("\nAre ANAGRAMS!!!");
    return;
}

int main()
{
    struct node * root1=NULL,*root2=NULL;
    struct nord * head1=NULL,*head2=NULL;
    char s1[20],s2[20];
    
    printf("Enter two strings : ");
    scanf("%s %s",s1,s2);
    
    if(strlen(s1)!=strlen(s2))
    {
        printf("Not ANAGRAMS!!");
        exit(0);
    }
    
    root1=newnode(s1[0]);
    for(int i=1;s1[i]!='\0';i++)
    {
        insert(root1,s1[i]);
    }
    
    root2=newnode(s2[0]);
    for(int i=1;s2[i]!='\0';i++)
    {
        insert(root2,s2[i]);
    }

    head1=newnode1(0);
    head2=newnode1(0);
    inorder2(root1,head1);
    inorder2(root2,head2);
    anagrams(head1,head2);
    return 0;
}
