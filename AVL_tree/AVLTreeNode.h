#pragma once
//@author Maltseva K.V.

#include"TreeNode.h"


//узел AVL-дерева   
template <class T>
class AVLTreeNode :public TreeNode<T> {
private:
    //Фактор баланса( разница высот левого и правого поддеревьев)
    int balanceFactor;
  
public:
    //конструктор класса
   /* AVLTreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr)
        : TreeNode<T>(item, lptr, rptr), balanceFactor(0)
    {
    }*/

    AVLTreeNode(const T& value, TreeNode<T>* leftChild = nullptr, TreeNode<T>* rightChild = nullptr)
        : TreeNode<T>(value, leftChild, rightChild), balanceFactor(0)
    {
    }
    //левое поддерево
    AVLTreeNode<T>* Left() const { return dynamic_cast<AVLTreeNode<T>*>(this->left); }
    //правое поддерево
    AVLTreeNode<T>* Right() const { return dynamic_cast<AVLTreeNode<T>*>(this->right); }
   //получение фактора баланса
    int GetBalanceFactor() const { return balanceFactor; }
    //установка фактора баланса
    void SetBalanceFactor(int factor) { balanceFactor = factor; }
    //методы,позволяющие установить указатели на правое и левое поддеревья
    void SetRight(AVLTreeNode<T>* rightNode)
    {
        this->right = rightNode;
    }
    void SetLeft(AVLTreeNode<T>* leftNode)
    {
        this->left = leftNode;
    }
 
   


   
    //получение высоты дерева
    int GetHeight(AVLTreeNode<T>* node) {
        //если корень пуст, высота =-1
        if (node == nullptr) {
            return -1;
        }
        //рекурсивно вызываем функцию для поддеревьев
        int leftHeight = GetHeight(node->Left());
        int rightHeight = GetHeight(node->Right());

        //корень+ макс.поддерево
        return 1 + max(leftHeight, rightHeight);
    }
    //вычисление баланс фактора
    int GetBalanceFactor(AVLTreeNode<T>* node) {
        //если корень пуст,вернуть 0
        if (node == nullptr) {
            return 0;
        }
        //баланс фактор= высота правого поддерева - высота левого
        return GetHeight(node->Right()) - GetHeight(node->Left());
    }

    //   //левый поворот
    //   void RotateLeft(AVLTreeNode<T>*& node) {
    //       //Проверяем, что node и его правое поддерево не пусты, чтобы поворот был возможен.
    //       //Если это не так, мы просто возвращаемся из функции.
    //       if (node == nullptr || node->right == nullptr)
    //       {
    //           return;
    //       }
    //       //Создаем новый указатель newRoot и присваиваем ему правое поддерево узла node.
    //       AVLTreeNode<T>* newRoot = node->Right();
    //      // изменяем указатели, чтобы правое поддерево newRoot стало левым поддеревом узла node,
    //      //  а node стал левым дочерним узлом newRoot
    //       node->SetRight(newRoot->Left());
    //       newRoot->SetLeft(node);
    //       //обновляем указатель node на новый корень newRoot
    //       node = newRoot;
    //       
    //   }

    ////правый поворот
    //   void RotateRight(AVLTreeNode<T>*& node) {
    //       //Проверяем, что node и его левое поддерево не пусты, чтобы поворот был возможен.
    //      //Если это не так, мы просто возвращаемся из функции.
    //       if (node == nullptr || node->Left() == nullptr)
    //       {
    //           return ;
    //       }
    //      // Создаем новый указатель newRoot и присваиваем ему левое поддерево узла node
    //       AVLTreeNode<T>* newRoot = node->Left();
    //       //изменяем указатели, чтобы левое поддерево newRoot стало правым поддеревом узла node,
    //        // а node стал правым дочерним узлом newRoot
    //       node->SetLeft(newRoot->Right());
    //       newRoot->SetRight(node);
    //       //обновляем указатель node на новый корень newRoot
    //       node = newRoot;
    //      
    //   }


       //левый поворот
    AVLTreeNode<T>* RotateLeft(AVLTreeNode<T>* node) {
        //Проверяем, что node и его правое поддерево не пусты, чтобы поворот был возможен.
        //Если это не так, мы просто возвращаемся из функции.
        if (node == nullptr || node->right == nullptr)
        {
            return nullptr;
        }
        //Создаем новый указатель newRoot и присваиваем ему правое поддерево узла node.
        AVLTreeNode<T>* newRoot = node->Right();
        // изменяем указатели, чтобы правое поддерево newRoot стало левым поддеревом узла node,
        //  а node стал левым дочерним узлом newRoot
        node->SetRight(newRoot->Left());
        newRoot->SetLeft(node);
        //обновляем указатель node на новый корень newRoot
        node = newRoot;
        return node;
    }

