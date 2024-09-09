#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
/* Structurile necesare*/
typedef struct node{
    char data;
    struct node *next;
    struct node *prev;
    struct node* nextlist;
    struct node* prevlist;
}node;
typedef struct TDoubleLinkedList{
    node* head;
    node* tail;
    int len;
}TDoubleLinkedList;
typedef struct ListOfLists{
  int len;
  node* HEAD;
  node* TAIL;
}ListOfLists;
typedef struct nod_stiva{
char *data;
struct nod_stiva *next;
}nod_stiva;
typedef struct Stiva{
struct nod_stiva *top;
int len;
}Stiva;
/* Contori necesari pentru prelucrarea caracterelor */
int pozcnt=0,contor,pozcnt1=0,contor1,contor2,contor3,contor4=0,contor5=0;
int contor6=0,contor7=0,contor8=1,contor9=0,contor10=0,contor11=0,contor12=0;
/* Variabila poz reprezinta cursorul */
node* poz=NULL,*vechi=NULL,*vechi1=NULL,*poz1=NULL,*poz2=NULL,*sep=NULL,*poz3=NULL;
void init(TDoubleLinkedList **list)
{
    *list=(TDoubleLinkedList*)calloc(1,sizeof(TDoubleLinkedList));
    (*list)->head=(*list)->tail=NULL;
    (*list)->len=0;
}
void init1(ListOfLists **LIST)
{
    *LIST=(ListOfLists*)calloc(1,sizeof(ListOfLists));
    (*LIST)->HEAD=(*LIST)->TAIL=NULL;
    (*LIST)->len=0;
}
void initiere_stiva(Stiva** s)
 {
    *s=(Stiva *)calloc(1,sizeof(Stiva));
    (*s)->top=NULL;
    (*s)->len=0;
 }
 int verif_stiva_goala(Stiva *s)
 {
   if(s->top==NULL && s->len==0)
   return 0;
   else
   return 1;
 }
 int adaugare_stiva(Stiva *s,char* data)
 {  nod_stiva* nou;
    nou=(nod_stiva*)calloc(1,sizeof(nod_stiva));
    nou->data=data;
    nou->next=s->top;
    s->top=nou;
    s->len++;
    if(s->top!=NULL)
    {
    return 1;
    s->len++;
    }
    return 0;
 }
char* eliminare_stiva(Stiva *s)
{  char* val;
   if(s->top==NULL)
   return NULL;
   nod_stiva* p;
   p=s->top;
   val=p->data;
   s->top=p->next;
   s->len--;
   if(s->len==0)
   s->top=NULL;
   free(p);
   return val;
}
/* Fiecare rand reprezinta o lista */
int add(TDoubleLinkedList *list,int n,char data)
{
  node* nou;
  nou=(node*)calloc(1,sizeof(node));
  nou->data=data;
  if(list->head==NULL && list->tail==NULL)
  {
      list->head=list->tail=nou;
      return 0;
  }
  else
  if(n<0 || n>list->len+2)
  return 0;
  else
  if(n==1)
  {
      nou->next=list->head;
      list->head->prev=nou;
      list->head=nou;
      return 0;
  }
  else
  if(n==list->len+1)
  {
      nou->prev=list->tail;
      list->tail->next=nou;
      list->tail=nou;
      return 0;
  }
return 0;

}
/* Adaugarea comenzilor intr-o lista de liste*/
int add1c(ListOfLists *LIST,TDoubleLinkedList *list)
{
   if(LIST->HEAD==NULL && LIST->TAIL==NULL)
   {
   LIST->HEAD=LIST->TAIL=list->head;
   return 0;
   }
   else
   if(LIST->len>0)
   {
      list->head->prevlist=LIST->TAIL;
      LIST->TAIL->nextlist=list->head;
      LIST->TAIL=list->head;
   }
return 0;
}
/* Adaugarea liniilor de text intr-o lista de liste*/
int add1(ListOfLists *LIST,TDoubleLinkedList *list)
{
   node* lm,*op=LIST->TAIL,*ij,*lo;
   int y=1,u=0,l=0;
   TDoubleLinkedList* lista=NULL;
  while(op)
 {
   op=op->next;
   if(op==poz)
   {
     u=1;
     break;
   }
  }
  if(poz!=NULL)
 { lo=poz;
  while(lo->prev)
  {
  lo=lo->prev;
  }
  if(lo->nextlist==LIST->TAIL)
  l=1;
  }
   if(LIST->HEAD==NULL && LIST->TAIL==NULL)
   {
   LIST->HEAD=LIST->TAIL=list->head;
   return 0;
   }
/* Cazul in care ma aflu la sfarsitul listei mari (lista de liste) */
   else
   if(LIST->len>0 && pozcnt==0 && pozcnt1==0)
   {
        list->head->prevlist=LIST->TAIL;
      LIST->TAIL->nextlist=list->head;
      LIST->TAIL=list->head;
   }
else
    if(pozcnt==1 && pozcnt1!=1)
   {
     if(poz==LIST->HEAD)
      {
        list->head->nextlist=LIST->HEAD;
        LIST->HEAD->prevlist=list->head;
        LIST->HEAD=list->head;
      }
    else
       if(poz!=LIST->HEAD && poz!=LIST->TAIL)
       {
          poz->prevlist->nextlist=list->head;
          list->head->prevlist=poz->prevlist;
          poz->prevlist=list->head;
         list->head->nextlist=poz;
      }
   else
     if(poz==LIST->TAIL)
       {
         LIST->TAIL->prevlist->nextlist=list->head;
         list->head->prevlist=LIST->TAIL->prevlist;
         LIST->TAIL->prevlist=list->head;
         list->head->nextlist=LIST->TAIL;
       }
   }
  else
     {
     if(pozcnt1==1 && (u==1 || l==1))
    {
        list->tail->next=poz->next;
        poz->next->prev=list->tail;
        list->head->prev=poz;
        poz->next=list->head;
    }
/* Daca inserez 2 linii in lista de liste folosind comanda gc */
   else
       if(pozcnt1==1 && u==0 && contor1!=1 && contor7==0)
    {
      init(&lista);
      list->tail->next=poz->next;
      poz->next->prev=list->tail;
      list->head->prev=poz;
      poz->next=list->head;
      ij=list->head;
  while(ij->prev)
     {
     ij=ij->prev;
     }
     poz3=list->tail->next;
  while(poz3)
    {
      add(lista,y,poz3->data);
      lista->len++;
      y++;
      poz3=poz3->next;
     }
      poz3=list->tail->next;
  while(poz3->next)
 {
     lm=poz3;
     poz3=poz3->next;
     free(lm);
}
   free(poz3);
   list->tail->next=NULL;
   lista->head->prev=NULL;
   lista->tail->next=NULL;
   lista->head->prevlist=ij;
   lista->head->nextlist=ij->nextlist;
   ij->nextlist->prevlist=lista->head;
   ij->nextlist=lista->head;
   poz3=lista->head;
   contor7++;
    }
else
    if(pozcnt1==1 && u==0 && contor1!=1 && contor7==1)
  {
       poz3->prevlist->nextlist=list->head;
       list->head->prevlist=poz3->prevlist;
       poz3->prevlist=list->head;
       list->head->nextlist=poz3;
       list->tail->next=NULL;
  }

}
if(lista!=NULL)
{
 free(lista);
}
 return 0;
}

