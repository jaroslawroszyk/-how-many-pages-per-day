#pragma once
#include <fstream>


enum class ProgramMode
{
    p_PagesDay = 1,
    p_Sum = 2 ,
    p_Show = 3,
    p_ShowTheConent = 4,
    p_delete = 5,
    p_Calculate = 6,
    p_exit = 7,
};
 
std::istream &operator>>(std::istream &in, ProgramMode &enter);