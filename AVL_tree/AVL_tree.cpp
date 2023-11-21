//@author Maltseva K.V.

#include <iostream>
#include "AVLTreeNode.h"
#include"TreeNode.h"
#include"AVLTree.h"
#include"TestAVLTree.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    
   AVLTree<int>* avlTree=new AVLTree<int>(25);
   // AVLTreeNode<int>* a = new AVLTreeNode<int>(5,nullptr,nullptr);
   //
   // Вставка элементов в AVL-дерево
    avlTree->Insert(20);
   avlTree->Insert(30);

   avlTree->Insert(40);
   avlTree->Insert(56);
   avlTree->Insert(32);
   avlTree->PrintTreeAVL();
   avlTree->Insert(54);
   avlTree->Remove(40);

   avlTree->PrintTreeAVL();
  //    //     4
  //   //    / \
  //    //  2     5
  //    // / \
  //    //1   3

  //AVLTree<int>* avlTree1 = new AVLTree<int>(4);
  //avlTree1->Insert(2);
  //avlTree1->Insert(5);

  //avlTree1->Insert(1);
  //avlTree1->Insert(3);

  //avlTree1->Remove(3);
  //avlTree1->Remove(5);
  //avlTree1->PrintTreeAVL();
   avlTree->Remove(30);
   // a->left = new AVLTreeNode<int>(10,nullptr,nullptr);
   // //avlTree->Insert(3);
   // //avlTree->Insert(7);
   //// avlTree->RemoveNode(7);
   // 
   // avlTree->RotateRight(a);
   avlTree->PrintTreeAVL();
   cout <<"Искомый элемент находится на уровне: " <<avlTree->Find(25)<<endl;
   cout << endl;
   cout <<"Высота дерева = " <<avlTree->Height() << endl;
   cout << "Количество узлов в дереве = "<<avlTree->CountNode()<< endl;

   cout << "LNR обход: " << endl;
   int* arr = new int[avlTree->CountNode()];
   avlTree->AddNodesToArray(arr);
   for (int i = 0; i < avlTree->CountNode(); i++) {
       cout << arr[i] << "  ";
   }
   cout << endl;

   TestGetHeight();
   TestGetBalanceFactor();
   TestRotateLeft();
   TestRotateRight();
   TestAddNodeAVL();
   TestBalanceTree();
   TestRemove();
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
