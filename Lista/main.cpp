#include <iostream>
template<class T>
class LSLSE;
class Socioclup{
private:
  int numero;
  std::string nombresocio;
  std::string domiciliosocio;
  int alloingreso;
public:
       Socioclup():numero(0),nombresocio(""),domiciliosocio(""),alloingreso(0){};
        friend std::ostream & operator<<(std::ostream &O, Socioclup &x)
        {
              O<<"Nombre del Socio: "<<x.nombresocio<<std::endl;
              O<<"Numero del Socio: "<<x.numero<<std::endl;
              O<<"Domicilio del Socio: "<<x.domiciliosocio<<std::endl;
              O<<"Ano de ingreso del Socio: "<<x.alloingreso<<std::endl;
              return O;
        }
 friend std::istream & operator>>(std::istream &Os, Socioclup &x)
 {
             std::cout<<"  Nombre del Socio: ";
        Os>>x.nombresocio;
        std::cout<<"  Domicilio de Socio: ";
        Os>>x.domiciliosocio;
        std::cout<<"  Numero de Socio: ";
        Os>>x.numero;
        std::cout<<"  Anio de ingreso: ";
        Os>>x.alloingreso;
        return Os;
         }
         int funnumerosocio()
         {
             return numero;
         }

        std::string funnombre()
        {
            return nombresocio;
        }
        std::string  funDomicilio()
        {
             return domiciliosocio;
        }
            void fNombre(std::string nombre){
        nombresocio = nombre;
    }
    void fDomicilio(std::string domicilio){
        domiciliosocio = domicilio;
    }

    friend class LSLSE<Socioclup>;
         bool operator ==(Socioclup &a)
         {
             return nombresocio == a.nombresocio && domiciliosocio == a.domiciliosocio && numero == a.numero && alloingreso == a.alloingreso;
         }
        bool operator!= (Socioclup &a){
            return nombresocio != a.nombresocio || domiciliosocio != a.domiciliosocio;
    }


};
template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    T fundata()
    {
        return data;
    }
    node<T> *funsig()
    {
        return sig;
    }
    node():sig(nullptr){};
    friend class LSLSE<T>;
};

template<class T>
class LSLSE{
private:
    node<T>* lista;
public:
    LSLSE():lista(nullptr){};
    bool vacia()const;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
    void imprimir()const;
    node<T>* buscar(T elem)const;
    int tamallo();
};
template<class T>
int LSLSE<T>::tamallo(){
    node<T>* aux=lista;
    int i=0;
   while(aux)
   {
       aux=aux->sig;
       i++;
   }

    return i;
}
template<class T>
node<T>* LSLSE<T>::buscar(T elem)const{
    node<T>* aux=lista;
    while(aux && aux->data != elem){
        aux = aux->sig;
    }
    return aux;
}


template<class T>
void LSLSE<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=nullptr){
         std::cout<<"\n-> "<<aux->data;
        aux=aux->sig;
    }
}

template<class T>
bool LSLSE<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void LSLSE<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template<class T>
node<T>* LSLSE<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* LSLSE<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* LSLSE<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool LSLSE<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

int main()
{
    int menu;
    LSLSE<Socioclup> milista;
    node<Socioclup>*pos=nullptr;
    node<Socioclup>*pos1=nullptr;
    Socioclup elem;
    int con=0;
    bool ban=true;
    bool ban1=true;
    std::string nombre;
    std::string domicilio;
    do
    {
        std::cout<<"Opciones:"<<std::endl;
        std::cout<<"1.Registro nuevo socio:"<<std::endl;
        std::cout<<"2.Baja a un socio:"<<std::endl;
        std::cout<<"3.Datos de los socios:"<<std::endl;
        std::cout<<"4.Buscar socio:"<<std::endl;
        std::cout<<"5.Numero se socios:"<<std::endl;
        std::cout<<"6.Salir:"<<std::endl;
        std::cout<<"Elige uno opcion:";
        std::cin>>menu;
        switch(menu)
        {
        case 1:
            std::cout<<"Datos del socio"<<std::endl;
            std::cin>>elem;
            pos=milista.primero();
             while(pos && ban){
                    if(pos->fundata().funnumerosocio() == elem.funnumerosocio())
                        ban = false;
                    pos = pos->funsig();
                }
                if(ban){
                    milista.insertar(pos, elem);
                    std::cout<<"registrado"<<std::endl;
                }
                else
                {
                    std::cout<<"Ya hay un socio con este numero"<<std::endl;
                }
                ban=true;
            break;
        case 2:
            pos1=milista.primero();
            std::cout<<"Datos del socio a eliminar"<<std::endl;
            std::cin>>elem;
            while(pos1 && pos1->fundata() != elem){
                    pos1 = pos1->funsig();}
                    if(milista.eliminar(pos1))
                    {
                        std::cout<<"Dato eliminado"<<std::endl;
                    }
                    else
                    {
                    std::cout<<"Dato no encontrado"<<std::endl;
                    }

            break;
        case 3:
            if(milista.vacia())
            {
                std::cout<<"Lista vacia"<<std::endl;
            }else
            {
            milista.imprimir();
            }
            break;
        case 4:
            std::cout<<"Datos a buscar del socio"<<std::endl;
            std::cout<<"Nombre"<<std::endl;
            std::cin>>nombre; elem.fNombre(nombre);
            std::cout<<"Domicilio"<<std::endl;
            std::cin>>domicilio; elem.fDomicilio(domicilio);
            if(milista.buscar(elem)){
                    elem = milista.buscar(elem)->fundata();
                    std::cout<<"Los datos del socio son:"<<std::endl<<elem;
                }
                else
                    std::cout<<"No se encontro el socio"<<std::endl;

            break;
        case 5:
            if(milista.vacia())
            {
                std::cout<<"Lista vacia"<<std::endl;
            }else
            {
                std::cout<<"Numero de socios:";
            std::cout<<milista.tamallo()<<std::endl;
            }

            break;

        }
    }
    while(menu!=6);
}
