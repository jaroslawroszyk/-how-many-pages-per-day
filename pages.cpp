#include "pages.h"
#include <fstream>

std::istream &operator>>(std::istream &in, Pages &enter)
{
    int int_entry;
    enter = (in >> int_entry) ? static_cast<Pages>(int_entry) : Pages::p_exit;
    return in;
}

HowManyPages SaveToFile(HowManyPages savedate)
{
    HowManyPages t;
    std::ofstream save;
    save.open("dane.txt", std::ios::app);
    if (save.good())
    {
        save << "Date: " << savedate.date << ", number of pages: " << savedate.pages << '\n';
        std::cout << "Wrote!\n";
    }

    save.close();
    return t;
}

HowManyPages enterdata()
{
    HowManyPages p;
    std::cout << "enter the day: ";
    std::cin >> p.date;
    std::cout << "how many pages: ";
    std::cin >> p.pages;
    // show(p);
    SaveToFile(p);
    return p;
}

void sum(HowManyPages p)
{
    std::string line;
    std::cout << "sum all pages \n";
    std::ifstream outFile;
    outFile.open("dane.txt", std::ios::app);
    if (outFile.is_open())
    {
        while (getline(outFile, line))
        {
            for(auto i : line)
            {
                p.sum += p.pages;
                
            }
            // std::cout << line << "\n";
            
        }
        
        outFile.close();
    }
    else
    {
        std::cout << "Unable to open file! \n";
    }
}

void menu()
{
    Pages enter;
    do
    {
        std::cout << "[1] Enter day and number of pages (automatic save)\n";
        std::cout << "[2] Sum all day \n";
        std::cout << "[3] Exit \n";
        std::cout << "Choose: ";
        std::cin >> enter;
        switch (enter)
        {
        case Pages::p_PagesDay:
        {
            system("clear");
            enterdata();
            break;
        }
        case Pages::p_Sum:
        {
            HowManyPages sume;
            system("clear");
            sum(sume);
            break;
        }
        case Pages::p_exit:
        {
            std::cout << "See you tomorrow \n";
            break;
        }
        }
    } while (enter != Pages::p_exit);
}

// void EnterData()
// {
//     HowManyPages test;

//     std::cout << "enter the day: ";
//     std::cin >> test.date;
//     std::cout << "how many pages: ";
//     std::cin >> test.pages;
// }

// void show(HowManyPages show)
// {
//     std::cout<< show.date << " " << show.pages << "\n";
// }