#ifndef MODULEARRAY_HPP
#define MODULEARRAY_HPP

#include <string>
#include <array>


namespace s5loo
{
    using str15 = std::array<std::string,15>;
    void fillArray(str15 &array);

    void printArray(const str15 &array);

    bool isPalindrome(std::string word);
} //namespace s5loo

#endif // MODULEARRAY_HPP
