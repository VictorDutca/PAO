#ifndef LISTA_H
#define LISTA_H

#include <workout.h>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <errhandler.h>

template<class T>
class Dlista {
    friend class iterator;
    friend class const_iterator;
private:
    class Nodo {
    public:
        T info;
        Nodo *prec, *next;
        Nodo(T, Nodo* =0, Nodo* =0);
        ~Nodo();
        bool operator==(const Nodo&) const;
        bool operator!=(const Nodo& n) const;
    };

    Nodo* first;
    unsigned int size;
    void cancellaNodo(Nodo*);
    T popFirst();
    T popLast();

public:
    Dlista();
    Dlista(const Dlista&);
    ~Dlista();
    Dlista& operator=(const Dlista&) const;
    T checkLast();
    int cancellaElemento (const T&);
    int getSize() const;
    bool operator==(const Dlista&) const;
    void pushNodo(Nodo*);
    void pushT(T);
    void removeAt(unsigned int);

    class iterator{
        friend class Dlista;
    private:
        Nodo* ptr;
    public:
        bool operator==(iterator) const;
        bool operator!=(iterator) const;
        iterator operator++(int);
        iterator& operator++();
        iterator operator--(int);
        iterator& operator--();
        T* operator->() const;
        T& operator*() const;
    };

    class const_iterator{
        friend class Dlista;
    private:
        const Nodo* ptr;
    public:
        bool operator==(const_iterator) const;
        bool operator!=(iterator) const;
        const_iterator operator++(int); //post
        const_iterator& operator++(); //pre
        const_iterator operator--(int);
        const_iterator& operator--();
        T* operator->() const;
        T& operator*() const;
    };
    iterator erase(iterator);
    iterator find(const T&) const;
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    T& operator[](iterator) const;
    const T& At(int) const;
};

//parte privata di Dlista

//parte implementativa di Nodo

template <typename T>
Dlista<T>::Nodo::Nodo(T w,typename Dlista<T>::Nodo *p, typename Dlista<T>::Nodo *n): info(w), prec(p), next(n) {}

template <typename T>
Dlista<T>::Nodo::~Nodo(){
    if(next){
        delete next;
    }
}

template <typename T>
bool Dlista<T>::Nodo::operator!=(const Nodo& n) const {
    return info!=n.info && prec==n.prec && next!=n.next;
}

template <typename T>
bool Dlista<T>::Nodo::operator==(const Nodo& n) const {
    return info==n.info && prec==n.prec && next==n.next;
}

//fine implementazione di Nodo

template <typename T>
T Dlista<T>::popFirst(){
    T aux;
    try{
    if(first){
        typename Dlista<T>::Nodo* a=0;
        if(first) {
            a=first;
            first=first->next;
            size--;
        }
        a->next=0;
        aux = a->info;
        delete a;
        return aux;
    }
    else {
        throw ErrEmptyList();
    }
    }
    catch(ErrEmptyList) {return 0;}
}

template <typename T>
T Dlista<T>::popLast(){
    T aux;
    try{
    if(first){
        typename Dlista<T>::Nodo* a=first;
        while(a->next){
            a=a->next;
        }
        a->prec->next = 0;
        size --;
        aux = a->info;
        return aux;
    }
    else {
        throw ErrEmptyList();
    }
    }
    catch (ErrEmptyList) {return 0;}
}

template <typename T>
void Dlista<T>::cancellaNodo(typename Dlista<T>::Nodo *current){
    if(!current->prec) { //Cancellazione in testa
        if(current->next) {
            first=first->next;
            first->prec=0;
            current->next=0;
            delete current;
            size--;
            return;
        }
        else {
            delete current;
            return;
        }
    }
    if(current->prec && current->next) { //Cancellazione centrale
        typename Dlista<T>::Nodo* a=current->prec;
        a->next=current->next;
        typename Dlista<T>::Nodo* b=current->next;
        b->prec=current->prec;
        current->prec=0;
        current->next=0;
        delete current;
        size--;
        return;
    }
    if(!current->next) { //Cancellazione alla fine
        typename Dlista<T>::Nodo* a=current->prec;
        a->next=0;
        delete current;
        size--;
        return;
    }
}

