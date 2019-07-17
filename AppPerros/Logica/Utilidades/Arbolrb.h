#ifndef ARBOLERB_H     
#define ARBOLERB_H 
#include<iostream>
#include "lista.h"

using namespace std;


template<class T,class O>
struct node

{

       T key;
       
       O order;

       node *parent;

       char color;

       node *left;

       node *right;

};


template<class T,class O>
class RBtree

{
	Lista<T> lista;
      node<T,O> *root;

      node<T,O> *q;

   public :

      RBtree()

      {

              q=NULL;

              root=NULL;

      }

      void insert(T nodo, O ord);

      void insertfix(node<T,O> *);

      void leftrotate(node<T,O> *);

      void rightrotate(node<T,O> *);

      void del(O x);

      node<T,O>* successor(node<T,O> *);

      void delfix(node<T,O> *);

      void disp();

      void display( node<T,O> *);

      void searchPrint(O x);
      node<T,O> *search(O x);
      
      void toLista(node<T,O> *);
      void arbolToLista();
      
      Lista<T> getLista(){return lista;}
      

};




template<class T, class O>
void RBtree<T,O>::insert(T nodo, O ord)

{

     int i=0;

     

     node<T,O> *p,*q;

     node<T,O> *t=new node<T,O>;
        
     t->order = ord;
     t->key=nodo;

     t->left=NULL;

     t->right=NULL;

     t->color='r';

     p=root;

     q=NULL;

     if(root==NULL)

     {

           root=t;

           t->parent=NULL;

     }

     else

     {

         while(p!=NULL)

         {

              q=p;

              if(p->order<t->order)

                  p=p->right;

              else

                  p=p->left;

         }

         t->parent=q;

         if(q->order<t->order)

              q->right=t;

         else

              q->left=t;

     }

     insertfix(t);

}

template<class T,class O>
void RBtree<T,O>::insertfix(node<T,O> *t)

{

     node<T,O> *u;

     if(root==t)

     {

         t->color='b';

         return;

     }

     while(t->parent!=NULL&&t->parent->color=='r')

     {

           node<T,O> *g=t->parent->parent;

           if(g->left==t->parent)

           {

                        if(g->right!=NULL)

                        {

                              u=g->right;

                              if(u->color=='r')

                              {

                                   t->parent->color='b';

                                   u->color='b';

                                   g->color='r';

                                   t=g;

                              }

                        }

                        else

                        {

                            if(t->parent->right==t)

                            {

                                 t=t->parent;

                                 leftrotate(t);

                            }

                            t->parent->color='b';

                            g->color='r';

                            rightrotate(g);

                        }

           }

           else

           {

                        if(g->left!=NULL)

                        {

                             u=g->left;

                             if(u->color=='r')

                             {

                                  t->parent->color='b';

                                  u->color='b';

                                  g->color='r';

                                  t=g;

                             }

                        }

                        else

                        {

                            if(t->parent->left==t)

                            {

                                   t=t->parent;

                                   rightrotate(t);

                            }

                            t->parent->color='b';

                            g->color='r';

                            leftrotate(g);

                        }

           }

           root->color='b';

     }

}


template<class T,class O>
void RBtree<T,O>::del(O x)

{

     if(root==NULL)

     {

           cout<<"\nEmpty Tree." ;

           return ;

     }
     

     node<T,O> *p;

     p=root;

     node<T,O> *y=NULL;

     node<T,O> *q=NULL;

     int found=0;

     while(p!=NULL&&found==0)

     {

           if(p->order==x)

               found=1;

           if(found==0)

           {

                 if(p->order<x) p=p->right;

                 else

                    p=p->left;

           }

     }

     if(found==0)

     {

            cout<<"\nElement Not Found.";

            return ;

     }

     else

     {

         cout<<"\nDeleted Element: "<<p->order;

         cout<<"\nColour: "; if(p->color=='b')

     cout<<"Black\n";

    else

     cout<<"Red\n"; if(p->parent!=NULL)

               cout<<"\nParent: "<<p->parent->order;

         else

               cout<<"\nThere is no parent of the node. "; if(p->right!=NULL)

               cout<<"\nRight Child: "<<p->right->order;

         else

               cout<<"\nThere is no right child of the node. "; if(p->left!=NULL)

               cout<<"\nLeft Child: "<<p->left->order;

         else

               cout<<"\nThere is no left child of the node.  ";

         cout<<"\nNode Deleted."; if(p->left==NULL||p->right==NULL)

              y=p;

         else

              y=successor(p);

         if(y->left!=NULL)

              q=y->left;

         else

         {

              if(y->right!=NULL)

                   q=y->right;

              else

                   q=NULL;

         }

         if(q!=NULL)

              q->parent=y->parent;

         if(y->parent==NULL)

              root=q;

         else

         {

             if(y==y->parent->left)

                y->parent->left=q;

             else

                y->parent->right=q;

         }

         if(y!=p)

         {

             p->color=y->color;

             p->order=y->order;

         }

         if(y->color=='b')

             delfix(q);

     }

}


