
// C++ program to implement Custom Linked List and
// iterator pattern.
#include <bits/stdc++.h>

using namespace std;
 
// Custom class to handle Linked List operations
// Operations like push_back, push_front, pop_back,
// pop_front, erase, size can be added here

template <typename T>

class LinkedList
{

    // Forward declaration

  public:  class Node;
 

public:

    LinkedList<T>() noexcept

    {

        // caution: static members can't be

        // initialized by initializer list

        m_spRoot = nullptr;

    }
 

    // Forward declaration must be done

    // in the same access scope

    class Iterator;
 

    // Root of LinkedList wrapped in Iterator type

    Iterator begin()

    {

        return Iterator(m_spRoot);

    }
 

    // End of LInkedList wrapped in Iterator type

    Iterator end()

    {

        return Iterator(nullptr);

    }
 

    // Adds data to the end of list

    

    void push_back(T data);

    void push_front(T data);

    void emplace(T data, int place);

    void splice(LinkedList l1, LinkedList l2);

    void merges(LinkedList l1, LinkedList l2);

    void clear();
 
    bool empty();

    int size();
   
    void Traverse();
 

    // Iterator class can be used to

    // sequentially access nodes of linked list

    class Iterator

    {

    public:

    Iterator() noexcept :

        m_pCurrentNode (m_spRoot) { }
 

    Iterator(const Node* pNode) noexcept :

        m_pCurrentNode (pNode) { }
 

        Iterator& operator=(Node* pNode)

        {

            this->m_pCurrentNode = pNode;

            return *this;

        }
 

        // Prefix ++ overload

        Iterator& operator++()

        {

            if (m_pCurrentNode)

                m_pCurrentNode = m_pCurrentNode->pNext;

            return *this;

        }
 

        // Postfix ++ overload

        Iterator operator++(int)

        {

            Iterator iterator = *this;

            ++*this;

            return iterator;

        }
 

        bool operator!=(const Iterator& iterator)

        {

            return m_pCurrentNode != iterator.m_pCurrentNode;

        }
 

        int operator*()

        {

            return m_pCurrentNode->data;

        }
 

    public:

        const Node* m_pCurrentNode;

    };
 

public:
 

    class Node

    {

        T data;

        Node* pNext;
 

        // LinkedList class methods need

        // to access Node information

        friend class LinkedList;

    };
 

    // Create a new Node

    Node* GetNode(T data)

    {

        Node* pNewNode = new Node;

        pNewNode->data = data;

        pNewNode->pNext = nullptr;
 

        return pNewNode;

    }
 

    // Return by reference so that it can be used in

    // left hand side of the assignment expression

    Node*& front()

    {

        return m_spRoot;

    }

    Node*& back(){
       Node* pCrawler = front();

        while (pCrawler->pNext)

        {

            pCrawler = pCrawler->pNext;

        }

        return pCrawler;

    }
    

    static Node* m_spRoot;
};
 

template <typename T>

/*static*/ typename LinkedList<T>::Node* LinkedList<T>::m_spRoot = nullptr;

template <typename T>

bool LinkedList<T>:: empty(){
    if(!front()) return false;
    else return true;
}

template <typename T>

int LinkedList<T>:: size(){
    int k=0;
    Node* pCrawler = front();

        while (pCrawler->pNext)

        {
            pCrawler = pCrawler->pNext;
            k++;

        }
        return k;
}

template <typename T>

void LinkedList<T>::push_back(T data)
{

    Node* pTemp = GetNode(data);

    if (!front())

    {

        front() = pTemp;

    }

    else

    {

        Node* pCrawler = front();

        while (pCrawler->pNext)

        {

            pCrawler = pCrawler->pNext;

        }
 

        pCrawler->pNext = pTemp;

    }
}
 
template <typename T>

void LinkedList<T>::push_front(T data){

    Node* pTemp = GetNode(data);

    if (!front())

    {

        front() = pTemp;

    }

    else
    {

            pTemp->pNext = front();
            
            front()=pTemp;

    }

}

template <typename T>

void LinkedList<T>:: emplace(T data, int place){

    Node* pTemp = GetNode(data);

    if (!front())

    {

        front() = pTemp;

    } else if(place> size()){
        push_back(data);
    } else {
        Node* pCrawler = front();
        for(int i=0;i<place-2;i++){
             pCrawler = pCrawler->pNext;
        }
        pTemp->pNext=pCrawler->pNext->pNext;
         pCrawler->pNext = pTemp;
    }
}

template <typename T>

void LinkedList<T>:: clear(){
   Node* pCrawler = front();

        while (pCrawler->pNext)

        {
            pCrawler->data=NULL;
            pCrawler = pCrawler->pNext;

        }
        pCrawler->data=NULL;

}

template <typename T>

void LinkedList<T>::Traverse()
{

    Node* pCrawler = front();
 

    while (pCrawler)

    {

        cout << pCrawler->data << " ";

        pCrawler = pCrawler->pNext;

    }
 

    cout << endl;
}
 
 template <typename T>

void LinkedList<T>:: splice(LinkedList l1, LinkedList l2){
   l2.front()=l1.front();
}

template <typename T>

void LinkedList<T>:: merges(LinkedList l1, LinkedList l2){
   Node* pCrawler=l1.front();
     while (pCrawler->pNext)

        {

            pCrawler = pCrawler->pNext;

        }
 

        pCrawler->pNext = l2.front();
    l2.clear();
}
//Driver program

int main()
{

    LinkedList<int> list;
    LinkedList<int> list1;
 

    // Add few items to the end of LinkedList

    list.push_back(4);

    list.push_back(1);

    list.push_back(2);

    list.push_back(5);

    list.push_back(7);

    list.push_back(9);

    list.push_front(77);
    list.emplace(44, 3);

    list.splice(list,list1);

    cout<<"\n"<< list.empty()<<"\n" <<list.size()<<"\n";
    
    
 

    cout << "Traversing LinkedList through method" << endl;
    list.Traverse();
    cout << "Traversing LinkedList through Iterator" << endl;

    for ( LinkedList<int>::Iterator iterator = list.begin();

            iterator != list.end(); iterator++)

    {

        cout << *iterator << " ";

    }
 

    cout << endl;

    list.clear();
    cout << "Traversing LinkedList through method" << endl;

    list.Traverse();
 

    return 0;
}