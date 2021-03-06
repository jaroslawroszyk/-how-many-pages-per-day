#include "Functionality.h"
#include "ProgramMode.h"
#include "BookStatistic.h"
#include <iostream>
#include <filesystem>

int calc()
{
    int startingPage = 0;
    int endPage = 0;
    int calculate = 0;
    std::cout << "Enter the starting page: ";
    std::cin >> startingPage;
    std::cout << "Enter the last page you read today: ";
    std::cin >> endPage;
    calculate = endPage - startingPage;
    std::cout << "you have read: ";
    return calculate;
}

void showFilesTxt()
{
    for (auto &de : std::filesystem::directory_iterator("."))
    {
        if (de.is_regular_file() && de.path().string().ends_with(".txt"))
        {
            // std::cout << de << '\n';     // or `de.path().string()
            std::cout << de.path().filename() << '\n';
        }
    }
    //vesrion with dir if u want use that u must include:
    // #include <dirent.h>
    // #include <stdio.h>
    // #include <string.h>
    // DIR *d;
    // char *p1, *p2;
    // int ret;
    // struct dirent *dir;
    // d = opendir(".");
    // if (d)
    // {
    //     while ((dir = readdir(d)) != NULL)
    //     {
    //         p1 = strtok(dir->d_name, ".");
    //         p2 = strtok(NULL, ".");
    //         if (p2 != NULL)
    //         {
    //             ret = strcmp(p2, "txt");
    //             if (ret == 0)
    //             {
    //                 std::cout << p1 << "\n";
    //             }
    //         }
    //     }
    //     closedir(d);
    // }
}

void deleteFile()
{
    std::string NameFile;
    std::cout << "Enter the name of the file you want to delete(without extension .txt): " << std::endl;

    std::cin >> NameFile;
    NameFile += ".txt";
    try
    {
        if (std::filesystem::remove(NameFile))
        {
            std::cout << "File " << NameFile << " deleted.\n";
        }
        else
        {
            std::cout << "file " << NameFile << " not found.\n";
        }
    }
    catch (const std::filesystem::filesystem_error &err)
    {
        std::cout << " filesystem error: " << err.what() << "\n";
    }
}

void showContent()
{
    std::string nameFile;
    std::cout << "Enter the name of the file you want to see the contents(without extension): ";
    std::cin >> nameFile;
    nameFile += ".txt";
    std::ifstream Content(nameFile);
    if(Content.is_open())
    {
        std::cout << Content.rdbuf();
    }
    Content.close();
}

void menu()
{
    ProgramMode enter;
    do
    {
        std::cout << "[1] Enter day and number of pages next enter book's title (automatic save)\n";
        std::cout << "[2] Add up the number of pages from a given book \n";
        std::cout << "[3] Show available files \n";
        std::cout << "[4] Show the contents of the file \n";
        std::cout << "[5] Delete file\n";
        std::cout << "[6] Count how many pages you have read \n";
        std::cout << "[7] Exit \n";
        std::cout << "Choose: ";
        std::cin >> enter;
        BookStatistic p;
        switch (enter)
        {
        case ProgramMode::p_PagesDay:
        {
            std::system("clear");
            std::cout << "Available files: " << std::endl;
            showFilesTxt();
            std::cout << std::endl
                      << std::endl;
            p.enterdata();
            break;
        }
        case ProgramMode::p_Sum:
        {
            std::system("clear");
            std::cout << "Available files: " << std::endl;
            showFilesTxt();
            std::cout << std::endl;
            p.sum();
            break;
        }
        case ProgramMode::p_Show:
        {
            std::system("clear");
            std::cout << "Available files: " << std::endl;
            showFilesTxt();
            std::cout << std::endl;
            break;
        }
        case ProgramMode::p_ShowTheConent:
        {
            std::system("clear");
            std::cout << "Available files: " << std::endl;
            showFilesTxt();
            std::cout << std::endl;
            showContent();
            break;
        }
        case ProgramMode::p_delete:
        {
            std::system("clear");
            std::cout << "Available files: " << std::endl;
            showFilesTxt();
            std::cout << std::endl;
            deleteFile();
            break;
        }
        case ProgramMode::p_Calculate:
        {
            std::system("clear");
            std::cout << calc() << " pages\n";
            break;
        }
        case ProgramMode::p_exit:
        {
            std::cout << "See you tomorrow \n";
            break;
        }
        default:
        {
            std::system("clear");
            std::cout << "nope \n";
            break;
        }
        }
    } while (enter != ProgramMode::p_exit);
}
