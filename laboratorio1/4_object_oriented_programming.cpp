#include <iostream>

using namespace std;

// Class CVector definition
class CVector
{
    private:
        int *m_pVect,                   // Pointer to the buffer
        m_nCount,                       // Control how many elements are actually used
        m_nMax,                         // Control how many are allocated as maximum
        m_nDelta;                       // To control the growing
        void Init(int delta);           // Init our private variables, etc
        void Resize();                  // Resize the vector when occurs an overflow
    public:
        CVector(int delta = 10);        // Constructor
        ~CVector();                     // Destructor
        void Insert(int elem);          // Insert a new element
        int getCount() const;           // Return the number of elements used
        int* getVect();                 // Return the pointer to the buffer
};

CVector::CVector(int delta){
    Init(delta);
}

CVector::~CVector(){
    delete[] m_pVect;                   // Delete the buffer
}

void CVector::Init(int delta){
    this->m_pVect = nullptr;            // Pointer to the buffer
    this->m_nCount = 0;                 // Control how many elements are actually used
    this->m_nMax = 0;                   // Control how many are allocated as maximum
    this->m_nDelta = delta;             // To control the growing
}

void CVector::Resize(){
    this->m_pVect = (int*)realloc(this->m_pVect, sizeof(int) * (this->m_nMax + this->m_nDelta));
    this->m_nMax += this->m_nDelta;     // The Max has to be increased by delta
}

void CVector::Insert(int elem){
    if( m_nCount == m_nMax )            // Verify the overflow
        Resize();                       // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem;         // Insert the element at the end
}

int CVector::getCount() const {
    return this->m_nCount;
}

int* CVector::getVect(){
    return this->m_pVect;
}

int main()
{
    CVector *v = new CVector;
    for (int i = 0; i < 10; i++) v->Insert(i);
    for (int i = 0; i < v->getCount(); i++) cout << v->getVect()[i] << " ";
    return 0;
}
