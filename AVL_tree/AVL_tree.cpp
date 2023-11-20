//@author Maltseva K.V.

#include <iostream>
#include "AVLTreeNode.h"
#include"TreeNode.h"

using namespace std;

int main()
{
   AVLTree<int>* avlTree=new AVLTree<int>(25);
   // AVLTreeNode<int>* a = new AVLTreeNode<int>(5,nullptr,nullptr);
   //
   // Вставка элементов в AVL-дерево
    avlTree->Insert(20);
   avlTree->Insert(30);

   avlTree->Insert(40);
   avlTree->Insert(56);
   avlTree->Insert(32);

   avlTree->Insert(54);
  avlTree->Remove(40);
  //avlTree->Remove(30);
   // a->left = new AVLTreeNode<int>(10,nullptr,nullptr);
   // //avlTree->Insert(3);
   // //avlTree->Insert(7);
   //// avlTree->RemoveNode(7);
   // 
   // avlTree->RotateRight(a);
   avlTree->PrintTreeAVL();

    //AVLTreeNode<int>* root1 = new AVLTreeNode<int>(15);
    //root1->left = new AVLTreeNode<int>(4);
    //root1->left->left = new AVLTreeNode<int>(4);
    //root1->left->left->left = new AVLTreeNode<int>(4);
    //root1->right = new AVLTreeNode<int>(5);

    //PrintTree(root1, 0);
    //cout<< endl;
    //cout << endl;
    //cout << endl;
    //cout << endl;

  //  AVLTree<int>* root = new AVLTree<int>();
  //  //root->RotateRight(root1);
  //  //PrintTree(root1, 0);


  //  AVLTreeNode<int>* root2 = new AVLTreeNode<int>(15);
  //  root2->right = new AVLTreeNode<int>(20);
  //  root2->right->right = new AVLTreeNode<int>(25);
  //  PrintTree(root2, 0);

  ////  cout << root->GetHeight(root2);
  //  cout << endl; cout << endl; cout << endl; cout << endl;
  //  //root->RotateLeft(root2);
  //  PrintTree(root2, 0);

    //AVLTree<int>* ROOT = new AVLTree<int>();
    //AVLTreeNode<int>* root3 = new AVLTreeNode<int>(15);
    //root3->left = new AVLTreeNode<int>(4);
    //root3->left->left = new AVLTreeNode<int>(2);
    //root3->left->right = new AVLTreeNode<int>(8);
    //root3->right = new AVLTreeNode<int>(20);
    //root3->right->left = new AVLTreeNode<int>(17);
    //root3->right->right = new AVLTreeNode<int>(25);
    //PrintTree(root3, 0);
    //cout<<ROOT->GetBalanceFactor(root3);
   /// AVLTreeNode<int>* root1 = new AVLTreeNode<int>(15,nullptr,nullptr);
   //// PrintTree(root1, 0);
}