template<class T,class O>
void RBtree<T,O>::delfix(node<T,O> *p)

{

    node<T,O> *s;

    while(p!=root&&p->color=='b')

    {

          if(p->parent->left==p)

          {

                  s=p->parent->right;

                  if(s->color=='r')

                  {

                         s->color='b';

                         p->parent->color='r';

                         leftrotate(p->parent);

                         s=p->parent->right;

                  }

                  if(s->right->color=='b'&&s->left->color=='b')

                  {

                         s->color='r';

                         p=p->parent;

                  }

                  else

                  {

                      if(s->right->color=='b')

                      {

                             s->left->color=='b';

                             s->color='r';

                             rightrotate(s);

                             s=p->parent->right;

                      }

                      s->color=p->parent->color;

                      p->parent->color='b';

                      s->right->color='b';

                      leftrotate(p->parent);

                      p=root;

                  }

          }

          else

          {

                  s=p->parent->left;

                  if(s->color=='r')

                  {

                        s->color='b';

                        p->parent->color='r';

                        rightrotate(p->parent);

                        s=p->parent->left;

                  }

                  if(s->left->color=='b'&&s->right->color=='b')

                  {

                        s->color='r';

                        p=p->parent;

                  }

                  else

                  {

                        if(s->left->color=='b')

                        {

                              s->right->color='b';

                              s->color='r';

                              leftrotate(s);

                              s=p->parent->left;

                        }

                        s->color=p->parent->color;

                        p->parent->color='b';

                        s->left->color='b';

                        rightrotate(p->parent);

                        p=root;

                  }

          }

       p->color='b';

       root->color='b';

    }

}


template<class T,class O>
void RBtree<T,O>::leftrotate(node<T,O> *p)

{

     if(p->right==NULL)

           return ;

     else

     {

           node<T,O> *y=p->right;

           if(y->left!=NULL)

           {

                  p->right=y->left;

                  y->left->parent=p;

           }

           else

                  p->right=NULL;

           if(p->parent!=NULL)

                y->parent=p->parent;

           if(p->parent==NULL)

                root=y;

           else

           {

               if(p==p->parent->left)

                       p->parent->left=y;

               else

                       p->parent->right=y;

           }

           y->left=p;

           p->parent=y;

     }

}
template<class T,class O>
void RBtree<T,O>::rightrotate(node<T,O> *p)

{

     if(p->left==NULL)

          return ;

     else

     {

         node<T,O> *y=p->left;

         if(y->right!=NULL)

         {

                  p->left=y->right;

                  y->right->parent=p;

         }

         else

                 p->left=NULL;

         if(p->parent!=NULL)

                 y->parent=p->parent;

         if(p->parent==NULL)

               root=y;

         else

         {

             if(p==p->parent->left)

                   p->parent->left=y;

             else

                   p->parent->right=y;

         }

         y->right=p;

         p->parent=y;

     }

}


template<class T,class O>
node<T,O>* RBtree<T,O>::successor(node<T,O> *p)

{

      node<T,O> *y=NULL;

     if(p->left!=NULL)

     {

         y=p->left;

         while(y->right!=NULL)

              y=y->right;

     }

     else

     {

         y=p->right;

         while(y->left!=NULL)

              y=y->left;

     }

     return y;

}


template<class T,class O>
void RBtree<T,O>::disp()

{

     display(root);

}
template<class T,class O>
void RBtree<T,O>::display(node<T,O> *p)

