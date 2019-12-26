/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dsaLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DSALIB_H
#define DSA191_A1_DSALIB_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class DSAException {
    int     _error;
    string  _text;
public:

    DSAException() : _error(0), _text("Success") {}
    DSAException(int err) : _error(err), _text("Unknown Error") {}
    DSAException(int err, const char* text) : _error(err), _text(text) {}

    int getError() { return _error; }
    string& getErrorText() { return _text; }
};

template <class T>
struct L1Item {
    T data;
    L1Item<T> *pNext;
    L1Item() : pNext(NULL) {}
    L1Item(T &a) : data(a), pNext(NULL) {}
};

template <class T>
class L1List {
    L1Item<T>   *_pHead;// The head pointer of linked list
    L1Item<T>   *_pTail;
    size_t      _size;// number of elements in this list
public:
    L1List() : _pHead(NULL), _pTail(NULL), _size(0) {}
    ~L1List(){
        this->clean();
    }


	L1Item<T> *get_Head()
	{
		return _pHead;
	}

    void    clean(){
        L1Item<T> * temp = _pHead;
        while (_pHead != NULL) {
            temp = _pHead;
            _pHead = _pHead->pNext;
            delete temp;
            this->_size --;
        }
        _pTail = NULL;
    }
    bool    isEmpty() {
        return _pHead == NULL;
    }
    size_t  getSize() {
        return _size;
    }

    T&      at(int i);// give the reference to the element i-th in the list
    T&      operator[](int i);// give the reference to the element i-th in the list

    bool    find(T& a, int& idx);// find an element similar to a in the list. Set the found index to idx, set idx to -1 if failed. Return true if success.
    int     insert(int i, T& a);// insert an element into the list at location i. Return 0 if success, -1 otherwise
    int     remove(int i);// remove an element at position i in the list. Return 0 if success, -1 otherwise.

    int     push_back(T& a);// insert to the end of the list
    int     insertHead(T& a);// insert to the beginning of the list

    int     removeHead();// remove the beginning element of the list
    int     removeLast();// remove the last element of the list

    void    reverse();

    void    traverse(void (*op)(T&)) {
        // TODO: Your code goes here
        L1Item<T> *p = _pHead;
		while (p) {
			op(p->data);
			p = p->pNext;
		}
    }
    void    traverse(void (*op)(T&, void*), void* pParam) {
        // TODO: Your code goes here
        L1Item<T> *p = _pHead;
		while (p) {
			op(p->data, pParam);
			p = p->pNext;
		}
    }
};

/// Insert item to the end of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::push_back(T &a) {
    // TODO: Your code goes here
    L1Item<T> * pNew = new L1Item<T>(a);
    if (this->getSize() == 0) {
        this->_pHead = pNew;
        this->_pTail = pNew;
        ++this->_size;
        return 0;
    }
    L1Item<T> *temp = this->_pTail;
    temp->pNext = pNew;
    this->_pTail = pNew;
    ++this->_size;
    return 0;
}

/// Insert item to the front of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::insertHead(T &a) {
    // TODO: Your code goes here
    if (this->getSize() == 0) {
        this->_pHead = new L1Item<T>(a);
        this->_pTail = this->_pHead;
        ++this->_size;
        return 0;
    }
    L1Item<T>* temp = new L1Item<T>(a);
    temp->pNext = this->_pHead;
    this->_pHead = temp;
    ++this->_size;
    return 0;
}

/// Remove the first item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeHead() {
    // TODO: Your code goes here
    if(_pHead == NULL) return -1;
    L1Item<T>* pLoc = _pHead;
    _pHead = pLoc->pNext;
    pLoc->pNext = NULL;
    delete pLoc;
    --this->_size;
    return 0;
}

/// Remove the last item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeLast() {
    // TODO: Your code goes here
    if (_pHead == NULL) return -1;
    if (this->_size <= 1) {
        L1List<T>::removeHead();
        return 0;
    }
    L1Item<T>* temp = _pHead;
    for (int i = 0; i < this->_size - 2; i++)
        temp = temp->pNext;
    L1Item<T>* temp1 = temp->pNext;
    temp->pNext = NULL;
    delete temp1;
    --this->_size;
    return 0;
}

template <class T>
int L1List<T>::remove(int pos) {
    // TODO: Your code goes here
    if (_pHead == NULL) return -1;
    if (this->_size <= 1 || pos == 0) {
        L1List<T>::removeHead();
        return 0;
    }
    L1Item<T>* temp = _pHead;
    L1Item<T>* temp1 = _pHead;
    for (int i = 0; i < pos; i++) {
        temp1 = temp;
        temp = temp->pNext;
    }
    temp1->pNext = temp->pNext;
    temp->pNext = NULL;
    delete temp;
    --this->_size;
    return 0;
}


template <class T>
int L1List<T>::insert(int pos, T& a) {
    // TODO: Your code goes here
    L1Item<T>* pNew = new L1Item<T>(a);
    if (pos > this->getSize() || pos < 0 || pNew == NULL) return -1;
    else if (pos == 0 || this->isEmpty()) return this->insertHead(a);
    else {
        L1Item<T>* current = this->_pHead;
        for (int i = 0; i < pos - 1; i++)
            current = current->pNext;
        pNew->pNext = current->pNext;
        current->pNext = pNew;
        this->_size++;
        return 0;
    }
}
#endif //DSA191_A1_DSALIB_H
