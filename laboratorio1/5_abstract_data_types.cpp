#include <iostream>

using namespace std;

// Class CVector definition
template <typename Type>
class CVector
{
    private:
        Type *m_pVect;                   // Pointer to the buffer
        int m_nCount;                    // Control how many elements are actually used
        int m_nMax;                      // Control how many are allocated as maximum
        int m_nDelta;                    // To control the growing
        void Init(int delta);            // Init our private variables, etc
        void Resize();                   // Resize the vector when occurs an overflow
    public:
        CVector(int delta = 10);         // Constructor
        ~CVector();                      // Destructor
        void Insert(Type &elem);         // Insert a new element
        int getCount() const;            // Return the number of elements used
        Type* getVect();                 // Return the pointer to the buffer
};

template <typename Type>
CVector<Type>::CVector(int delta){
    Init(delta);
}

template <typename Type>
CVector<Type>::~CVector(){
    delete[] m_pVect;                   // Delete the buffer
}

template <typename Type>
void CVector<Type>::Init(int delta){
    this->m_pVect = nullptr;            // Pointer to the buffer
    this->m_nCount = 0;                 // Control how many elements are actually used
    this->m_nMax = 0;                   // Control how many are allocated as maximum
    this->m_nDelta = delta;             // To control the growing
}

template <typename Type>
void CVector<Type>::Resize(){
    this->m_pVect = (int*)realloc(this->m_pVect, sizeof(int) * (this->m_nMax + this->m_nDelta));
    this->m_nMax += this->m_nDelta;     // The Max has to be increased by delta
}

template <typename Type>
void CVector<Type>::Insert(Type &elem){
    if( m_nCount == m_nMax )            // Verify the overflow
        Resize();                       // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem;         // Insert the element at the end
}

template <typename Type>
int CVector<Type>::getCount() const {
    return this->m_nCount;
}

template <typename Type>
Type* CVector<Type>::getVect(){
    return this->m_pVect;
}

int main()
{
    CVector<int> *v = new CVector<int>;
    for (int i = 0; i < 10; i++) v->Insert(i);
    for (int i = 0; i < v->getCount(); i++) cout << v->getVect()[i] << " ";
    return 0;
}