{

     if(root==NULL)

     {

          cout<<"\nEmpty Tree.";

          return ;

     }

     if(p!=NULL)

     {

                cout<<"\n\t NODE: ";

                cout<<"\n Key: "<<p->order;

                cout<<"\n Colour: "; if(p->color=='b')

     cout<<"Black";

    else

     cout<<"Red"; if(p->parent!=NULL)

                       cout<<"\n Parent: "<<p->parent->order;

                else

                       cout<<"\n There is no parent of the node. "; if(p->right!=NULL)

                       cout<<"\n Right Child: "<<p->right->order;

                else

                       cout<<"\n There is no right child of the node. "; if(p->left!=NULL)

                       cout<<"\n Left Child: "<<p->left->order;

                else

                       cout<<"\n There is no left child of the node.  ";

                cout<<endl; if(p->left)

    {

                 cout<<"\n\nLeft:\n"; display(p->left);

    }

    /*else

     cout<<"\nNo Left Child.\n";*/ if(p->right)

    {

     cout<<"\n\nRight:\n"; display(p->right);

    }

    /*else

     cout<<"\nNo Right Child.\n"*/

     }

}

template<class T,class O>
void RBtree<T,O>::searchPrint(O x)

{

     if(root==NULL)

     {

           cout<<"\nEmpty Tree\n" ;

           return  ;

     }
     

     node<T,O> *p=root;

     int found=0;

     while(p!=NULL&& found==0)

     {

            if(p->order==x)

                found=1;

            if(found==0)

            {

                 if(p->order<x) p=p->right;

                 else

                      p=p->left;

            }

     }

     if(found==0)

          cout<<"\nElement Not Found.";

     else

     {

                cout<<"\n\t FOUND NODE: ";

                cout<<"\n Key: "<<p->order;

                cout<<"\n Colour: "; if(p->color=='b')

     cout<<"Black";

    else

     cout<<"Red"; if(p->parent!=NULL)

                       cout<<"\n Parent: "<<p->parent->order;

                else

                       cout<<"\n There is no parent of the node. "; if(p->right!=NULL)

                       cout<<"\n Right Child: "<<p->right->order;

                else

                       cout<<"\n There is no right child of the node. "; if(p->left!=NULL)

                       cout<<"\n Left Child: "<<p->left->order;

                else

                       cout<<"\n There is no left child of the node.  ";

                cout<<endl;



     }

}

template<class T,class O>
node<T,O> * RBtree<T,O>::search(O x)

{

     if(root==NULL)

     {

           //cout<<"\nEmpty Tree\n" ;

           return  NULL;

     }
     

     node<T,O> *p=root;

     int found=0;

     while(p!=NULL&& found==0)

     {

            if(p->order==x)

                found=1;
                return p;

            if(found==0)

            {

                 if(p->order<x) p=p->right;

                 else

                      p=p->left;

            }

     }

     if(found==0)

          cout<<"\nElement Not Found.";

     else

     {

                cout<<"\n\t FOUND NODE: ";

                cout<<"\n Key: "<<p->order;

                cout<<"\n Colour: "; if(p->color=='b')

     cout<<"Black";

    else

     cout<<"Red"; if(p->parent!=NULL)

                       cout<<"\n Parent: "<<p->parent->order;

                else

                       cout<<"\n There is no parent of the node. "; if(p->right!=NULL)

                       cout<<"\n Right Child: "<<p->right->order;

                else

                       cout<<"\n There is no right child of the node. "; if(p->left!=NULL)

                       cout<<"\n Left Child: "<<p->left->order;

                else

                       cout<<"\n There is no left child of the node.  ";

                cout<<endl;



     }

}

template<class T,class O>
void RBtree<T,O>::arbolToLista()

{

     toLista(root);

}

template<class T,class O>
void RBtree<T,O>::toLista(node<T,O> *p)

{
	
	if(root==NULL)

     {

          

          return ;

     }

     if(p!=NULL)

     {
                
                
        lista.insertar_nodo(lista.getTam()+1,p->key);

     

     if(p->parent!=NULL){
     	
        lista.insertar_nodo(lista.getTam()+1,p->key);     	
	 }

                       

                else

                       if(p->right!=NULL)
                       
                       lista.insertar_nodo(lista.getTam()+1,p->key);

                else

                       if(p->left!=NULL)
                       
                       lista.insertar_nodo(lista.getTam()+1,p->key);

                else

                       cout<<"";

                if(p->left)
    			{
                 toLista(p->left);
    			}

			    if(p->right)
			    {
			     toLista(p->right);
			    }

    /*else

     cout<<"\nNo Right Child.\n"*/

     }
	

     



     

}



#endif



