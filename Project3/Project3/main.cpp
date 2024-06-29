#include <iostream>
#include <vector>
#include <memory>
#include "Std_unique_ptr.h"

class node
{
public:
    int m_value;
    node(int value) : m_value{ value }
    {}
    ~node()
    { 
        std::cout << "node destructor called\n"; 
    }
};

int main()
{
    node* n = new node(1);
    auto ptr1 = Std_unique_ptr<node>(n);
    node* n2 = ptr1.ptr;
    node n3 = ptr1.release();
    node* n4 = ptr1.ptr;

    auto ptr2 = Std_unique_ptr<node>(new node(2));



    return 0;
}