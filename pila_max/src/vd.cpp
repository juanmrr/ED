template <class T>
void VD<T>::Redimensionar(int nueva_dim){
    T * aux = new T[nueva_dim];
    int minimo = (nueva_dim<n)? nueva_dim : n;
    for (int i=0;i<minimo; i++)
        aux[i]= datos[i];
    reservados = nueva_dim;
    n = minimo;
    delete []datos;
    datos = aux;
}

/***************************************************/
template <class T>
void VD<T>::Copia(const VD<T> & I){
 reservados = I.reservados;
  datos = new T[reservados];
  n=I.n;
  for (int i=0;i<n;i++)
    datos[i]= I.datos[i];
}  


/***************************************************/
template <class T>
VD<T>::VD(int tam){
  reservados = tam;
  datos = new T[reservados];
  n=0;
}
/***************************************************/
template <class T>
VD<T>::VD(const VD<T> & V){
  Copia(V);
}
/***************************************************/
template <class T>
VD<T>::~VD(){
 if (datos!=0)
  delete[]datos;
} 
/***************************************************/
template <class T>
VD<T> & VD<T>::operator=(const VD<T> & I){

if (this !=&I){
    delete []datos;
    Copia(I);
  }
  return *this;
}  

/***************************************************/
template <class T>
T VD<T>::Get(int pos)const{
  assert(pos>=0 && pos<n);
  return datos[pos];
}  
/***************************************************/
template <class T>
const T & VD<T>::operator[](int pos)const{
  assert(pos>=0 && pos<n);
  return datos[pos];
}  

/***************************************************/
template <class T>
T & VD<T>::operator[](int pos){
  assert(pos>=0 && pos<n);
  return datos[pos];
}  

/***************************************************/
template <class T>
void VD<T>::Borrar(int pos){
    assert(pos>=0 && pos<n);
    for (int i=pos+1;i<n;i++)
      datos[i-1]=datos[i];
    n--;
    if (reservados/4>=n) Redimensionar(reservados/2);
}    
/***************************************************/
template <class T>
void VD<T>::Insertar(const T &nuevo,int pos){
    assert(pos>=0 && pos<=n);//podemos inserarlo por el final
    if (reservados==n) Redimensionar(reservados*2);
    for (int i=n;i>pos;i--)
      datos[i]=datos[i-1];
    datos[pos]=nuevo;  
    n++;
}    
    
    
