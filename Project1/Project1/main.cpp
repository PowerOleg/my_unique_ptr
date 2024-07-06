#include <iostream>
#include <vector>
#include <memory>

void print(const std::vector<double>& vec)
{
    for (auto& value : vec)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {
        std::cout << "constructor called\n";
        print(upper);
        print(middle);
        print(down);

    };
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    std::unique_ptr<tridiagonal_matrix> clone()
    {
        //auto unique_ptr = std::make_unique<tridiagonal_matrix>(*this);
        tridiagonal_matrix* matrix_new = new tridiagonal_matrix(this->m_down, this->m_upper, this->m_middle);
        //auto unique = std::make_unique<tridiagonal_matrix>(matrix_new);//такой вариант не работает
        std::unique_ptr<tridiagonal_matrix> unique(matrix_new);
        return unique;
    }
};

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone();
    matrix_clone->m_upper.clear();
    std::cout << "Cleared\n";
    std::cout << "matrix_clone\n";  
    print(matrix_clone->m_upper);
    std::cout << "matrix\n";
    print(matrix->m_upper);

    return 0;
}

