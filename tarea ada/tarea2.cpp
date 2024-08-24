#include <iostream>
using namespace std;
class CVector
{
private:
int* m_pVect,
m_nCount, 
m_nMax, 
m_nDelta;
void Init(int delta); 
void Resize();
public:
CVector() {
m_nMax = 5; 
m_pVect = new int[m_nMax];  
m_nCount = 0; 
m_nDelta = 5; 
}
void Insert(int elem); 
void print();
};
void CVector::Insert(int elem)
{
if (m_nCount == m_nMax) 
Resize(); 
m_pVect[m_nCount++] = elem; 
}
void CVector::print() {
for (int* p =  m_pVect; p <  m_pVect +  m_nCount; p++) {
cout << *p << " ";
}
}
void CVector::Resize()
{
int* pTemp, i;
pTemp = new int[m_nMax + m_nDelta]; 
for (i = 0; i < m_nMax; i++) 
pTemp[i] = m_pVect[i]; 
delete[] m_pVect; 
m_pVect = pTemp; 
m_nMax += m_nDelta;
}
int main() {
CVector obj1;
obj1.Insert(1);
obj1.Insert(2);
obj1.Insert(3);
obj1.Insert(4);
obj1.Insert(5);
obj1.Insert(6);
obj1.print();
}