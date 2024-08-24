#include <iostream>
using namespace std;

struct Vector
{
    int m_nMax=5; 
    int* m_pVect = new int[m_nMax];  
    int m_nCount=0;
    int m_nDelta=5; 
};
void Resize(Vector* pThis)
{
    int *pTemp, i;
    pTemp = new int[pThis->m_nMax + pThis->m_nDelta]; 
    for(i = 0 ; i < pThis->m_nMax; i++) 
    pTemp[i] = pThis->m_pVect[i]; 
    delete [ ] pThis->m_pVect; 
    pThis->m_pVect = pTemp; 
    pThis->m_nMax += pThis->m_nDelta;
}
void Insert(Vector* pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax) 
        Resize(pThis); 
    pThis->m_pVect[pThis->m_nCount++] = elem;
}
void print(Vector* pThis) {
    for (int* p = pThis->m_pVect;p<pThis->m_pVect + pThis->m_nCount;p++) {
        cout<<*p<<" ";
    }
}

int main()
{
    Vector obj1;
    Insert(&obj1, 1);
    Insert(&obj1, 2);
    Insert(&obj1, 3);
    Insert(&obj1, 4);
    Insert(&obj1, 5);
    Insert(&obj1, 6);
    Insert(&obj1, 7);
    print(&obj1);
}