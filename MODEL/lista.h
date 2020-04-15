#ifndef LISTA_H
#define LISTA_H

#include<workout.h>

template<class T>
class Dlista{
friend class iterator;
friend class const_iterator;
public:
class Nodo {
public:
    T info;
    Nodo* prec,*next;
    Nodo(T w=0, Nodo* p=0, Nodo* n=0) : info(w), prec(p),next(n) {}

//        Nodo(const Nodo& n) {
//            info=n.info;
//            prec=n.prec;
//            next=n.next;
//        }
    /*Nodo& operator=(const Nodo& n) {
        if(this!=&n){

            info=n.info;
            prec=n.prec;
            next=n.next;
        }
            return *this;

    }*/
    ~Nodo() {
        if(next) {
            delete next;
        }
    }
    bool operator==(const Nodo& n) const {
        return info==n.info && prec==n.prec && next==n.next;
    }
    bool operator!=(const Nodo& n) const {
        return info!=n.info && prec==n.prec && next!=n.next;
    }
    };
// fine calss Nodo

    unsigned int size;
    Nodo* first;
    Dlista() : first() {}
    Dlista(const Dlista& l) {
        Nodo* primo = l.first;
        first=new Nodo(l.first,0,0);
        Nodo* testa=first;
        Nodo*pre=0;
        while(primo){
            pre=primo;
            primo = primo->next;
            testa->next=new Nodo(primo->info,pre,0);
            testa=testa->next;
        }
    }
    ~Dlista() {
        if(first) {
            delete first;
        }
    }
    void pushNodo(Nodo* n) {
        Nodo* a=first;
        while(a->next) {
            a=a->next;
        }
        a->next=n;
        n->next=0;
    }
    Nodo* popFirst() {
        Nodo *a=0;
        if(first) {
            a=first;
            first=first->next;
        }
        a->next=0;
        return a;
    }
    /*if( !primo || !ultimo || !attuale)
   throw ErrContenitore();
if(attuale == primo && primo == ultimo)
   primo = ultimo = 0;
else if(attuale == primo) {
   primo = primo->dx;
   primo->sx = 0;
   attuale->dx = 0;
} else if( attuale == ultimo ) {
   ultimo = attuale->sx;
   ultimo->dx = 0;
} else {
   (attuale->sx)->dx = attuale->dx;
   (attuale->dx)->sx = attuale->sx;
   attuale->dx = attuale->sx = 0;
}
delete attuale;
*/

    bool operator==(const Dlista& l) const {
        Nodo* a=first;
        Nodo* b=l.first;
        while(a->next && b->next) {
            if(a->info != b->info) {
                return false;
            }
            a=a->next;
            b=b->next;
        }
        return true;
    }

    Dlista& operator=(const Dlista& l) {
        if(first!=l.first) {
            delete first;
            first=new Nodo(l.first->info, 0);
            Nodo* a=first;
            Nodo* b=l.first;
            while(b->next) {
                b=b->next;
                a->next=new Nodo(b->info, 0);
                a=a->next;
            }
            a->next=new Nodo(b->info, 0);
            return *this;
        }
    }

     void cancellaNodo(Nodo* current) {
        if(!current->prec) { //Cancellazione in testa
            if(current->next) {
                first=first->next;
                first->prec=0;
                current->next=0;
                delete current;
                return;
            }
            else {
                delete current;
                return;
            }
        }
        if(current->prec && current->next) { //Cancellazione centrale
            Nodo* a=current->prec;
            a->next=current->next;
            Nodo* b=current->next;
            b->prec=current->prec;
            current->prec=0;
            current->next=0;
            delete current;
            return;
        }
        if(!current->next) { //Cancellazione alla fine
            Nodo* a=current->prec;
            a->next=0;
            delete current;
            return;
        }
    }

    class iterator{
    friend class Dlista;
    private:
         Nodo* ptr;
    public:
         bool operator==(iterator it) const{
             return ptr == it.ptr;
         }
         bool operator!=(iterator it) const{
             return ptr != it.ptr;
         }
         iterator operator++(int){//postfisso
             iterator temp = *this;
             if(ptr){
                 ptr=ptr->next;
             }
             return temp;
         }
         iterator& operator++(){ //prefisso
             if(ptr){
                ptr = ptr->next;
             }
             return *this;
         }
         //ricordare che da favigno non fungeva il --
         iterator operator--(int){
             iterator temp = *this;
              if(ptr){
                ptr = ptr->prec;
              }
                return temp;
         }
         iterator& operator--(){
             if(ptr){
               ptr = ptr->prec;
             }
               return *this;
         }
         Nodo* operator->() const{
             return &(ptr->info);

         }
         Nodo& operator*() const{
             return ptr->info;
         }

};
    iterator erase(iterator i){
        if(size == 0)
            return begin();
        if(i.punt){
            iterator aux;
            aux.ptr = i.ptr->next;
            cancellaNodo(i.ptr);
            size--;
            return aux;
        }
        else
            return end();
    }
    //iterator it = nomestruttura.find()
    iterator find(const T& t) const {
        if(size>0){
            Nodo* scorri=first;
            while(scorri){
                if(scorri->info==t){
                    Dlista<T>::iterator ok = scorri;
                    return ok;
                 }
                scorri=scorri->next;
            }
        }
    }


        class const_iterator{
            friend class Dlista;
        private:
            const Nodo* ptr;
        public:
            bool operator==(iterator it) const{
                return ptr == it.ptr;
            }
            bool operator!=(iterator it) const{
                return ptr != it.ptr;
            }
            const_iterator operator++(int){
                const_iterator temp = *this;
                if(ptr){
                    ptr=ptr->next;
                }
                return temp;

            } //postfisso
            const_iterator& operator++(){
                if(ptr){
                   ptr = ptr->next;
                }
                return *this;

            }    //prefisso
            const_iterator operator--(int){
                const_iterator temp = *this;
                 if(ptr){
                   ptr = ptr->prec;
                 }
                   return temp;
            }
            const_iterator& operator--(){
                if(ptr){
                  ptr = ptr->prec;
                }
                  return *this;
            }
            T* operator->() const{
                return &(ptr->info);
            }
            T& operator*() const{
                return ptr->info;
            }
            //Dlist<T> get_tipoWorkout();



        };

             iterator begin(){
                iterator aux;
                aux.ptr = first;
                return aux;
             }
             iterator end(){
                 iterator aux;
                 aux.ptr = 0;
                 return aux;
             }
             const_iterator begin() const{
                const_iterator aux;
                aux.ptr = first;
                return aux;
             }
             const_iterator end() const{
                 const_iterator aux;
                 aux.ptr = 0;
                 return aux;
             }
             T& operator[](iterator i) const{
                 return i.ptr->info;
             }

             // La funzione erase fatta sopra per ora sembra quella giusta
             /*iterator erase(iterator i){
                    if(i.ptr) {
                        iterator ret;
                        ret.ptr = i.ptr->next;

                            cancellaNodo(i.ptr);
                        //possibile exception


                        return ret;
                    } else
                        return end();
                 }

                */

};

#endif // LISTA_H
