#include <iostream>
#include <string>
#include <type_traits>

template<typename TypeInt>
class DoSomethingWithInt{
public:
    using value_type = typename TypeInt;
    static_assert(is_integral<TypeInt>(), "Soory, I only take Integral type as parameter.");

    DoSomethingWithInt( TypeInt init ): value(init) {}

private:
    TypeInt value;

};


int main()
{

    

    return 0;
}