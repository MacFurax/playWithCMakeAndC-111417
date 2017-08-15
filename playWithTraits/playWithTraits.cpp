#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

template<typename TypeInt>
class DoSomethingWithInt{
public:
    using value_type = TypeInt;
    static_assert(is_integral<TypeInt>(), "Sorry, I only take Integral type as parameter.");

    DoSomethingWithInt( TypeInt init ): value(init) {}

private:
    TypeInt value;

};


int main()
{

    DoSomethingWithInt<int> dswi1(14);
    DoSomethingWithInt<float> dswi2(12.135); // should failed at compile time 

    return 0;
}