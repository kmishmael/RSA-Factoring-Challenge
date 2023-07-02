#include <iostream>
#include <cstdint>


extern "C"
{
    void factors(uint64_t v_num)
    {
        uint64_t c;

        if (v_num % 2 == 0)
        {
            std::cout << v_num << "=" << v_num / 2 << "*2\n";
        }
        c = 3;
        while ((c * c) <= v_num)
        {
            if (v_num % c == 0)
            {
                std::cout << v_num << "=" << v_num / c << "*" << c << "\n";
                break;
            }
            c += 2;
        }
    }
}
