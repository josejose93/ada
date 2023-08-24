#include <iostream>

using namespace std;

struct Vector
{
    int*m_pVect;                                // Pointer to the buffer
    int m_nCount;                               // Control how many elements are actually used
    int m_nMax;                                 // Control how many are allocated as maximum
    int m_nDelta;                               // To control the growing
};

void Resize(Vector *pThis){
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
    pThis->m_nMax += pThis->m_nDelta;           // The Max has to be increased by delta
}

void Insert(Vector *pThis, int elem){
    if( pThis->m_nCount == pThis->m_nMax )      // Verify the overflow
        Resize(pThis);                          // Resize the vector before inserting elem
    pThis->m_pVect[pThis->m_nCount++] = elem;   // Insert the element at the end of the sequence
}

int main()
{
    Vector *v = new Vector;
    for (int i = 0; i < 10; i++) Insert(v, i);
    for (int i = 0; i < v->m_nCount; i++) cout << v->m_pVect[i] << " ";
    return 0;
}
