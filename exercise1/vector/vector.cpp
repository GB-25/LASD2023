
/// @brief 
namespace lasd {

/* ************************************************************************** */

template <typename Data>
Vector<Data>::Vector(const ulong newdimensione){
    elemento= new Data[newdimensione] {};
    dimensione = newdimensione;
}

template <typename Data>
Vector<Data>::Vector(const MappableContainer<Data>& mapcontainer){
    dimensione = mapcontainer.Size();
    elemento = new Data[dimensione];

    for (ulong i = 0; i < dimensione; i++)
    {
        elemento[i] = mapcontainer[i];
    };
}

template <typename Data>
Vector<Data>::Vector(MutableMappableContainer<Data>&& mutcontainer){
    dimensione = mutcontainer.Size();
    elemento = new Data[dimensione];

    for (ulong i = 0; i < dimensione; i++)
    {
        elemento[i] = mutcontainer[i];
    };
}

template<typename Data>
Vector<Data>::Vector(const Vector<Data>& vet){
    elemento = new Data[vet.dimensione];
    std::copy(vet.elemento, vet.elemento + vet.dimensione, elemento);
    dimensione = vet.dimensione;
}

template<typename Data>
Vector<Data>::Vector (Vector<Data>&& vet) noexcept{
    std::swap(elemento, vet.elemento);
    std::swap(dimensione, vet.dimensione);
}

template<typename Data>
Vector<Data>::~Vector(){
    delete[] elemento;
}

template<typename Data>
Vector<Data>& Vector<Data>::operator = (const Vector<Data>& vet) {
    Vector<Data>* elemento = new Vector<Data>(vet);
    std::swap(*elemento, *this);
    delete elemento;
    return this;
}

template<typename Data>
Vector<Data>& Vector<Data>::operator= (Vector <Data>&& vet) noexcept {
    std::swap(elemento, vet.elemento);
    std::swap(dimensione, vet.dimensione);
    return *this;
} 

template<typename Data>
bool Vector<Data>::operator == (const Vector<Data>& vet) const noexcept {
    if(dimensione == vet.dimensione){
        for(ulong i=0; i < dimensione; ++i) {
            if(elemento[i] != vet.elemento[i]){
                return false;
            }
            
        }
         return true;
    }
   else{
       return false;
   }

}

template<typename Data>
bool Vector<Data>::operator!=(const Vector<Data>& vet) const noexcept{
    return !(*this == vet);
}

template<typename Data>
void Vector<Data>::Resize(const ulong newdimensione){
    if(newdimensione == 0){
        Clear();
    }
    else if (dimensione != newdimensione) {
        ulong limit = (dimensione < newdimensione) ? dimensione : newdimensione;
        Data* tmp_elemento = new Data[newdimensione] {};
        for (ulong i = 0; i < limit; ++i) {
            std::swap(elemento[i], tmp_elemento[i]);
        }
        std::swap(elemento, tmp_elemento);
        dimensione = newdimensione;
        delete[] tmp_elemento;
    }

}

template<typename Data>
void Vector<Data>::Clear(){
    delete[]elemento;
    elemento = nullptr;
    dimensione = 0;
}

template<typename Data>
Data& Vector<Data>::Front()const {
    if (dimensione != 0) {
        return elemento[0];
    }
    else{
        throw std::length_error ("Array vuoto.");

    }

}

template<typename Data>
Data& Vector<Data>::Back() const{
    if(dimensione != 0){
        return elemento[dimensione-1];
    } 
    else{
        throw std::length_error("Array vuoto.");
    }

}

template<typename Data>
Data& Vector<Data>::operator[](const ulong i) const{
    if(i < dimensione){
        return elemento[i];
    }
    else {
        throw std::out_of_range("Indice:" + std::to_string(i) + "; lunghezza del vettore: " +std::to_string(dimensione) + ".");
    }

}

template<typename Data>
void Vector<Data>::Sort() const{
    
}


/* ************************************************************************** */
}

