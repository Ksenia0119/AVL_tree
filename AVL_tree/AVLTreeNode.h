#pragma once
//@author Maltseva K.V.

#include"TreeNode.h"


//���� AVL-������   
template <class T>
class AVLTreeNode :public TreeNode<T> {
private:
    //������ �������( ������� ����� ������ � ������� �����������)
    int balanceFactor;
  
public:
    //����������� ������
   /* AVLTreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr)
        : TreeNode<T>(item, lptr, rptr), balanceFactor(0)
    {
    }*/

    AVLTreeNode(const T& value, TreeNode<T>* leftChild = nullptr, TreeNode<T>* rightChild = nullptr)
        : TreeNode<T>(value, leftChild, rightChild), balanceFactor(0)
    {
    }
    //����� ���������
    AVLTreeNode<T>* Left() const { return dynamic_cast<AVLTreeNode<T>*>(this->left); }
    //������ ���������
    AVLTreeNode<T>* Right() const { return dynamic_cast<AVLTreeNode<T>*>(this->right); }
   //��������� ������� �������
    int GetBalanceFactor() const { return balanceFactor; }
    //��������� ������� �������
    void SetBalanceFactor(int factor) { balanceFactor = factor; }
    //������,����������� ���������� ��������� �� ������ � ����� ����������
    void SetRight(AVLTreeNode<T>* rightNode)
    {
        this->right = rightNode;
    }
    void SetLeft(AVLTreeNode<T>* leftNode)
    {
        this->left = leftNode;
    }
 
   
};

//AVL ������
template <class T>
class AVLTree
{
private:
    //��������� �� ������
    AVLTreeNode<T>* root;
    
    
public:
   //�����������
    AVLTree(const T& item): root(new AVLTreeNode<T>(item,nullptr,nullptr)){}
    AVLTree() : root(nullptr)
    {
    }
    //������ � ��������� �� ������
    AVLTreeNode<T>* GetRoot() const { return root; }
   
    //����� ������� ������ ����
    void Insert(const T& item)
    {  //������� ����
       root = AddNodeAVL(root, item);
       //���������������� ������
       BalanceTree(root);

    }
    //������ ������
    void PrintTreeAVL() {
        PrintTree(root, 0);
    }

    //��������� ������ ������
    int GetHeight(AVLTreeNode<T>* node) {
        //���� ������ ����, ������ =-1
        if (node == nullptr) {
            return -1;
        }
        //���������� �������� ������� ��� �����������
        int leftHeight = GetHeight(node->Left());
        int rightHeight = GetHeight(node->Right());

        //������+ ����.���������
        return 1 + std::max(leftHeight, rightHeight);
    }
    //���������� ������ �������
    int GetBalanceFactor(AVLTreeNode<T>* node) {
        //���� ������ ����,������� 0
        if (node == nullptr) {
            return 0;
        }
        //������ ������= ������ ������� ��������� - ������ ������
        return GetHeight(node->Right()) - GetHeight(node->Left());
    }

    //����� �������
    void RotateLeft(AVLTreeNode<T>*& node) {
        //���������, ��� node � ��� ������ ��������� �� �����, ����� ������� ��� ��������.
        //���� ��� �� ���, �� ������ ������������ �� �������.
        if (node == nullptr || node->right == nullptr)
        {
            return;
        }
        //������� ����� ��������� newRoot � ����������� ��� ������ ��������� ���� node.
        AVLTreeNode<T>* newRoot = node->Right();
       // �������� ���������, ����� ������ ��������� newRoot ����� ����� ���������� ���� node,
       //  � node ���� ����� �������� ����� newRoot
        node->SetRight(newRoot->Left());
        newRoot->SetLeft(node);
        //��������� ��������� node �� ����� ������ newRoot
        node = newRoot;
        
    }

 //������ �������
    void RotateRight(AVLTreeNode<T>*& node) {
        //���������, ��� node � ��� ����� ��������� �� �����, ����� ������� ��� ��������.
       //���� ��� �� ���, �� ������ ������������ �� �������.
        if (node == nullptr || node->Left() == nullptr)
        {
            return ;
        }
       // ������� ����� ��������� newRoot � ����������� ��� ����� ��������� ���� node
        AVLTreeNode<T>* newRoot = node->Left();
        //�������� ���������, ����� ����� ��������� newRoot ����� ������ ���������� ���� node,
         // � node ���� ������ �������� ����� newRoot
        node->SetLeft(newRoot->Right());
        newRoot->SetRight(node);
        //��������� ��������� node �� ����� ������ newRoot
        node = newRoot;
       
    }

    //���������������� ������
    void BalanceTree(AVLTreeNode<T>*& node) {
        if (node == nullptr) {
            return;
        }

        int balanceFactor = GetBalanceFactor(node);

        // ���� ������ ����� ����� ������
        if (balanceFactor > 1) {
            // ���� ����� ��������� ����� ������ ������, ������� ������ ����� ������� ��� ������ ���������
            if (GetBalanceFactor(node->Left()) < 0) {
                RotateLeft(node->Left());
            }
            // ����� ������ ������ ������� ��� �������� ����
            RotateRight(node);
        }
        // ���� ������ ����� ������ ������
        else if (balanceFactor < -1) {
            // ���� ������ ��������� ����� ����� ������, ������� ������ ������ ������� ��� ������� ���������
            if (GetBalanceFactor(node->Right()) > 0) {
                RotateRight(node->Right());
            }
            // ����� ������ ����� ������� ��� �������� ����
            RotateLeft(node);
        }
    }
   
};
//���������� ����� ����� � ������ AVL
template <class T>
AVLTreeNode<T>* AddNodeAVL(AVLTreeNode<T>* node, const T& item)

{
    //���� ����� �� ����������

    if (node == nullptr)

    { //�������� �� � ������� � ��� ������

        return new AVLTreeNode<int>(item, nullptr, nullptr);

    }


    if (item < node->data) {
        // ���������� ��������� �������� � ����� ���������
        node->left = AddNode(node->left, item);
    }
    else if (item > node->data) {
        // ���������� ��������� �������� � ������ ���������
        node->right = AddNode(node->right, item);
    }

    // ���� �������� ��� ������������ � ������, ������ �� ������

    return node;
}