//implementazione parte publica di Dlista

template <typename T>
Dlista<T>::Dlista(): first(0), size(0){}

template <typename T>
Dlista<T>::Dlista(const Dlista& listaAux){
    typename Dlista<T>::Nodo* primo = listaAux.first;
    first=new Nodo(listaAux.first,0,0);
    typename Dlista<T>::Nodo* testa=first;
    typename Dlista<T>::Nodo*pre=0;
    while(primo){
        pre=primo;
        primo = primo->next;
        testa->next=new Nodo(primo->info,pre,0);
        testa=testa->next;
    }
}

template <typename T>
Dlista<T>::~Dlista(){
    if(first) {
        delete first;
    }
}

template <typename T>
T Dlista<T>::checkLast(){
    T aux;
    try{
    if(first){
        typename Dlista<T>::Nodo* a=first;
        while(a->next){
            a=a->next;
        }

        aux = a->info;
        return aux;
    }
    else {
        throw ErrEmptyList();
    }
    }
    catch (ErrEmptyList) {return 0;}
}


template <typename T>
void Dlista<T>::removeAt(unsigned int position){
    typename Dlista<T>::Nodo *a=first;
    try{
        if(position > size){
            throw ErrList();
        }
        if(position == 0){
            popFirst();
        }
        else if(position == (size-1)){
            popLast();
        }
        else{
            while(position){
                a=a->next;
                position --;
            }
            a->prec->next = a->next;
            a->next->prec = a->prec;
            a->prec = 0;
            a->next = 0;
            size--;
            delete a;
        }
    }
    catch (ErrList) {};
}

template <typename T>
int Dlista<T>::getSize() const{
    return size;
}

template <typename T>
void Dlista<T>::pushNodo(typename Dlista<T>::Nodo *n){
    if(first){
        Nodo* a=first;
        while(a->next) {
            a=a->next;
        }
        a->next=n;
        n->prec=a;
        n->next=0;
        size++;
    }
    else {
        first=n;
        size++;
    }
}

template <typename T>
void Dlista<T>::pushT(T t){
    typename Dlista<T>::Nodo* n = new Nodo (t,0,0);
    pushNodo(n);
}

template <typename T>
bool Dlista<T>::operator==( const Dlista& listaAux) const{
    typename Dlista<T>::Nodo* a=first;
    typename Dlista<T>::Nodo* b=listaAux.first;
    while(a->next && b->next) {
        if(a->info != b->info) {
            return false;
        }
        a=a->next;
        b=b->next;
    }
    return true;
}

template <typename T>
Dlista<T>& Dlista<T>::operator=(const Dlista &listaAux) const{
    if(first!=listaAux.first) {
        delete first;
        first=new Nodo(listaAux.first->info, 0);
        typename Dlista<T>::Nodo* a=first;
        typename Dlista<T>::Nodo* b=listaAux.first;
        while(b->next) {
            b=b->next;
            a->next=new Nodo(b->info, 0);
            a=a->next;
        }
        a->next=new Nodo(b->info, 0);
        return *this;
    }
}

template <typename T>
int Dlista<T>::cancellaElemento(const T& el) {
    if(!first) return -1;
    typename Dlista<T>::Nodo* scorri = first;
    if(scorri->info == el) {
        first = first->next;
        first->prec = 0;
        scorri->next = 0;
        delete scorri;
        return 0;
    }
    while(scorri->next){
        scorri=scorri->next;
        if(scorri->info == el){
            scorri->prec->next=scorri->next;
            if(scorri->next) scorri->next->prec=scorri->prec;
            scorri->next=0;
            scorri->prec=0;
            delete scorri;
            return 0;
        }
    }
    return -1;
}

// parte implementativa di iterator

template <typename T>
bool Dlista<T>::iterator::operator==(typename Dlista<T>::iterator it) const{
    return ptr == it.ptr;
}

template <typename T>
bool Dlista<T>::iterator::operator!=(typename Dlista<T>::iterator it) const{
    return ptr != it.ptr;
}

