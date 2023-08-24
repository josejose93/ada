#include <iostream>

using namespace std;

int gVect[100];                     // Buffer to save the elements
int gnCount;                        // Counter to know the number of elements used

void Insert(int elem){
    if( gnCount < 100 )             // we can only insert if there is space
        gVect[gnCount++] = elem;    // Insert the element at the end
}

int main()
{
    for (int i = 0; i < 10; i++) Insert(i);
    for (int i = 0; i < gnCount; i++) cout << gVect[i] << " ";
    return 0;
}
