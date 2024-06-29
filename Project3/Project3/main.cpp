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
    auto ptr2 = Std_unique_ptr<node>(new node(2));

    node n2 = *ptr1;
    node* released_n = ptr1.release();
    return 0;
}