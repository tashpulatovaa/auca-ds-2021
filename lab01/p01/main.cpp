#include <iostream>

int main()
{
    #ifdef AUCA_DEBUG
    std::cout << "Author: Aikokul Tashpulatova " << std::endl;
    #endif
    std::cout << "Hello, " << __cplusplus << "!!!\n";
}
