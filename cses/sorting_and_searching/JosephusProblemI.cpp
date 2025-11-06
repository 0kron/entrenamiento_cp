#include<bits/stdc++.h>
#define endl '\n'

using namespace std; 
using ll = long long int; 
using paiir = pair<int, int>; 

struct LinkedVal {
    int value; 
    LinkedVal* next; 
    LinkedVal* prev; 
    LinkedVal(int val) : value(val), next(nullptr), prev(nullptr) {}
}; 

struct LinkedRing {
    LinkedVal* begin = nullptr; 
    LinkedVal* end = nullptr; 

    void push_back(int val) {
        LinkedVal* nuevo = new LinkedVal(val);
        if (begin == nullptr) {
            begin = nuevo;
            end = nuevo;
            nuevo->next = nuevo;
            nuevo->prev = nuevo;
        } else {
            nuevo->prev = end;
            nuevo->next = begin;
            end->next = nuevo;
            begin->prev = nuevo;
            end = nuevo;
        }
    }

    LinkedVal* del(LinkedVal* pBorrar) {
        if (pBorrar == nullptr) return nullptr;
        
        LinkedVal* retorno = pBorrar->prev; 
        
        // Si solo queda un elemento
        if (pBorrar->next == pBorrar) {
            begin = nullptr;
            end = nullptr;
        } else {
            pBorrar->prev->next = pBorrar->next;
            pBorrar->next->prev = pBorrar->prev;
            
            if (pBorrar == begin) begin = pBorrar->next;
            if (pBorrar == end) end = pBorrar->prev;
        }
        
        delete pBorrar;
        return retorno; 
    }

    ~LinkedRing() {
        // Liberar memoria para evitar memory leaks
        if (begin == nullptr) return;
        
        LinkedVal* current = begin;
        LinkedVal* nextNode;
        
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != begin);
    }
};

int main() {
    int n;
    cin >> n; 
    int k; cin >> k;  
    LinkedRing valores; 
    
    for (int i = 0; i < n; i++) {
        valores.push_back(i + 1);  
    }
    LinkedVal inicio = LinkedVal(-1); 
    LinkedVal* iterador = &inicio;
    iterador->next = valores.begin; 
    int count = 0;
    
    while (count < n && iterador != nullptr) {
        for (int j = 0; j < (k+1)%(n-count); j++) {
            if (iterador != nullptr) {
                iterador = iterador->next;
            }
        } 
        
        if (iterador != nullptr) {
            cout << iterador->value << " "; 
            iterador = valores.del(iterador); 
            count++; 
        }
    }
    
    return 0;
}