template <typename T>
typename Dlista<T>::iterator& Dlista<T>::iterator::operator++(){//prefisso
    if(ptr){
        ptr = ptr->next;
    }
    return *this;
}

template <typename T>
typename Dlista<T>::iterator Dlista<T>::iterator::operator++(int){ //postfisso
    iterator temp = *this;
    if(ptr){
        ptr=ptr->next;
    }
    return temp;
}

template <typename T>
typename Dlista<T>::iterator Dlista<T>::iterator::operator--(int){
    iterator temp = *this;
    if(ptr){
        ptr = ptr->prec;
    }
    return temp;
}

template <typename T>
typename Dlista<T>::iterator& Dlista<T>::iterator::operator--(){
    if(ptr){
        ptr = ptr->prec;
    }
    return *this;
}

template <typename T>
T* Dlista<T>::iterator::operator->() const{
    return &(ptr->info);
}

template <typename T>
T& Dlista<T>::iterator::operator*() const{
    return ptr->info;
}

template <typename T>
typename Dlista<T>::iterator Dlista<T>::erase(typename Dlista<T>::iterator i){
    if(size == 0)
        return begin();
    if(i.ptr){
        iterator aux;
        iterator aux1;
        aux1.ptr= i.ptr->prec;
        aux.ptr = i.ptr->next;
        cancellaNodo(i.ptr);
        if(!aux.ptr){
            return aux1;
        }
        return aux;
    }
    else
        return end();
}

template <typename T>
typename Dlista<T>::iterator Dlista<T>::find(const T& t) const {
    if(size>0){
        typename Dlista<T>::Nodo* scorri=first;
        while(scorri){
            if(scorri->info==t){
                iterator ok = scorri;
                return ok;
            }
            scorri=scorri->next;
        }
    }
}

//parte implementativa di const_iterator

template <typename T>
bool Dlista<T>::const_iterator::operator==(const_iterator it) const{
    return ptr == it.ptr;
}
template <typename T>
bool Dlista<T>::const_iterator::operator!=(iterator it) const{
    return ptr != it.ptr;
}

template <typename T>
typename Dlista<T>::const_iterator Dlista<T>::const_iterator::operator++(int){ //postfisso
    const_iterator temp = *this;
    if(ptr){
        ptr=ptr->next;
    }
    return temp;

}

template <typename T>
typename Dlista<T>::const_iterator& Dlista<T>::const_iterator::operator++(){ //prefisso
    if(ptr){
        ptr = ptr->next;
    }
    return *this;

}

template <typename T>
typename Dlista<T>::const_iterator Dlista<T>::const_iterator::operator--(int){
    const_iterator temp = *this;
    if(ptr){
        ptr = ptr->prec;
    }
    return temp;
}

template <typename T>
typename Dlista<T>::const_iterator& Dlista<T>::const_iterator::operator--(){
    if(ptr){
        ptr = ptr->prec;
    }
    return *this;
}

template <typename T>
T* Dlista<T>::const_iterator::operator->() const{
    return &(ptr->info);
}

template <typename T>
T& Dlista<T>::const_iterator::operator*() const{
    return ptr->info;
}

template <typename T>
T& Dlista<T>::operator[](iterator i) const{
    return i.ptr->info;
}

template <typename T>
typename Dlista<T>::iterator Dlista<T>::begin(){
    iterator aux;
    aux.ptr = first;
    return aux;
}

template <typename T>
typename Dlista<T>::iterator Dlista<T>::end(){
    iterator aux;
    aux.ptr = 0;
    return aux;
}

template <typename T>
typename Dlista<T>::const_iterator Dlista<T>::begin() const{
    const_iterator aux;
    aux.ptr = first;
    return aux;
}

template <typename T>
typename Dlista<T>::const_iterator Dlista<T>::end() const{
    const_iterator aux;
    aux.ptr = 0;
    return aux;
}

template <typename T>
const T& Dlista<T>::At(int position) const{
    Nodo *aux = first;
    int counter = 0;
    while (aux && counter < position) {
        aux = aux->next;
        counter++;
    }

    if(counter < position)
        throw;

    return aux->info;
}

#endif // LISTA_H
