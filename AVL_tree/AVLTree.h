#pragma once

//@author Maltseva K.V.

#include"TreeNode.h"
#include"AVLTreeNode.h"
template <class T>
class AVLTree
{
private:
    //��������� �� ������
    AVLTreeNode<T>* root;


public:
    //�����������
    AVLTree(const T& item) : root(new AVLTreeNode<T>(item, nullptr, nullptr)) {}
    AVLTree() : root(nullptr)
    {
    }


    // ������� ������ ����
    void Insert(const T& item)
    {
        root = root->AddNodeAVL(item);

    }
    //�������� ����
    void Remove(const T& item) {
        root = root->Remove(item);
    }

    //������ ������
    void PrintTreeAVL() {
        PrintTree(root, 0);
    }
    //����� �� ��������
    int Find(const T& item) {
        return Search(root, item, 0);
    }
    //������� ������� (�������) ������
    int Height() {
        return Depth(root);
    }
    //������� ����� ������
    int CountNode() {
        return CountNodes(root);
    }
    //�������� ������
    void DeleteAVLTree() {
        DeleteTree(root);
    }

    //������ ������ � ������ � ������� LNR
    void AddNodesToArray(T arr[]) {
        PrintArr(root, arr);
    }
};
