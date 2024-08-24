#include <iostream>
using namespace std;

template <typename Type>
class CVector
{
private:
Type* m_pVect; 
int m_nCount; 
int m_nMax; 
int m_nDelta; 
void Resize(); 
public:
CVector() {
m_nMax = 5; 
m_pVect = new Type[m_nMax];  
m_nCount = 0; 
m_nDelta = 5; 
}
void Insert(Type elem); 
void print();
};
template <typename Type>
void CVector<Type>::Insert(Type elem)

{
if (m_nCount == m_nMax) 
Resize(); 
m_pVect[m_nCount++] = elem; 
}
template <typename Type>
void CVector<Type>::print() {
for (Type* p = m_pVect; p < m_pVect + m_nCount; p++) {
cout << *p << " ";
}
}
template <typename Type>
void CVector<Type>::Resize()
{
Type* pTemp;

pTemp = new Type[m_nMax + m_nDelta];
for (int i = 0; i < m_nMax; i++)
pTemp[i] = m_pVect[i]; 
delete[] m_pVect; 
m_pVect = pTemp;
m_nMax += m_nDelta;
}
int main() {
CVector <int>obj1;
obj1.Insert(1);
obj1.Insert(2);
obj1.Insert(3);
obj1.Insert(4);
obj1.Insert(5);
obj1.print();
CVector <char>obj2;
obj2.Insert('a');
obj2.Insert('b');
obj2.Insert('c');
obj2.Insert('d');
obj2.Insert('e');
obj2.print();
}
