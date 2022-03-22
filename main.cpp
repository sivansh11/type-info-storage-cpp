#include "type.h"


int main()
{
    struct RandomType
    {
        RandomType()
        {
            random_vars[0] = 1;
            random_vars[1] = 2;
            random_vars[2] = 3;
        }
        float random_vars[3];
    };
    Type<RandomType> RandomType_type;

    void* p_data = RandomType_type.allocate();
    RandomType_type.construct(p_data);    

    std::cout << ((RandomType*)p_data)->random_vars[0] << '\n';
    std::cout << ((RandomType*)p_data)->random_vars[1] << '\n';
    std::cout << ((RandomType*)p_data)->random_vars[2] << '\n';

    return 0;
}