    //правый поворот
    AVLTreeNode<T>* RotateRight(AVLTreeNode<T>* node) {
        //Проверяем, что node и его левое поддерево не пусты, чтобы поворот был возможен.
       //Если это не так, мы просто возвращаемся из функции.
        if (node == nullptr || node->Left() == nullptr)
        {
            return nullptr;
        }
        // Создаем новый указатель newRoot и присваиваем ему левое поддерево узла node
        AVLTreeNode<T>* newRoot = node->Left();
        //изменяем указатели, чтобы левое поддерево newRoot стало правым поддеревом узла node,
         // а node стал правым дочерним узлом newRoot
        node->SetLeft(newRoot->Right());
        newRoot->SetRight(node);
        //обновляем указатель node на новый корень newRoot
        node = newRoot;
        return node;
    }
    AVLTreeNode<T>* AddNodeAVL( const T& item)
        
    {
        AVLTreeNode<T>* node = this;
        if (node == nullptr)
        {
            return new AVLTreeNode<T>(item);
        }

        if (item < node->data)
        {
            node->SetLeft(dynamic_cast<AVLTreeNode<T>*>(node->Left()->AddNodeAVL(item)));
        }
        else if (item > node->data)
        {
            node->SetRight (dynamic_cast<AVLTreeNode<T>*>(node->Right()->AddNodeAVL(item)));
        }

        return BalanceTree(node);
    }
   
    //перебалансировка дерева
    AVLTreeNode<T>* BalanceTree(AVLTreeNode<T>* node) {
        if (node == nullptr) {
            return nullptr;
        }

        int balanceFactor = GetBalanceFactor(node);

        // Если дерево имеет левый наклон
        if (balanceFactor ==-2) {
            // Если левое поддерево имеет правый наклон, сначала делаем левый поворот для левого поддерева
            if (GetBalanceFactor(node->Left()) > 0) {
                node->SetLeft(RotateLeft(node->Left()));
            }
            // Затем делаем правый поворот для текущего узла
            return RotateRight(node);
        }
        // Если дерево имеет правый наклон
        else if (balanceFactor ==2) {
            // Если правое поддерево имеет левый наклон, сначала делаем правый поворот для правого поддерева
            if (GetBalanceFactor(node->Right()) <  0) {
                node->SetRight(RotateRight(node->Right()));
            }
            // Затем делаем левый поворот для текущего узла
            return RotateLeft(node);
        }
        return node;
    }

    //удаление узла бинарного дерева
    template<class T>
    AVLTreeNode<T>* Remove( const T& data) {
        AVLTreeNode<T>* root  = this;
        //указател, parent, который будет храненить родителя удаляемого узла
        AVLTreeNode<T>* parent;

        if (root == nullptr) {
            // Дерево пустое или достигнут конец ветки (лист без значения)
            return nullptr;
        }

        if (data < root->data) {
            // Рекурсивно удаляем значение из левого поддерева
            root->SetLeft(dynamic_cast<AVLTreeNode<T>*> (root->Left()->Remove(data)));
        }
        else if (data > root->data) {
            // Рекурсивно удаляем значение из правого поддерева
          //  root->right = Remove(root->right, data);
            root->SetRight(dynamic_cast<AVLTreeNode<T>*> (root->Right()->Remove(data)));
        }
        else {
            // Найден узел, который нужно удалить

            if (root->Left() == nullptr && root->Right() == nullptr) {
                // Узел является листом (не имеет потомков)
                delete root;
                root = nullptr;
            }
            else if (root->Left() == nullptr) {
                // Узел имеет только правого потомка

                parent = root;
                root = root->Right();
                delete parent;
            }
            else if (root->Right() == nullptr) {
                // Узел имеет только левого потомка

                parent = root;
                root = root->Left();
                delete parent;
            }
            else {
                //// Узел имеет оба потомка

                //AVLTreeNode<T>* parent = dynamic_cast<AVLTreeNode<T>*>(SuccMin(root->right));
                //root->data = parent->data;
                //root->right = Remove(root->right, parent->data);

               // Узел имеет оба потомка
                AVLTreeNode<T>* successor = dynamic_cast<AVLTreeNode<T>*>(SuccMin(root->Right()));
                root->data = successor->data;

                if (successor == root->Right()) {
                    root->SetRight(successor->Right());
                }
                else {
                    AVLTreeNode<T>* successorParent = root->Right();
                    while (successorParent->Left() != successor) {
                        successorParent = successorParent->Left();
                    }
                    successorParent->SetLeft(successor->Right());
                }

                delete successor;
                /*AVLTreeNode<T>* successor = dynamic_cast<AVLTreeNode<T>*>(SuccMin(root->Right()));
                root->data=successor->data;

                if (successor == root->Right()) {
                    root->SetRight(successor->Right());
                }
                else {
                    AVLTreeNode<T>* successorParent = parent(successor);
                    successorParent->SetLeft(successor->Right());
                }

                delete successor;*/
            }
        }

        return BalanceTree(root);
    }
    ////перебалансировка дерева
    //void BalanceTree(AVLTreeNode<T>* node) {
    //    if (node == nullptr) {
    //        return;
    //    }

