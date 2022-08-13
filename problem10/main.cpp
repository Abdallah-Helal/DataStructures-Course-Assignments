#include <iostream>
using namespace std;

template <class type>
struct node
{
    type data ;
    node<type> *next ;
    node<type> *prev ;
};
template <class T>
class list
{
private:
    node<T>*head ;
    node<T>*tail ;
    int cnt ;
public :
    class iterator
    {
        //friend class Li;
    private:
        node<T> *nodePtr;
    public:
        iterator(node<T> *newPtr) : nodePtr(newPtr) {}
        ~iterator() {}
        bool operator!=(const iterator& itr) const
        {
            return nodePtr != itr.nodePtr;
        }
        bool operator==(const iterator& itr) const
        {
            return nodePtr == itr.nodePtr;
        }
        T& operator*() const
        {
            return nodePtr->data;
        }
        node<T>* getNodePtr()
        {
            return nodePtr;
        }

        iterator operator++(int)
        {
            iterator temp = *this;
            if (nodePtr->next != NULL)
                nodePtr = nodePtr->next;
            else
                throw("currently pointing after the last element of the list.");
            return temp;
        }
        iterator operator++()
        {
            if (nodePtr->next != NULL)
                nodePtr = nodePtr->next;
            else
                throw("currently pointing after the last element of the list.");
            return *this;
        }
        iterator operator--(int)
        {
            iterator temp = *this;
            if (nodePtr->prev == NULL)
                throw("currently pointing to the first element of the list.");
            else
                nodePtr = nodePtr->prev;
            return temp;
        }
        iterator operator--()
        {
            if (nodePtr->prev == NULL)
                throw("currently pointing to the first element of the list.");
            else
                nodePtr = nodePtr->prev;
            return *this;
        }
    }; // End of inner class iterator

    list() ;
    list(T value , int sz);
    ~list();
    void push_front(T value)  ;
    void push_back(T value)  ;
    void insert(T value, iterator position );
    void insert(T value, int loc) ;
    void pop_front() ;
    void pop_back() ;
    node <T> * erase(iterator position);
    void erase(int loc);
    void print() ;
    int size() {return cnt ;}
    list<T>& operator= ( list<T> &otehrlist);
    iterator begin()
    {
        iterator x(head) ;
        return x ;
    }
    iterator end()
    {
        iterator x(tail) ;
        return x ;
}
};
//constructors & destructor
template<class T>
list<T>::list()
{
    head=tail=new node<T> ; // it will be a dummy node after the actual tail and pointer tail will point to it
    cnt=0;
}
template<class T>
list<T>::list(T value , int sz):cnt(sz)
{
    node<T> *cur=new node<T> ;
    head=cur ;
    cur->data=value ;
    for (int i=0 ; i<sz-1 ; i++)
    {
        node<T> *N=new node<T> ;
        cur->next=N ;
        N->prev=cur ;
        N->data = value ;
        cur =N;
    }
    tail=new node<T> ;
    tail->prev = cur ;
    cur->next =tail ;

}
template<class T>
list<T>::~list()
{
    node<T>* cur=head ;
    while (cur!=NULL)
    {
        head=cur ;
        cur=cur->next ;
        delete head ;
    }
}

//insert functions
template<class T>
void list<T>::push_front (T value)
{
    node<T>*N =new node<T> ;
    N->data=value ;
    N->prev =NULL ;
    N->next=head ;
    head->prev = N ;
    head = N ;
    cnt++;
}
template<class T>
void list<T>::push_back (T value)
{
    node<T> *N = new node<T>  ;
    N->data =value;
    N->next =tail;
    N->prev =tail->prev;
    (head==tail) /*an empty list*/ ? head=N : (tail->prev)->next = N ;
    tail->prev = N;
    cnt++;
}

template <class T>
void list<T>::insert(T value, iterator position )
{
    node <T>*N = new node<T> ;
    node <T> *C = position.getNodePtr() ;
    N->data=value ;
    N->next = C ;
    N->prev = C->prev ;
    ((C->prev) == NULL) ? head=N : (C->prev)->next = N ;
    C->prev = N ;
    cnt++;

}

template<class T>
void list<T>::insert (T value, int loc)
{
    if (loc > cnt || loc < 0)
        cout << "can't add at position " << loc << endl ;
    else
    {
        iterator it = begin() ;
        while (loc--)
            it++;
        insert(value,it);
    }
}

//deletion function
template <class T>
void list<T>::pop_front()
{
    if (cnt>0)
    {
        node<T>*N=head ;
        head=head->next ;
        delete N ;
        cnt--;
    }
    else
        cout << "Can't delete from empty list \n";
}
template <class T>
void list<T>::pop_back()
{
    if (cnt>0)
    {
        node<T>*N=tail->prev ;
        (N->prev)->next=tail ;
        tail->prev= N->prev ;
        delete N ;
        cnt--;
    }
    else
        cout << "Can't delete from empty list \n";
}

template <class T>
node <T> * list<T>::erase(iterator position)
{
    node <T> *N = position.getNodePtr() ;
    node <T> *next_point = N->next ;
    ( N == head) ? head = next_point :(N->prev)->next = next_point ;
    next_point->prev = N->prev ;
    delete N ;
    return next_point ;
}

template <class T>
void list<T>::erase(int loc)
{
    if (cnt==0)
        cout << "Can't delete from empty list \n";
    else if (loc <0 || loc>=cnt)
        cout << "Invalid location \n";
    else
    {
        iterator it = begin() ;
        while (loc--)
            it++;
        erase(it);
    }
}

template<class T>
void list<T>::print()
{
    if (cnt==0)
        cout << "Empty List!" ;
    else
    {
        node<T>*cur = head ;
        while (cur!=tail )
        {
            cout << cur->data << " " ;
            cur=cur->next ;
        }
        cout << endl;
    }
}
template<class T>
list<T>& list<T>::operator= ( list<T> &otehrlist)
 {
    list<T>::iterator it = otehrlist.begin();
    int n = otehrlist.size() ;
    while(n--)
        push_back(*(it++));
    return *this ;
 }


int main()
{
    list<int> mylist ;

    mylist.push_back(2);
    mylist.insert(1,0);
    mylist.push_back(3);
    mylist.push_front(0);
    mylist.print() ;

    list<int> ::iterator it = mylist.begin() ;
    it++;
    mylist.insert(20,it);
    mylist.erase(it);
    while (it!=mylist.end())
    {

        cout << *it << " " ;
        it++ ;
    }
    cout << endl;
    list<int> otherlist;
    otherlist= mylist ;
    cout << "the copied list : " ;
    otherlist.print() ;
    mylist.push_back(5);
    otherlist.push_back(7);
    cout << "the original list : " ;
    mylist.print();
    cout << "the copied list : " ;
    otherlist.print();

    return 0;
}
