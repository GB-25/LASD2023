
namespace lasd {

/* ************************************************************************** */

template<typename Data>
List<Data>::Node::Node(const Data& valore){
    elemento = valore;
    this->next = nullptr;
}

template<typename Data>
List<Data>::Node::Node(Data&& valore) noexcept {
    std::swap(elemento, valore);
    this->next = nullptr;
}

template<typename Data>
typename List<Data>::Node& List<Data>::Node::operator=(const typename List<Data>::Node& nodo){
    this->elemento = nodo.elemento;
    this->next = nodo.next;
}

template<typename Data>
typename List<Data>::Node& List<Data>::Node::operator=(typename List<Data>::Node&& nodo) noexcept{
    std::swap(elemento, nodo.elemento);
    std::swap(next, nodo.next);
}

template<typename Data>
bool List<Data>::Node::operator==(const Node& nodo) const noexcept{
    if (elemento != nodo.elemento){
        return false;
    }
    return true;
}

template<typename Data>
bool List<Data>::Node::operator!=(const Node& nodo) const noexcept{
    return !(*this == nodo);
}

template<typename Data>
List<Data>::List(const MappableContainer<Data>& map){

    this->First = nullptr;
    this->Last = nullptr;
    
    if(map.Size()!=0){
        for (unsigned long i = 0; i < map.Size(); i++) {
            InsertAtBack(map[i]);
        }
    }
}

template<typename Data>
List<Data>::List(MutableMappableContainer<Data>&& mut){
    this->First = nullptr;
    this->Last = nullptr;
    
    if(mut.Size()!=0){
        for (unsigned long i = 0; i < mut.Size(); i++) {
            InsertAtBack(mut[i]);
        }
    }
}

template <typename Data>
List<Data>::List(const List<Data>& otherList){
    if(this != &otherList){

        if (otherList.First == nullptr){
            this->First = nullptr;
            this->Last = nullptr;
            dimensione = 0;
        }
        else{
            struct Node* current;
            current = otherList.First;
            struct Node* node = new Node(current->elemento);
            this->First = node;
            this->Last = this->First;

            current = current->next;
            while (current != nullptr) {
                struct Node* newnode = new Node(current->elemento);
                this->Last->next = newnode;
                this->Last = newnode;
                current = current->next;
            }
            this->dimensione = otherList.dimensione;
        }
        
    }
}

template<typename Data>
List<Data>::List(List<Data>&& otherList) noexcept{
    dimensione = otherList.dimensione;
    otherList.dimensione = 0;
    this->First = otherList.First;
    otherList.First = nullptr;
}

template<typename Data>
List<Data>::~List(){
    Node* current = this->First;
    while(current != nullptr){
        Node* to_delete = current;
        current = current -> next;
        delete to_delete;

    }
}

template <typename Data>
List<Data>& List<Data>::operator=(const List<Data>& cpylist){
    List<Data>*tmplist = new List<Data>(cpylist);
    std::swap(*tmplist, *this);
    delete tmplist;
    return *this;
}

template<typename Data>
List<Data>& List<Data>::operator=(List<Data>&& mvlist) noexcept{
  std::swap(this->First, mvlist.First);
  std::swap(this->Last, mvlist.Last);
  std::swap(dim, mvlist.dim);
  return *this;
}

template<typename Data>
bool List<Data>::operator==(const List<Data>& list) const noexcept{

  if(dimensione == list.dimensione){
    struct Node* current = this->First;
    struct Node* Tmp = list.First;
    for(unsigned long i = 0; i < dimensione; i++){
      if(current->elemento != Tmp->elemento){
        return false;
      }
      current = current->next;
      Tmp = Tmp->next;
    }
    return true;
  }
  else{
    return false;
  }

}  

template<typename Data>
bool List<Data>::operator!=(const List<Data>& list) const noexcept{
  return !(*this == list);
}


template<typename Data>
void List<Data>::InsertAtFront(const Data& ival)noexcept {

    struct Node* newNode;
    newNode = new Node (ival);
    newNode->next = this->First;
    this->First = newNode;
    dimensione++;
    if(this->Last == nullptr)
        this->Last = newNode;
}

template<typename Data>
void List<Data>::InsertAtFront(Data&& ival) noexcept{
    struct Node* newNode;
    newNode = new Node(std::move(ival));
    newNode-> next = this->First;
    this->First = newNode;
    dimensione++;
    if (this->Last == nullptr) {
        this->Last = newNode;
    }
    
}

template <typename Data>
void List<Data>::RemoveFromFront(){
    struct Node* current;
    if(this->First == nullptr)
        throw std::length_error("Lista vuota.");
    else if (this->First == this->Last){
        dimensione--;
        this->First = nullptr;
        this->Last = nullptr;
    }
    else{
        current = this->First;
        this->First = this->First->next;
        dimensione--;
    }
}

template<typename Data>
Data& List<Data>::FrontNRemove(){
    struct Node* current;
    if(First == nullptr)
        throw std::length_error("Lista vuota.");
    else if (this->First == this->Last){
        dimensione--;
        current = this->First;
        this->First = nullptr;
        this->Last = nullptr;
        return current->elemento;
    } else {
                current = this->First;
				this->First = this->First->next;
				dimensione--;
				return current->elemento;
		}
}

template<typename Data>
void List<Data>::InsertAtBack(const Data& ival) {
    struct Node* newNode;
    newNode = new Node(ival);
    if (!this->First) {
        this->First = newNode;
        this->Last = newNode;
        dimensione++;
}
else {
    struct Node* tmp = First;
    while(tmp->next) tmp = tmp->next;
    tmp->next = newNode;
    dimensione++;
    this->Last = tmp->next;
    }

}

template <typename Data>
void List<Data>::InsertAtBack(Data&& ivalue) noexcept{
    struct Node* newNode;
    newNode = new Node (ivalue);
    if(!First){
        this->First = newNode;
        this->Last = newNode;
        dimensione++;
    }
    else{
        struct Node* tmp = this->First;
        while(tmp->next) tmp = tmp->next;
        tmp -> next = newNode;
        dimensione++;
        this->Last=tmp->next;
    }
}

template<typename Data>
void List<Data>::Clear(){
    struct Node* tmp;
    while(First != nullptr){
        tmp = this->First;
        this->First = this->First->next;
    }
    this->Last = nullptr;
    dimensione = 0;
    this->First = nullptr; 
}

template <typename Data>
bool List<Data>::Insert(const Data& dat){
    bool 
}

/* ************************************************************************** */

}