    //    int balanceFactor = GetBalanceFactor(node);

    //    // Если дерево имеет левый наклон
    //    if (balanceFactor > 1) {
    //        // Если левое поддерево имеет правый наклон, сначала делаем левый поворот для левого поддерева
    //        if (GetBalanceFactor(node->Left()) < 0) {
    //            RotateLeft(node->Left());
    //        }
    //        // Затем делаем правый поворот для текущего узла
    //        RotateRight(node);
    //    }
    //    // Если дерево имеет правый наклон
    //    else if (balanceFactor < -1) {
    //        // Если правое поддерево имеет левый наклон, сначала делаем правый поворот для правого поддерева
    //        if (GetBalanceFactor(node->Right()) > 0) {
    //            RotateRight(node->Right());
    //        }
    //        // Затем делаем левый поворот для текущего узла
    //        RotateLeft(node);
    //    }
    //}

    // //перебалансировка дерева
    //void BalanceTree() {
    //    if (root == nullptr) {
    //        return;
    //    }

    //    int balanceFactor = GetBalanceFactor(root);

    //    // Если дерево имеет левый наклон
    //    if (balanceFactor > 1) {
    //        // Если левое поддерево имеет правый наклон, сначала делаем левый поворот для левого поддерева
    //        if (GetBalanceFactor(root->Left()) < 0) {
    //            RotateLeft(root->Left());
    //        }
    //        // Затем делаем правый поворот для текущего узла
    //        RotateRight(root);
    //    }
    //    // Если дерево имеет правый наклон
    //    else if (balanceFactor < -1) {
    //        // Если правое поддерево имеет левый наклон, сначала делаем правый поворот для правого поддерева
    //        if (GetBalanceFactor(root->Right()) > 0) {
    //            RotateRight(root->Right());
    //        }
    //        // Затем делаем левый поворот для текущего узла
    //        RotateLeft(root);
    //    }
    //}
  
};
//// Прототип функции
//template <class T>
//AVLTreeNode<T>* AddNodeAVL(AVLTreeNode<T>* node, const T& item);
//AVL дерево
template <class T>
class AVLTree
{
private:
    //указатель на корень
    AVLTreeNode<T>* root;
    
    
public:
   //конструктор
    AVLTree(const T& item): root(new AVLTreeNode<T>(item,nullptr,nullptr)){}
    AVLTree() : root(nullptr)
    {
    }
    //доступ к указателю на корень
    AVLTreeNode<T>* GetRoot() const { return root; }
   
    //метод вставки нового узла
    void Insert(const T& item)
    {  //вставка узла
       root = root-> AddNodeAVL( item);
       //перебалансировка дерева
     // root = BalanceTree(root);

    }

    void Remove(const T& item) {
        root = root->Remove(item);
    }
  
    //печать дерева
    void PrintTreeAVL() {
        PrintTree(root, 0);
    }
   
};

//// Определение функции AddNodeAVL
//template <class T>
//AVLTreeNode<T>* AddNodeAVL(AVLTreeNode<T>* node, const T& item)
//
//{
//    //Если ветки не существует
//
//    if (node == nullptr)
//
//    { //создадим ее и зададим в нее данные
//
//        return new AVLTreeNode<int>(item, nullptr, nullptr);
//
//    }
//
//
//    if (item < node->data) {
//        // Рекурсивно вставляем значение в левое поддерево
//        node->left = AddNode(node->left, item);
//    }
//    else if (item > node->data) {
//        // Рекурсивно вставляем значение в правое поддерево
//        node->right = AddNode(node->right, item);
//    }
//
//    // Если значение уже присутствует в дереве, ничего не делаем
//
//    //return node;
//    return BalanceTree(node);
//}