int main(int argc,char* argv[])
{
   Stiva* st=NULL;
   ListOfLists *LIST=NULL,*LIST2=NULL;
   /* Listele auxiliare vor ajuta la realizarea comenzii undo */
   TDoubleLinkedList *list2=NULL,*lista_auxiliara=NULL,*lista_auxiliara1=NULL,*lista_auxiliara2=NULL,*lista_auxiliara3=NULL;
   FILE* f1,*f2;
   f1=freopen("editor.in","r+",stdin);
   f2=fopen("editor.out","w");
   init1(&LIST);
   init1(&LIST2);
   initiere_stiva(&st);
   node* q,*r,*poz1,*e,*e1,*e2;
   int cnt=0,jx=1,mk,i;
   /* Aceste variabile vor ajuta la eliberarea memoriei */
   char* s=NULL,*sir[2],ch,*s1=NULL,*s2=NULL,*sir1=NULL,*sir2=NULL,*sir3=NULL;
   char* s3=NULL,*s4=NULL,*s5=NULL,*s6=NULL,*s7=NULL,*s8=NULL;
   sir[0]=NULL;
   sir[1]=NULL;
   s=(char*)calloc(MAX,sizeof(char));
   sir1=(char*)calloc(MAX,sizeof(char));
   sir2=(char*)calloc(MAX,sizeof(char));
   sir3=(char*)calloc(MAX,sizeof(char));
  for(mk=0;mk<2;mk++)
  sir[mk]=(char*)calloc(MAX,sizeof(char));
  mk=0;
  fgets(s,MAX,stdin);
   while(1)
{ /* Procesul de citire */
     TDoubleLinkedList *list=NULL;
    if((contor9==0 || contor9==1) && contor10<2)
   {
     init(&list);
     for(i=1;i<=strlen(s);i++)
     {
     add(list,i,*(s+i-1));
     list->len++;
     }
     add1(LIST,list);
     free(list);
   }
   /* Procesul de prelucrare */
     LIST->len++;
     if(s[0]==':' && s[1]==':')
    {  comenzi1:
     init(&list2);
     for(i=1;i<=strlen(s);i++)
     {
     add(list2,i,*(s+i-1));
     list2->len++;
     }
     add1c(LIST2,list2);
     free(list2);
     LIST2->len++;
     goto comenzi;
     while(strcmp(s,"::i")!=0)
     {
      comenzi:
  /* Salvarea in fisier */
      if(LIST2->TAIL->data=='s')
     {
        fclose(f2);
        f2=fopen("editor.out","w");
        q=r=LIST->HEAD;
      while(r)
     {
     while(q)
     {
      if(q->data!='\n')
      fprintf(f2,"%c",q->data);
      q=q->next;
     }
       fprintf(f2,"\n");
       r=r->nextlist;
       q=r;
    }
     }
  /* Iesire */
     if(LIST2->TAIL->data=='q')
     {
     q=e=LIST->HEAD;
     r=LIST->HEAD->nextlist;
     while(r)
    {
      while(q->next)
       {  e=q;
          q=q->next;
          free(e);
      }
     free(q);
     q=r;
     r=r->nextlist;
     }
    while(q->next)
     {
    e=q;
    q=q->next;
    free(e);
      }
     free(q);
     cnt=1;
     break;
     }
  /* Procesul de stergere totala */
   if(LIST2->TAIL->data=='d' && s[1]=='a')
  {
   int h=3,j=1,mcontor1=0,mcontor2=0,l;
   TDoubleLinkedList *list6=NULL;
   init(&list6);
   while(s[h]!='\0')
  {
   add(list6,j,s[h]);
   list6->len++;
   h++;
   j++;
  }
  e1=list6->head;
  while(e1)
  {
   mcontor1++;
   e1=e1->next;
   }
  mcontor1--;
  mcontor2=mcontor1;
  e2=LIST->TAIL;
  while(e2->next)
  {
  e2=e2->next;
  if(e2->data=='\n')
  break;
  }
  e2=e2->prev;
  e1=list6->head;
  q=r=LIST->HEAD;
  h=0;
/* Parcurgere si eliminare */
  cautare:
  if(r!=NULL)
{ 
  e1=list6->head;
  while(r!=e2)
 {
   if(h==mcontor1)
    {
   j=0;
   break;
    }
   if(r->data==e1->data)
  {
   h++;
   if(e1->next)
   e1=e1->next;
  }
   else
  {
      h=0;
      e1=list6->head;
  }
  if(r->next==NULL)
  {
   while(r->prev!=NULL)
   r=r->prev;
   r=r->nextlist;
   continue;
  }
  r=r->next;
  }
}
  if(r!=NULL)
  if(r==e2 && r->data==e1->data)
  h++;
  if(h==mcontor1)
  j=0;
   if(j==0)
{
  q=r;
  for(l=0;l<mcontor1 && r->prev!=NULL;l++)
  r=r->prev;
/* Se trateaza toate cazurile */
  if(r->prev!=NULL && r->next!=NULL)
{
   node* kl=LIST->TAIL;
   int vc=0;
   while(kl->next)
  { kl=kl->next;
   if(kl==r)
   {
   vc=1;
   break;
   }

  }
   if(q->next!=NULL && vc==0)
  {
    while(mcontor1 && r->next)
       {
         e1=r;
         r->prev->next=r->next;
         r->next->prev=r->prev;
         r=r->next;
         free(e1);
         mcontor1--;
     }
   }
  else
      if((vc==1 && r->prev!=NULL) || (vc==1 && q->next!=NULL))
   {
     if(q->next->data=='\n')
     r=r->next;
      while(mcontor1 && r->next)
       {
         e1=r;
         r->prev->next=r->next;
         r->next->prev=r->prev;
         r=r->next;
         free(e1);
         mcontor1--;
      }
     if(r->next==NULL)
      goto terminare;
  }
  else
      if((vc==0 && r->prev!=NULL) || (vc==0 && q->next!=NULL))
  {
    while(mcontor1 && r->next)
      {
        e1=r;
        r->prev->next=r->next;
        r->next->prev=r->prev;
        r=r->next;
        free(e1);
        mcontor1--;
      }
 }

}
/* Ma aflu la inceputul unei linii */
 else  if(r->prev==NULL && r->nextlist!=NULL && r->prevlist!=NULL)
{
     if(q->data!='\n')
    {
      while(mcontor1)
     { q=r;
       r->prevlist->nextlist=r->next;
       r->next->prevlist=r->prevlist;
       r->nextlist->prevlist=r->next;
       r->next->nextlist=r->nextlist;
       r=r->next;
       r->prev=NULL;
       free(q);
       mcontor1--;
     }
}
 else
      {
        q=e1=r;
        r->nextlist->prevlist=r->prevlist;
        r->prevlist->nextlist=r->nextlist;
        r=r->nextlist;
        while(q->next)
          {
            e1=q;
            q=q->next;
            free(e1);
          }
      free(q);
      }
}
/* Ma aflu la sfarsitul listei mari */
 else if(r->prev==NULL && r->prevlist!=NULL && r->nextlist==NULL)
 {
    if(q->next->data!='\n')
   {
      while(mcontor1)
     { q=r;
       r->prevlist->nextlist=r->next;
       r->next->prevlist=r->prevlist;
       r->nextlist=NULL;
       r=r->next;
       r->prev=NULL;
       LIST->TAIL=r;
       free(q);
       mcontor1--;
     }
    
  }
 else
    {
      q=r=LIST->TAIL;
      LIST->TAIL=r->prevlist;
      while(q->next)
      {
       r=q;
       q=q->next;
       free(r);
      }
      free(q);
      LIST->TAIL->nextlist=NULL;
      r=LIST->TAIL;
      goto terminare;
    }
}
/* Ma aflu la inceputul listei mari */
 else if(r->prev==NULL && r->prevlist==NULL && r->nextlist!=NULL)
 {
   if(q->data!='\n')
    {
      while(mcontor1)
        {
          q=r;
          r->next->nextlist=r->nextlist;
          r->nextlist->prevlist=r->next;
          r=r->next;
          r->prev=NULL;
          LIST->HEAD=r;
          free(q);
          mcontor1--;
       }
   }
   else
     {
        q=r=LIST->HEAD;
        LIST->HEAD=r->nextlist;
        while(q->next)
      {
       r=q;
       q=q->next;
       free(r);
      }
      free(q);
      poz=LIST->HEAD;
      LIST->HEAD->prevlist=NULL;
     }
  }
}
/* Daca mai sunt necesare stergeri 
  Reiau procesul */
  if(r!=e2)
  {
   mcontor1=mcontor2;
   h=0;
   j=1;
   r=LIST->HEAD;
   goto cautare;
  }
  terminare:
  q=list6->head;
  while(q->next)
  { r=q;
    q=q->next;
    free(r);
  }
 free(q);
 free(list6);
  }
  /* Procesul de stergere partiala */
   if(LIST2->TAIL->data=='d' && s[1]=='w')
  {  contor10++;
     dw_redo:
     e2=LIST->TAIL;
   int h=3,j=1,mcontor=0,z=0,l;
   TDoubleLinkedList *list3=NULL;
   init(&list3);
   while(s[h]!='\0')
{  if(s[h]!='\n')
    {
    sir1[z]=s[h];
    z++;
    }
   add(list3,j,s[h]);
   list3->len++;
   h++;
   j++;
}
  e1=list3->head;
  while(e1)
  {
   mcontor++;
   e1=e1->next;
  }
  mcontor--;
  e2=LIST->TAIL;
  while(e2->next)
  {
  e2=e2->next;
  if(e2->data=='\n')
  break;
  }
  e2=e2->prev;
  e1=list3->head;
  q=r=poz;
  h=0;
  /* Parcurg lista mare pentru a sterge */
  if(poz!=NULL)
{
  while(r!=e2)
 {
   if(h==mcontor)
    {
    j=0;
    break;
    }
   if(r->data==e1->data)
  {
   h++;
   if(e1->next)
   e1=e1->next;
  }
else
   {
     h=0;
     e1=list3->head;
   }
  if(r->next==NULL)
  {
   while(r->prev!=NULL)
   r=r->prev;
   r=r->nextlist;
   continue;
  }
  r=r->next;
  }
}
 if(r!=NULL)
 if(r==e2 && r->data==e1->data)
 h++;
 if(h==mcontor)
 j=0;
 /* Se trateaza toate cazurile */
   if(j==0)
{
  q=r;
  for(l=0;l<mcontor && r->prev!=NULL;l++)
  r=r->prev;
  /* Daca ma aflu pe o linie */
  if(r->prev!=NULL && r->next!=NULL)
{
   node* kl=LIST->TAIL;
   int vc=0;
   while(kl->next)
{   kl=kl->next;
    if(kl==r)
   {
   vc=1;
   break;
   }

}
   if(q->next!=NULL && vc==0)
  {
    while(mcontor && r->next)
      {
       e1=r;
       r->prev->next=r->next;
       r->next->prev=r->prev;
       r=r->next;
       free(e1);
       mcontor--;
     }
  }
  else
      if((vc==1 && r->prev!=NULL) || (vc==1 && q->next!=NULL))
   {
    if(q->next->data=='\n')
    r=r->next;
    while(mcontor && r->next)
       {
        e1=r;
        r->prev->next=r->next;
        r->next->prev=r->prev;
        r=r->next;
        free(e1);
        mcontor--;
      }
    }
  else
     if((vc==0 && r->prev!=NULL) || (vc==0 && q->next!=NULL))
  {
    while(mcontor && r->next)
       {
        e1=r;
       r->prev->next=r->next;
       r->next->prev=r->prev;
       r=r->next;
       free(e1);
       mcontor--;
      }
 }
}
/* Daca ma aflu la inceput de linie */
  if(r->prev==NULL && r->nextlist!=NULL && r->prevlist!=NULL)
{
     if(q->data!='\n')
      while(mcontor)
     { q=r;
       r->prevlist->nextlist=r->next;
       r->next->prevlist=r->prevlist;
       r->nextlist->prevlist=r->next;
       r->next->nextlist=r->nextlist;
       r=r->next;
       r->prev=NULL;
       free(q);
       mcontor--;
     }
    else
       {
         q=e1=r;
         r->nextlist->prevlist=r->prevlist;
         r->prevlist->nextlist=r->nextlist;
         r=r->nextlist;
        while(q->next)
          {
            e1=q;
            q=q->next;
            free(e1);
          }
      free(q);
       }
}
/*Daca ma aflu la sfarsit */
  if(r->prev==NULL && r->prevlist!=NULL && r->nextlist==NULL)
 {
   if(q->next->data!='\n')
  while(mcontor)
     { q=r;
       r->prevlist->nextlist=r->next;
       r->next->prevlist=r->prevlist;
       r->nextlist=NULL;
       r=r->next;
       r->prev=NULL;
       LIST->TAIL=r;
       free(q);
       mcontor--;
     }
  else
       {
      q=r=LIST->TAIL;
      LIST->TAIL=q->prevlist;
      while(q->next)
      {
       r=q;
       q=q->next;
       free(r);
      }
      free(q);
      LIST->TAIL->nextlist=NULL;
      r=LIST->TAIL;
       }
 }
 /* Daca ma aflu la inceput */
 if(r->prev==NULL && r->prevlist==NULL && r->nextlist!=NULL)
 {
  if(q->data!='\n')
  while(mcontor)
        {
          q=r;
          r->next->nextlist=r->nextlist;
          r->nextlist->prevlist=r->next;
          r=r->next;
          r->prev=NULL;
          LIST->HEAD=r;
          free(q);
          mcontor--;
       }
    else
     {
        q=r=LIST->HEAD;
        LIST->HEAD=q->nextlist;
        while(q->next)
      {
       r=q;
       q=q->next;
       free(r);
      }
      free(q);
      poz=LIST->HEAD;
      LIST->HEAD->prevlist=NULL;
     }
 }

} 
/* Inchei procesul */
  poz1=r;
  q=list3->head;
  while(q->next)
  { e1=q;
  q=q->next;
  free(e1);
  }
 free(q);
 free(list3);
 }
/* Procesul de inlocuire totala */
if(LIST2->TAIL->data=='r' && s[1]=='a')
  {
    /* Vector de liste pentru fiecare inlocuire */
   int h=3,j=1,ncontor1=0,ncontor2,y,x=1,y1,z=0,l=0,i=0;
   TDoubleLinkedList *list7=NULL,*list8[MAX];
   init(&list7);
   init(&list8[0]);
   while(s[h]!=' ')
  {
   add(list7,j,s[h]);
   list7->len++;
   h++;
   j++;
  }
 j=1;
 h=y=h+1;
 y1=y;
 while(s[h]!='\0')
 {
 add(list8[0],j,s[h]);
 list8[0]->len++;
 h++;
 j++;
 }
 /* Numar caracterele necesare */
e1=list7->head;
  while(e1)
  {
    ncontor1++;
    e1=e1->next;
   }
  ncontor2=ncontor1;
  e2=LIST->TAIL;
  while(e2->next)
  {
  e2=e2->next;
  if(e2->data=='\n')
  break;
 }
  e2=e2->prev;
  e1=list7->head;
  q=r=LIST->HEAD;
  h=0;
  if(r!=NULL)
{ 
  e1=list7->head;
  while(r!=e2)
 {
   if(h==ncontor1)
    {
     h=0;
     z++;
    }
  if(r!=NULL && e1!=NULL)
{
  if(r->data==e1->data)
  {
   h++;
  if(e1->next)
   e1=e1->next;
  }

 }
  else
      {
     h=0;
     e1=list7->head;
      }
  if(r->next==NULL)
  {
   while(r->prev!=NULL)
   r=r->prev;
   r=r->nextlist;
   continue;
  }
  r=r->next;
 }
}
  if(r!=NULL && e1!=NULL)
  if(r==e2 && r->data==e1->data)
  h++;
  if(h==ncontor1)
  z++;
  r=LIST->HEAD;
  h=0;
  /* Parcurg lista mare */
  cautare1:
  if(r!=NULL)
{ e1=list7->head;
  while(r!=e2)
 {
   if(h==ncontor1)
    {
   j=0;
   break;
    }
   if(r->data==e1->data)
  {
   h++;
   if(e1->next)
   e1=e1->next;
  }
   else
      {
     h=0;
     e1=list7->head;
      }
  if(r->next==NULL)
  {
   while(r->prev!=NULL)
   r=r->prev;
   r=r->nextlist;
  continue;
  }
  r=r->next;
 }
}
 if(r!=NULL && e1!=NULL)
 if(r==e2 && r->data==e1->data)
 h++;
 if(h==ncontor1)
 j=0;
   if(j==0)
{
  /* Tratez toate cazurile */
  q=r;
  for(l=0;l<ncontor1 && r->prev;l++)
  r=r->prev;
/* Daca ma aflu intre 2 caractere*/
 if(r->prev!=NULL && r->next!=NULL)
{
   node* kl=LIST->TAIL;
   int vc=0;
   while(kl->next)
  { kl=kl->next;
   if(kl==r)
   {
   vc=1;
   break;
   }

  }
   if(q->next!=NULL && vc==0)
  {
    while(ncontor1 && r->next)
       {
       e1=r;
       r->prev->next=r->next;
       r->next->prev=r->prev;
       r=r->next;
       free(e1);
       ncontor1--;
       }
  r=r->prev;
  list8[i]->tail->next=r->next;
  r->next->prev=list8[i]->tail;
  list8[i]->head->prev=r;
  r->next=list8[i]->head;
   }
  else
      if((vc==1 && r->prev!=NULL) || (vc==1 && q->next!=NULL))
 {
  if(q->next->data=='\n')
  {
    r=r->next;
    while(ncontor1 && r->next)
       {
        e1=r;
        r->prev->next=r->next;
        r->next->prev=r->prev;
        r=r->next;
        free(e1);
        ncontor1--;
       }
  e1=r;
  r->prev->next=NULL;
  r=r->prev;
  free(e1);
  list8[i]->head->prev=r;
  r->next=list8[i]->head;
  list8[i]->tail->next=NULL;
 goto terminare2;
 }
   else
     {
      while(ncontor1 && r->next)
       {
       e1=r;
       r->prev->next=r->next;
       r->next->prev=r->prev;
       r=r->next;
       free(e1);
       ncontor1--;
      }
  r=r->prev;
  list8[i]->tail->next=r->next;
  r->next->prev=list8[i]->tail;
  list8[i]->head->prev=r;
  r->next=list8[i]->head;
    }
 }
   else
      if((vc==0 && r->prev!=NULL) || (vc==0 && q->next!=NULL))
  {
    while(ncontor1 && r->next)
       {
       e1=r;
       r->prev->next=r->next;
       r->next->prev=r->prev;
       r=r->next;
       free(e1);
       ncontor1--;
      }
  list8[i]->head->prev=r;
  r->next=list8[i]->head;
  }
}
/* Daca ma aflu la inceputul liniei */
 else  
    if(r->prev==NULL && r->nextlist!=NULL && r->prevlist!=NULL)
  { if(q->data!='\n')
    {
      while(ncontor1)
     { q=r;
       r->prevlist->nextlist=r->next;
       r->next->prevlist=r->prevlist;
       r->nextlist->prevlist=r->next;
       r->next->nextlist=r->nextlist;
       r=r->next;
       r->prev=NULL;
       free(q);
       ncontor1--;
     }
  list8[i]->tail->next=r;
  list8[i]->head->prevlist=r->prevlist;
  r->prevlist->nextlist=list8[i]->head;
  list8[i]->head->nextlist=r->nextlist;
  r->nextlist->prevlist=list8[i]->head;
   }
   else
       { 
         q=e1=r;
         r->nextlist->prevlist=r->prevlist;
         r->prevlist->nextlist=r->nextlist;
         r=r->nextlist;
          while(q->next)
           { e1=q;
             q=q->next;
             free(e1);
           }
      free(q);
      r->prevlist->nextlist=list8[i]->head;
      list8[i]->head->prevlist=r->prevlist;
      list8[i]->head->nextlist=r;
      r->prevlist=list8[i]->head;
       }
  }
 else 
 /* Daca ma aflu la sfarsitul listei mari */
    if(r->prev==NULL && r->prevlist!=NULL && r->nextlist==NULL)
 {  
    if(q->next->data!='\n')
  {
  while(ncontor1)
     { q=r;
       r->prevlist->nextlist=r->next;
       r->next->prevlist=r->prevlist;
       r->nextlist=NULL;
       r=r->next;
       r->prev=NULL;
       free(q);
       ncontor1--;
     }
  if(list8[i]->tail->data=='\n')
  {
   list8[i]->head->next=r;
   r->prev=list8[i]->head;
   list8[i]->head->prevlist=r->prevlist;
   r->prevlist->nextlist=list8[i]->head;
   list8[i]->head->nextlist=NULL;
   LIST->TAIL=list8[i]->head;
   }
  else
     {
   list8[i]->tail->next=r;
   r->prev=list8[i]->tail;
   list8[i]->head->prevlist=r->prevlist;
   r->prevlist->nextlist=list8[i]->head;
   list8[i]->head->nextlist=NULL;
   LIST->TAIL=list8[i]->head;
    }
  }
  else
     {
      q=r=LIST->TAIL;
      LIST->TAIL=r->prevlist;
      while(q->next)
    {
     r=q;
     q=q->next;
     free(r);
    }
    free(q);
    LIST->TAIL->nextlist=NULL;
    r=LIST->TAIL;
    list8[i]->head->prevlist=r;
    r->nextlist=list8[i]->head;
    goto terminare2;
     }

 }
 /* Daca ma aflu la inceputul listei mari */
 else 
    if(r->prev==NULL && r->prevlist==NULL && r->nextlist!=NULL)
 { 
   if(q->data!='\n')
   {
  while(ncontor1)
        {
          q=r;
          r->next->nextlist=r->nextlist;
          r->nextlist->prevlist=r->next;
          r=r->next;
          r->prev=NULL;
          LIST->HEAD=r;
          free(q);
          ncontor1--;
       }
  list8[i]->tail->next=r;
  r->prev=list8[i]->tail;
  list8[i]->head->nextlist=r->nextlist;
  r->nextlist->prevlist=list8[i]->head;
  r=list8[i]->head;
  LIST->HEAD=r;
  poz=LIST->HEAD;
  }
  else
      {
       q=r=LIST->HEAD;
       LIST->HEAD=r->nextlist;
       while(q->next)
      {
       r=q;
       q=q->next;
       free(r);
      }
     free(q);
     LIST->HEAD->prevlist=NULL;
     list8[i]->head->nextlist=poz;
     poz->prevlist=list8[i]->head;
     LIST->HEAD=list8[i]->head;
     poz=LIST->HEAD;
      }
 }
}
/* Reiau procesul pentru a inlocui toate aparitiile */
 if(r!=e2 && (i+1)!=z)
  {
   i++;
   ncontor1=ncontor2;
   init(&list8[i]);
   while(s[y]!='\0')
  {
  add(list8[i],x,s[y]);
  list8[i]->len++;
  y++;
  x++;
  }
   x=1;
   y=y1;
   h=0;
   j=1;
   r=LIST->HEAD;
   goto cautare1;
  }
  /* Incheierea procesului */
 terminare2:
 if(i==z)
 {
 i--;
 free(list8[z]);
 }
 q=list7->head;
  while(q->next)
  { 
  e1=q;
  q=q->next;
  free(e1);
  }
 free(q);
 free(list7);
 for(x=0;x<=i;x++)
 free(list8[x]);
 }
 /* Procesul de inlocuire partiala */ 
  if(LIST2->TAIL->data=='r' && s[1]=='e')
  {
   re_redo:
   re_undo:
   e2=LIST->TAIL;
   int h=3,j=1,ncontor=0,z=0,l;
   TDoubleLinkedList *list4=NULL,*list5=NULL;
   init(&list4);
   init(&list5);
   /* Adaug in liste pentru a inlocui */
   while(s[h]!=' ')
  { if(s[h]!='\n')
    {
    sir2[z]=s[h];
    z++;
    }
   add(list4,j,s[h]);
   list4->len++;
   h++;
   j++;
  }
 z=0;
 j=1;
 h=h+1;
 while(s[h]!='\0')
 { if(s[h]!='\n')
   {
  sir3[z]=s[h];
  z++;
  }
 add(list5,j,s[h]);
 list5->len++;
 h++;
 j++;
 }
e1=list4->head;
  while(e1)
  {
   ncontor++;
   e1=e1->next;
   }
  e2=LIST->TAIL;
  while(e2->next)
  {
  e2=e2->next;
  if(e2->data=='\n')
  break;
 }
  e2=e2->prev;
  e1=list4->head;
  q=r=poz;
  h=0;
  /* Parcurg lista mare */
  if(poz!=NULL)
{
  while(r!=e2)
 {
   if(h==ncontor)
    {
   j=0;
   break;
    }
   if(r->data==e1->data)
  {
   h++;
   if(e1->next)
   e1=e1->next;
  }
  else
      {
   h=0;
   e1=list4->head;
     }
  if(r->next==NULL)
  {
  while(r->prev!=NULL)
  r=r->prev;
  r=r->nextlist;
  continue;
  }
  r=r->next;
  }
}
 if(r!=NULL && e1!=NULL)
 if(r==e2 && r->data==e1->data)
 h++;
 if(h==ncontor)
 j=0;
   if(j==0)
{ q=r;
/* Se trateaza toate cazurile */
  for(l=0;l<ncontor && r->prev;l++)
  r=r->prev;
  /* Daca ma aflu intre 2 caractere */
 if(r->prev!=NULL && r->next!=NULL)
{
   node* kl=LIST->TAIL;
   int vc=0;
   while(kl->next)
  { kl=kl->next;
   if(kl==r)
  {
   vc=1;
   break;
   }
  }
   if(q->next!=NULL && vc==0)
  {
    while(ncontor && r->next)
    {
       e1=r;
       r->prev->next=r->next;
       r->next->prev=r->prev;
       r=r->next;
       free(e1);
       ncontor--;
     }
  r=r->prev;
  list5->tail->next=r->next;
  r->next->prev=list5->tail;
  list5->head->prev=r;
  r->next=list5->head;
   }
  else
      if((vc==1 && r->prev!=NULL) || (vc==1 && q->next!=NULL))
   { 
    if(q->next->data=='\n')
    {
    r=r->next;
    while(ncontor && r->next)
      {
       e1=r;
       r->prev->next=r->next;
       r->next->prev=r->prev;
       r=r->next;
       free(e1);
       ncontor--;
      }
  e1=r;
  r->prev->next=NULL;
  r=r->prev;
  free(e1);
  list5->head->prev=r;
  r->next=list5->head;
  list5->tail->next=NULL;
 goto terminare1;
  }
  else
     {
      while(ncontor && r->next)
      {
       e1=r;
       r->prev->next=r->next;
       r->next->prev=r->prev;
       r=r->next;
       free(e1);
       ncontor--;
      }
  r=r->prev;
  list5->tail->next=r->next;
  r->next->prev=list5->tail;
  list5->head->prev=r;
  r->next=list5->head;
     }
 }
   else
      if((vc==0 && r->prev!=NULL) || (vc==0 && q->next!=NULL))
  {
    while(ncontor && r->next)
      {
       e1=r;
       r->prev->next=r->next;
       r->next->prev=r->prev;
       r=r->next;
       free(e1);
       ncontor--;
      }
  list5->head->prev=r;
  r->next=list5->head;
 }
}
/* Daca ma aflu la inceput de linie */
 else  
     if(r->prev==NULL && r->nextlist!=NULL && r->prevlist!=NULL)
  {  if(q->data!='\n')
    {
      while(ncontor)
     { q=r;
       r->prevlist->nextlist=r->next;
       r->next->prevlist=r->prevlist;
       r->nextlist->prevlist=r->next;
       r->next->nextlist=r->nextlist;
       r=r->next;
       r->prev=NULL;
       free(q);
       ncontor--;
     }
  list5->tail->next=r;
  list5->head->prevlist=r->prevlist;
  r->prevlist->nextlist=list5->head;
  list5->head->nextlist=r->nextlist;
  r->nextlist->prevlist=list5->head;
   }
   else
       { q=e1=r;
         r->nextlist->prevlist=r->prevlist;
         r->prevlist->nextlist=r->nextlist;
         r=r->nextlist;
          while(q->next)
           { e1=q;
             q=q->next;
             free(e1);
           }
      free(q);
      r->prevlist->nextlist=list5->head;
      list5->head->prevlist=r->prevlist;
      list5->head->nextlist=r;
      r->prevlist=list5->head;
       }
  }
  /* Daca ma aflu la sfarsitul listei mari */
 else 
     if(r->prev==NULL && r->prevlist!=NULL && r->nextlist==NULL)
 { if(q->next->data!='\n')
  {
  while(ncontor)
     { q=r;
       r->prevlist->nextlist=r->next;
       r->next->prevlist=r->prevlist;
       r->nextlist=NULL;
       r=r->next;
       r->prev=NULL;
       free(q);
       ncontor--;
     }
  list5->tail->next=r;
  list5->head->prevlist=r->prevlist;
  r->prevlist->nextlist=list5->head;
  }
   else
   {
      q=r=LIST->TAIL;
      LIST->TAIL=r->prevlist;
      while(q->next)
    {
    r=q;
    q=q->next;
    free(r);
    }
    free(q);
    LIST->TAIL->nextlist=NULL;
    r=LIST->TAIL;
    list5->head->prevlist=r;
    r->nextlist=list5->head;
    goto terminare1;
    }

 }
 /* Daca ma aflu la inceputul listei mari */
 else if(r->prev==NULL && r->prevlist==NULL && r->nextlist!=NULL)
 { if(q->data!='\n')
   {
  while(ncontor)
        {
          q=r;
          r->next->nextlist=r->nextlist;
          r->nextlist->prevlist=r->next;
          r=r->next;
          r->prev=NULL;
          LIST->HEAD=r;
          free(q);
          ncontor--;
       }
  list5->tail->next=r;
  r->prev=list5->tail;
  list5->head->nextlist=r->nextlist;
  r->nextlist->prevlist=list5->head;
  r=list5->head;
  LIST->HEAD=r;
  }
  else
      {
       q=r=LIST->HEAD;
       LIST->HEAD=r->nextlist;
       while(q->next)
      {
       r=q;
       q=q->next;
       free(r);
      }
     free(q);
     poz=LIST->HEAD;
     LIST->HEAD->prevlist=NULL;
     list5->head->nextlist=poz;
     poz->prevlist=list5->head;
     poz=list5->head;
     LIST->HEAD=poz;
      }
 }
}
/* Incheierea procesului */
 terminare1:
 poz2=r;
 q=list4->head;
  while(q->next)
  { e1=q;
  q=q->next;
  free(e1);
  }
 free(q);
 free(list4);
 free(list5);
 }
 /* Procesul de undo */
   if(LIST2->TAIL->data=='u')
    {
     char *m,*j;
     int ix=0,y;
     if(LIST2->TAIL->data!='s')
     {
    /* Undo pentru inserarea textului */
     if(LIST2->TAIL->prevlist->data==':' && LIST2->TAIL->prevlist->next->data==':')
     {
       if(lista_auxiliara!=NULL && contor10<2 && (contor9==0 || contor9==1))
      {
       q=lista_auxiliara->head;
       while(q->next)
       { r=q;
         q=q->next;
         free(r);
        }
     free(q);
     free(lista_auxiliara);
     lista_auxiliara=NULL;
      }
       if(contor10<2 && (contor9==0 || contor9==1))
       {
       int j=1;
       contor3++;
       q=r=LIST->TAIL;
       LIST->TAIL=q->prevlist;
       init(&lista_auxiliara);
      while(q->next)
      {
       r=q;
       add(lista_auxiliara,j,r->data);
       lista_auxiliara->len++;
       q=q->next;
       free(r);
       j++;
      }
      free(q);
      LIST->len--;
      LIST->TAIL->nextlist=NULL;
      poz=LIST->TAIL;
     }
    else
        if(pozcnt1==1 && contor10<2 && (contor9==0 || contor9==1))
        {
         int j=1;
         contor3++;
         q=r=LIST->TAIL;
         LIST->TAIL=q->prevlist;
         init(&lista_auxiliara);
         init(&lista_auxiliara2);
      while(q->next)
      {
       r=q;
       add(lista_auxiliara,j,r->data);
       lista_auxiliara->len++;
       q=q->next;
      free(r);
      j++;
      }
      free(q);
      LIST->len--;
      LIST->TAIL->nextlist=NULL;
      poz=LIST->TAIL;
      q=r=LIST->TAIL;
      LIST->TAIL=q->prevlist;
      j=1;
      while(q->next)
      {
       r=q;
       add(lista_auxiliara2,j,r->data);
       lista_auxiliara2->len++;
       q=q->next;
       free(r);
       j++;
      }
     free(q);
     LIST->len--;
     LIST->TAIL->nextlist=NULL;
     poz=LIST->TAIL;
    }
   }
   /* Undo pentru restul comenzilor */
   if(LIST2->TAIL->prevlist->data!='u')
     {
       /* Procesul de stergere 'd' */
      if(LIST2->TAIL->prevlist->data=='d' && LIST2->TAIL->prevlist->next->data!='l' && LIST2->TAIL->prevlist->next->data!='w' && LIST2->TAIL->prevlist->next->data!='a')
  {
    int jk,nm=0;
    m=(char *)calloc(MAX,sizeof(char));
    s1=m;
    s5=sir[0];
    s6=sir[1];
    e1=LIST2->TAIL->prevlist;
    sep=LIST2->TAIL->prevlist;
    init(&lista_auxiliara3);
    while(e1)
    { if(e1->data!='\n')
      m[ix]=e1->data;
      e1=e1->next;
      ix++;
     }
   if(strlen(m)>1)
   jk=m[2]-'0';
   else
    jk=1;
     ix=0;
     y=strlen(sir[contor5-1]);
     /* Tratez toate cazurile de stergere */
    while(y)
    {
     add(lista_auxiliara3,jx,sir[contor5-1][ix]);
     lista_auxiliara3->len++;
     jx++;
     ix++;
     y--;
    }
    if(poz->prev!=NULL && poz->next!=NULL && contor1!=1)
   {
     nm=1;
    contor12++;
    lista_auxiliara3->tail->next=poz->next;
    lista_auxiliara3->head->prev=poz;
    poz->next->prev=lista_auxiliara3->tail;
    poz->next=lista_auxiliara3->head;
   }
   /* Daca ma aflu la inceputul listei mari */
   else
       if(poz==LIST->HEAD)
     { 
        lista_auxiliara3->tail->next=poz;
        lista_auxiliara3->head->nextlist=poz->nextlist;
        poz->nextlist->prevlist=lista_auxiliara3->head;
        poz->prev=lista_auxiliara3->tail;
        LIST->HEAD=lista_auxiliara3->head;
    }
    /* Daca ma aflu la sfarsitul listei mai */
    else
       if(poz==LIST->TAIL)
    { 
      lista_auxiliara3->tail->next=poz;
      lista_auxiliara3->head->prevlist=poz->prevlist;
      poz->prevlist->nextlist=lista_auxiliara3->head;
      poz->prev=lista_auxiliara3->tail;
      LIST->TAIL=lista_auxiliara3->head;
   }
   /* Ultimul caz */
    else
        if(((contor1==1 && contor2!=1) || contor!=1 ) && poz!=LIST->HEAD && poz!=LIST->TAIL)
   { 
     lista_auxiliara3->tail->next=poz;
     lista_auxiliara3->head->prevlist=poz->prevlist;
     poz->prevlist->nextlist=lista_auxiliara3->head;
     lista_auxiliara3->head->nextlist=poz->nextlist;
     poz->nextlist->prevlist=lista_auxiliara3->head;
     poz->prev=lista_auxiliara3->tail;

   }
   if(nm!=1)
   for(ix=0;ix<jk;ix++)
   poz=poz->prev;
   /* Introduc comanda  in stiva */
   adaugare_stiva(st,m);
   lista_auxiliara3->len=0;
   free(lista_auxiliara3);
   }
   /* Undo pentru 'back' */
     else
         if(LIST2->TAIL->prevlist->data=='b')
       {
        j=(char *)calloc(2,sizeof(char));
        node* mk=(node *)calloc(1,sizeof(node));
        mk->data=ch;
        sep=LIST2->TAIL->prevlist;
        j[0]='b';
        j[1]='\0';
        if(poz==LIST->HEAD)
        { mk->next=poz;
          poz->prevlist->nextlist=mk;
          mk->nextlist=poz->nextlist;
          poz->prev=mk;
          LIST->HEAD=mk;
        }
        /* Tratez toate cazurile */
       else
          if(poz!=LIST->HEAD && poz!=LIST->TAIL && (contor1==1 && contor2!=1))
       {
        mk->next=poz;
        mk->nextlist=poz->nextlist;
        mk->prevlist=poz->prevlist;
        poz->prevlist->nextlist=mk;
        poz->nextlist->prevlist=mk;
        poz->prev=mk;
       }
      else
         if(poz!=LIST->HEAD && poz!=LIST->TAIL && contor1!=1)
     {
       mk->next=poz;
       mk->prev=poz->prev;
       poz->prev->next=mk;
       poz->prev=mk;
      }
      /* Daca ma aflu la sfarsit */
       else
           if(poz==LIST->TAIL)
        {
          mk->next=poz;
          poz->prevlist->nextlist=mk;
          mk->prevlist=poz->prevlist;
          poz->prev=mk;
          LIST->TAIL=mk;
        }
     else
         if(poz->next==NULL)
       { mk->prev=poz;
         poz->next=mk;
         mk->next=NULL;
       }
    poz=poz->prev;
    /* Adaug in stiva */
    adaugare_stiva(st,j);
      }
  else
 /* Undo pentru 'gc' */
       if(LIST2->TAIL->prevlist->data=='g' && LIST2->TAIL->prevlist->next->data=='c')
      {
        m=(char *)calloc(MAX-5,sizeof(char));
        s7=m;
        e1=LIST2->TAIL->prevlist;
        sep=LIST2->TAIL->prevlist;
        ix=0;
        while(e1)
        {
         if(e1->data!='\n')
         m[ix]=e1->data;
         e1=e1->next;
         ix++;
         }
         /* Ma duc inapoi cu poz (cursorul) */
       poz=vechi1;
       /* Adaug in stiva */
       adaugare_stiva(st,m);
      }
/* Undo pentru 'gl' */
  else
     if(LIST2->TAIL->prevlist->data=='g' && LIST2->TAIL->prevlist->next->data=='l')
     {  m=(char *)calloc(MAX,sizeof(char));
        s1=m;
        e1=LIST2->TAIL->prevlist;
        sep=LIST2->TAIL->prevlist;
        ix=0;
        while(e1)
         {
         if(e1->data!='\n')
         m[ix]=e1->data;
         e1=e1->next;
         ix++;
         }
         /* Ma duc inapoi cu poz (cursorul) */
      poz=vechi;
      /* Adaug in stiva */
      adaugare_stiva(st,m);
     }
  else
  /* Undo pentru stergerea partiala */
      if(LIST2->TAIL->prevlist->data=='d' && LIST2->TAIL->prevlist->next->data=='w')
   {
    m=(char *)calloc(MAX,sizeof(char));
    s8=m;
    s2=sir1;
    e1=LIST2->TAIL->prevlist;
    sep=LIST2->TAIL->prevlist;
    if(contor12!=1)
   {
    init(&lista_auxiliara1);
    while(e1)
    { if(e1->data!='\n')
      m[ix]=e1->data;
      e1=e1->next;
      ix++;
     }
     ix=0;
     y=strlen(sir1);
     /* Adaug in lista */
    while(y)
    {
     add(lista_auxiliara1,jx,sir1[ix]);
     lista_auxiliara1->len++;
     jx++;
     ix++;
     y--;
    }
   }
     y=0;
     /* Tratez toate cazurile */
   if(poz1!=NULL && contor12==0)
  {
    if(poz1->next!=NULL && poz1->prev!=NULL)
   { y++;
    lista_auxiliara1->tail->next=poz1;
    lista_auxiliara1->head->prev=poz1->prev;
    poz1->prev->next=lista_auxiliara1->head;
    poz1->prev=lista_auxiliara1->tail;
   }
   else
   /* Daca ma aflu la inceput */
       if(poz1==LIST->HEAD)
     { y++;
       lista_auxiliara1->tail->next=poz1;
       lista_auxiliara1->head->nextlist=poz1->nextlist;
       poz1->nextlist->prevlist=lista_auxiliara1->head;
       poz1->prev=lista_auxiliara1->tail;
       LIST->HEAD=lista_auxiliara1->head;
    }
      else
    /* Daca ma aflu la sfarsit */
       if(poz1==LIST->TAIL)
    { lista_auxiliara1->tail->next=poz1;
      lista_auxiliara1->head->prevlist=poz1->prevlist;
      poz1->prevlist->nextlist=lista_auxiliara1->head;
      poz1->prev=lista_auxiliara1->tail;
      LIST->TAIL=lista_auxiliara1->head;
      y++;
   }
    else
        if(poz1->nextlist!=NULL && poz1->prevlist!=NULL && poz1!=LIST->HEAD && poz1!=LIST->TAIL)
   { e1=lista_auxiliara1->head;
      while(e1->next)
      { e2=e1;
        e1=e1->next;
        free(e2);
       }
       free(e1);
      contor11++;
   }
 }
   if(y==1)
    /* Adaug in stiva */
   adaugare_stiva(st,m);
   if(contor12==0)
   free(lista_auxiliara1);
    }
  else
  /* Undo pentru inlocuirea partiala */
     if(LIST2->TAIL->prevlist->data=='r' && LIST2->TAIL->prevlist->next->data=='e' && contor6!=1)
  { char* p=NULL;
    p=(char* )calloc(MAX,sizeof(char));
    m=(char *)calloc(MAX,sizeof(char));
    s1=m;
    s3=sir2;
    s4=sir3;
    e1=LIST2->TAIL->prevlist;
     while(e1)
    { if(e1->data!='\n')
      m[ix]=e1->data;
      e1=e1->next;
      ix++;
     }
    ix=0;
    p[0]='r';
    p[1]='e';
    p[2]=' ';
   ix=3;
   /* Inversez argumentele comenzii */
   while(sir3[ix-3]!='\0')
   {
   p[ix]=sir3[ix-3];
   ix++;
   }
  y=0;
   p[strlen(p)]=' ';
   ix=strlen(p);
   while(sir2[y]!='\0')
  {
   p[ix]=sir2[y];
   y++;
   ix++;
   }
   ix=0;
   for(ix=0;ix<=strlen(p);ix++)
   s[ix]=p[ix];
   s[strlen(p)]='\n';
   /* Adaug in stiva */
   adaugare_stiva(st,m);
   contor6++;
   free(p);
   goto re_undo;
   }
  } 
 }
}
/* Procesul de redo */
   if(LIST2->TAIL->data=='r')
   /* Redo pentru inserarea textului */
  {  if(s[1]!='a' && s[1]!='e' && strlen(s)==2)
      {
       if(contor3!=0)
       {
        add1(LIST,lista_auxiliara);
        LIST->len++;
        contor4=1;
        contor3--;
      }
      /* Redo pentru restul comenzilor */
      else
          if(verif_stiva_goala(st)==1 && st->top!=NULL && st->len!=0)
          {
             char str[MAX];
             int l;
            strcpy(str,eliminare_stiva(st));
            for(l=0;l<=strlen(str);l++)
            s[l]=str[l];
            if(strlen(str)!=1)
           {
              /*Daca in stiva am 'd' */
            if(str[0]=='d' && str[1]!='w' && str[1]!='a' && str[1]!='l')
           {
             s[strlen(str)]='\n';
            goto d_redo;
          }
            else
                 /*Daca in stiva am 'gc' */
              if(str[0]=='g' && str[1]=='c')
            {
             goto gc_redo;
            }
            else
                /*Daca in stiva am 'gl' */
               if(str[0]=='g' && str[1]=='l')
            {
              goto gl_redo;
            }
            else
                 /*Daca in stiva am 'dw' */
                if(str[0]=='d' && str[1]=='w' && contor11!=1)
               {
              s[strlen(str)]='\n';
              goto dw_redo;
              }
            else
                /*Daca in stiva am 're' */
               if(str[0]=='r' && str[1]=='e')
             { contor6--;
               goto re_redo;
             }
          }
          else
              /*Daca in stiva am 'd' si lungimea este 1*/
              if(str[0]=='d')
            {
              s[strlen(str)]='\n';
              goto d_redo;
            }
           else
               /*Daca in stiva am 'b' si lungimea este 1*/
                if(str[0]=='b')
             {
                goto b_redo;
             }
      }
     }
    }
    /* Procesul de mutare 'gl' */
    if(LIST2->TAIL->data=='g' && s[1]=='l')
     { gl_redo:
       contor=s[3]-'0';
      int l;
       if(poz==NULL)
       vechi1=LIST->HEAD;
       poz=LIST->HEAD;
       for(l=1;l<contor;l++)
       poz=poz->nextlist;
       pozcnt=1;
       vechi1=poz;
     }
     /* Procesul de stergere 'back' */
     if(LIST2->TAIL->data=='b')
     {   b_redo:
            r=LIST->HEAD;
            int fl=0,fl1=0;
            /*  La sfarsit de linie */
           while(r!=LIST->TAIL)
          {
           if(r==poz)
          {
           fl=1;
           break;
           }
           r=r->nextlist;
           }
         r=LIST->TAIL;
      while(r->next)
       {
         if(r==poz)
         {
           fl1=1;
           break;
          }
         r=r->next;
       }
      if(pozcnt==0 && pozcnt1!=1)
      {
       q=r=LIST->TAIL;
       while(q->next)
      { contor++;
       q=q->next;
      }
      contor++;
      if(contor==2)
       {  LIST->TAIL=r->prevlist;
          ch=LIST->TAIL->data;
          free(q);
          free(r);
          LIST->TAIL->nextlist=NULL;
       }
    else {
      q=q->prev;
      r=q;
      ch=r->data;
      q->prev->next=q->next;
      q->next->prev=q->prev;
      free(r);
      }
     contor=0;
      }
      /* Tratez toate cazurile */
      else
         if((fl==1 && poz!=LIST->TAIL && poz!=LIST->HEAD) || (contor1==1 && poz!=LIST->TAIL && poz!=LIST->HEAD))
       {
       q=poz;
       ch=poz->data;
       poz->next->prevlist=poz->prevlist;
       poz->prevlist->nextlist=poz->next;
       poz->nextlist->prevlist=poz->next;
       poz->next->nextlist=poz->nextlist;
       poz=poz->next;
       poz->prev=NULL;
       free(q);
       }
      else
      /*La inceputul ultimei linii */
          if((pozcnt==1 && poz==LIST->TAIL) || (contor1==1 && poz==LIST->TAIL))
      {
       q=poz;
       ch=poz->data;
       poz->next->prevlist=poz->prevlist;
       poz->prevlist->nextlist=poz->next;
       poz->next->nextlist=NULL;
       poz=poz->next;
       poz->prev=NULL;
        free(q);
        }
     else
       /* La inceputul primei linii */
         if((pozcnt==1 && poz==LIST->HEAD) || (contor1==1 && poz==LIST->HEAD))
        {
        q=poz;
        ch=poz->data;
        LIST->HEAD=poz->next;
        LIST->HEAD->nextlist=poz->nextlist;
        poz->nextlist->prevlist=LIST->HEAD;
        LIST->HEAD->prevlist=NULL;
        poz=LIST->HEAD;
        free(q);
       }
       /*Restul cazurilor */
     else
         if(fl1==0)
      {
       q=poz;
       ch=poz->data;
       poz->prev->next=poz->next;
       poz->next->prev=poz->prev;
       poz=poz->prev;
       free(q);
      }
      else
      {
        q=poz;
        ch=poz->data;
        poz->prev->next=poz->next;
        poz->next->prev=poz->prev;
        poz=poz->next;
        free(q);
    }
   }
   /* Procesul de mutare 'gc' */
    if(LIST2->TAIL->data=='g' && s[1]=='c')
    { gc_redo:
     contor1=s[3]-'0';
     int l;
     /* Daca am doar un argument */
     if(strlen(s)==5 && pozcnt==0)
    {
     vechi=poz;
     poz=LIST->TAIL;
    for(l=1;l<contor1;l++)
    poz=poz->next;
    pozcnt1=1;
    }
    else
        if(pozcnt==1 && strlen(s)==5)
        { for(l=1;l<contor1;l++)
          poz=poz->next;
          pozcnt1=1;
        }
        /* Daca am 2 argumente */
     if(strlen(s)==7)
       { if(poz==NULL)
        vechi=LIST->HEAD;
        else
        vechi=poz;
        contor2=s[5]-'0';
        poz=LIST->HEAD;
      /* Mut cursorul */
        for(l=1;l<contor2 && poz->nextlist;l++)
        poz=poz->nextlist;
        for(l=1;l<contor1 && poz->next;l++)
       { if(poz->next->data=='\n' && poz->next->next==NULL)
         { 
           break;
           pozcnt1=1;
          }
        poz=poz->next;
        if(poz->data=='\n')
        poz=poz->next;
        pozcnt1=1;
       }
   }
}
/* Procesul de stergere 'd' */
    if(LIST2->TAIL->data=='d')
    {  d_redo:
         if(s[1]=='l')
         goto dl;
     else
        if(s[1]!='w' && s[1]!='a')
       {
      if(contor5>1)
    {
       contor5=0;
    }
      int h=0,z=0,fl=0;
      if(strlen(s)!=2)
      h=s[2]-'0';
      r=LIST->TAIL;
      while(r->next)
     {
        if(r==poz)
        {
         fl=1;
        break;
        }
      r=r->next;
      }
      /* Tratez toate cazurile */
       if(h==0 && poz->prev!=NULL && fl==0)
      {
        poz3=poz;
        poz3=poz3->next;
        sir[contor5][z]=poz3->data;
        z++;
        q=poz3;
        poz3->prev->next=poz3->next;
        poz3->next->prev=poz3->prev;
        free(q);
       }
     else
     /* Daca ma aflu intre 2 caractere pe ultima linie */
         if(h==0 && poz->prev!=NULL && fl==1)
       {
        sir[contor5][z]=poz->data;
        z++;
        q=poz;
        poz->prev->next=poz->next;
        poz->next->prev=poz->prev;
        free(q);
        }
      else
      /* Daca ma aflu intre 2 caractere */
        if(poz->prev!=NULL && poz->next!=NULL && fl==0)
       {
         r=poz;
         r=r->next;
        while(h && r->next)
       { 
        sir[contor5][z]=r->data;
        z++;
        q=r;
        r->prev->next=r->next;
        r->next->prev=r->prev;
        free(q);
        h--;
       }
      if(poz->next==NULL && h!=0)
        { 
         sir[contor5][z]=poz->data;
         z++;
         q=poz;
         poz->prev->next=NULL;
         poz=poz->prev;
         free(q);
        }
      }
   else
       /* Daca ma aflu intre 2 caractere pe ultima linie (argumentul comenzii este diferit de 0*)*/
        if(poz->prev!=NULL && poz->next!=NULL && fl==1)
       {
        while(h && r->next)
       { sir[contor5][z]=r->data;
         z++;
         q=poz;
         poz->prev->next=poz->next;
         poz->next->prev=poz->prev;
         free(q);
         h--;
       }
      if(poz->next==NULL && h!=0)
        { sir[contor5][z]=poz->data;
         z++;
         q=poz;
         poz->prev->next=NULL;
         poz=poz->prev;
         free(q);
         }
      }
        else
           /* Daca ma aflu la inceput de linie */
            if(poz->prev==NULL && poz!=LIST->HEAD && poz!=LIST->TAIL)
           {
              while(h)
             {
            sir[contor5][z]=poz->data;
            z++;
            q=poz;
            poz->prevlist->nextlist=poz->next;
            poz->next->prevlist=poz->prevlist;
            poz->nextlist->prevlist=poz->next;
            poz->next->nextlist=poz->nextlist;
            poz=poz->next;
            poz->prev=NULL;
            free(q);
            h--;
            }
            }
        else
            /* Daca ma aflu pe prima linie  */
            if(poz==LIST->HEAD)
         {
         while(h)
        { sir[contor5][z]=poz->data;
          z++;
          q=poz;
          poz->next->nextlist=poz->nextlist;
          poz->nextlist->prevlist=poz->next;
          poz=poz->next;
          poz->prev=NULL;
          LIST->HEAD=poz;
          free(q);
          h--;
       }
         }
     else
           /* Daca ma aflu pe ultima linie  */
         if(poz==LIST->TAIL)
     {
          while(h)
        {  sir[contor5][z]=poz->data;
           z++;
           q=poz;
           poz->next->prevlist=poz->prevlist;
           poz->prevlist->nextlist=poz->next;
           poz=poz->next;
           poz->prev=NULL;
           LIST->TAIL=poz;
           free(q);
           h--;
        }
    }
     contor5++;
     }
}
 /* Procesul de stergere 'dl' */
    if(LIST2->TAIL->data=='d' && s[1]=='l')
    {
       dl:
        r=LIST->HEAD;
        int fl=0,l;
        while(r!=LIST->TAIL)
        {
        if(r==poz)
        {
        fl=1;
        break;
        }
       r=r->nextlist;
       }
       contor9++;
       int c=s[3]-'0';
      if(strlen(s)==3 && fl==1 && pozcnt1!=1)
      {
         /* Stergerea ultimei linii */
      if(pozcnt==0 || poz==LIST->TAIL)
      { 
      q=r=LIST->TAIL;
      LIST->TAIL=q->prevlist;
      while(q->next)
      {
       r=q;
       q=q->next;
       free(r);
      }
      free(q);
      LIST->TAIL->nextlist=NULL;
      poz=LIST->TAIL;
      }
     else
         /* Stergerea unei linii */
      if(poz!=LIST->HEAD)
        { q=r=poz;
          poz->nextlist->prevlist=poz->prevlist;
          poz->prevlist->nextlist=poz->nextlist;
          poz=poz->nextlist;
        while(q->next)
          {
            r=q;
            q=q->next;
            free(r);
          }
      free(q);
       }
     else
        {
             /* Stergerea primei linii  */
         q=r=LIST->HEAD;
         LIST->HEAD=q->nextlist;
         while(q->next)
      {
       r=q;
       q=q->next;
       free(r);
      }
        free(q);
        poz=LIST->HEAD;
        LIST->HEAD->prevlist=NULL;
      }
   }
     else
     /* Daca mut cursorul folosind 'gc' */
          if(pozcnt1==1)
        {
         q=LIST->HEAD;
         while(poz->prev)
         poz=poz->prev;
         while(q!=poz)
         q=q->nextlist;
        if(poz==LIST->HEAD)
        {
         LIST->HEAD=q->nextlist;
        while(q->next)
      {
       poz=q;
       q=q->next;
       free(poz);
      }
        free(q);
        poz=LIST->HEAD;
        LIST->HEAD->prevlist=NULL;
      }
    /* Tratez toate cazurile */
      else
         if(poz!=LIST->HEAD && poz!=LIST->TAIL)
        {
         q=r=poz;
         poz->nextlist->prevlist=poz->prevlist;
         poz->prevlist->nextlist=poz->nextlist;
         poz=poz->nextlist;
        while(q->next)
          {
            r=q;
            q=q->next;
            free(r);
          }
      free(q);
         }
     else
     /* Daca ma aflu pe ultima linie */
         if(poz==LIST->TAIL)
       {
       q=r=LIST->TAIL;
       LIST->TAIL=q->prevlist;
       while(q->next)
      {
       r=q;
       q=q->next;
       free(r);
      }
      free(q);
      LIST->TAIL->nextlist=NULL;
      poz=LIST->TAIL;
           }
       }
      else
         {
             /* Daca ma aflu pe prima linie */
           poz1=LIST->HEAD;
           for(l=1;l<c;l++)
           poz1=poz1->nextlist;
         if(poz1==LIST->HEAD)
             {
            poz1=q=LIST->HEAD;
            LIST->HEAD=poz1->nextlist;
            while(q->next)
           {
            poz1=q;
            q=q->next;
            free(poz1);
            }
          free(q);
         LIST->HEAD->prevlist=NULL;
         
           }
               /* Daca ma aflu pe o linie*/
          else
             if(poz1!=LIST->HEAD && poz1!=LIST->TAIL)
             {  q=r=poz1;
                poz1->nextlist->prevlist=poz1->prevlist;
                poz1->prevlist->nextlist=poz1->nextlist;
           while(q->next)
          {
            r=q;
            q=q->next;
            free(r);
          }
      free(q);    
           }
         else
             /* Daca ma aflu pe ultima linie */
             {
             q=poz1=LIST->TAIL;
             LIST->TAIL=poz1->prevlist;
           while(q->next)
            {
            poz1=q;
            q=q->next;
            free(poz1);
            }
          free(q);
           }
         LIST->TAIL->nextlist=NULL;
       }
    }
     fgets(s,MAX,stdin);
     init(&list2);
     for(i=1;i<=strlen(s);i++)
     {
     add(list2,i,*(s+i-1));
     list2->len++;
     }
     /* Adaug comenzile in lista de liste LIST2 */
     add1c(LIST2,list2);
     free(list2);
     LIST2->len++;
     if(LIST2->TAIL->data==':' && s[2]=='i')
   break;
     }
   }
     if(cnt==1)
     break;
     fgets(s,MAX,stdin);
     if(s[0]==':' && s[1]==':')
     goto comenzi1;
}
/* Eliberez toata memoria */
  free(s);
if(s7!=NULL)
  free(s7);
if(s8!=NULL)
  free(s8);
if(s3!=NULL)
 {
  free(s3);
 }
else
{
  free(sir2);
}
if(s4!=NULL)
  {
  free(s4);
  }
else
  {
  free(sir3);
  }
if(s5!=NULL)
 {
 free(s5);
 }
else
 {
 free(sir[0]);
 }
if(s6!=NULL)
 {
 free(s6);
 }
else
 {
  free(sir[1]);
 }
if(s1!=NULL)
 {
  free(s1);
 }
if(s2!=NULL)
  {
  free(s2);
  }
else
  {
   free(sir1);
  }
  free(LIST);
if(lista_auxiliara!=NULL && contor4==1)
free(lista_auxiliara);
 else
 {
      if(lista_auxiliara!=NULL && contor4==0)
   {
       q=lista_auxiliara->head;
       while(q->next)
       { r=q;
         q=q->next;
        free(r);
       }
     free(q);
     free(lista_auxiliara);
     lista_auxiliara=NULL;
    }
}
  if(lista_auxiliara2!=NULL)
 {
   q=lista_auxiliara2->head;
       while(q->next)
       { r=q;
         q=q->next;
        free(r);
        }
     free(q);
     free(lista_auxiliara2);
     lista_auxiliara2=NULL;
 }
  free(st);
  q=e=LIST2->HEAD;
  r=LIST2->HEAD->nextlist;
     while(r)
    {
      while(q->next)
       { e=q;
         q=q->next;
         free(e);
      }
     free(q);
     q=r;
     r=r->nextlist;
     }
    while(q->next)
     {
    e=q;
    q=q->next;
    free(e);
      }
  free(q);
  free(LIST2);
  fclose(f1);
  fclose(f2);
  return 0;
}
