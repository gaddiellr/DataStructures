#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <string>
#include <sstream>
#include <iostream>
#include "exception.h"
using namespace std;

template <class T>
class PriorityQueue {
private:
	T* data;
	unsigned int length;
	unsigned int count;
	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;
	void pushDown(unsigned int);
	void swap(unsigned int, unsigned int);
public:
	PriorityQueue(unsigned int);
	~PriorityQueue();
	bool full() const;
	void push(T);
	void pop();
	T top();
	bool empty() const;
	unsigned int size() const;
	void clear();
	string toString() const;
};

template <class T>
PriorityQueue<T>::PriorityQueue(unsigned int sze) {
	length = sze;
	data = new T[length];
	count = 0;
}

template <class T>
PriorityQueue<T>::~PriorityQueue() {
	delete [] data;
	data = NULL;
	length = 0;
	count = 0;
}

template <class T>
bool PriorityQueue<T>::full() const {
	return (count == length);
}

template <class T>
unsigned int PriorityQueue<T>::parent(unsigned int pos) const {
	return (pos - 1) / 2;
}

template <class T>
unsigned int PriorityQueue<T>::left(unsigned int pos) const {
	return (pos * 2) + 1;
}

template <class T>
unsigned int PriorityQueue<T>::right(unsigned int pos) const {
	return (pos * 2) + 2;
}

template <class T>
void PriorityQueue<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void PriorityQueue<T>::pushDown(unsigned int pos) {
    unsigned int le = left(pos);
    unsigned int ri = right(pos);
    unsigned int min = pos;

    if (le < count && data[le] < data[min]){
        min = le;
    }
    if (ri < count && data[ri] < data[min]){
        min = ri;
    }

    if(min != pos){
        swap(pos, min);
        pushDown(min);
    }
}

//Agregar un dato a la fila priorizada

template <class T>
void PriorityQueue<T>::push(T val) {
	unsigned int pos;
	if (full()){
		throw Overflow();
	}

	pos = count;
	count++;
	while(pos > 0 && val < data[parent(pos)]){
		data[pos]= data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
}

//Sacar de la fila priorizada el dato que tiene mayor prioridad

template <class T>
void PriorityQueue<T>::pop() {
	if (empty()){
		throw NoSuchElement();
	}
	data[0] = data[--count];
	pushDown(0);
}

//Regresar el valor del dato que está con mayor prioridad en la fila priorizada

template <class T>
T PriorityQueue<T>::top() {
	if (empty()){
		throw NoSuchElement();
	}
	return data[0];
}

//Regresar un valor boleando diciendo si la fila priorizada esta vacía o tiene datos

template <class T>
bool PriorityQueue<T>::empty() const {
	return (count == 0);
}

//Regresa la cantidad de datos que tiene la fila priorizada

template <class T>
unsigned int PriorityQueue<T>::size() const {
	return count;
}

template <class T>
void PriorityQueue<T>::clear() {
	count = 0;
}

template <class T>
string PriorityQueue<T>::toString() const {
	stringstream aux;

	aux << "[";
	for (unsigned int i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		}
	aux << data[i];
	}
	aux << "]";
	return aux.str();
}
#endif
