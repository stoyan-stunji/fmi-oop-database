#ifndef RUN_H
#define RUN_H

#include "examples.h"
#include "menu.h"

long long help_counter = 0;

void run()
{
    generate_examples();
    
    menu m;
    std::string input;
    std::cout << "PROJECT [7] DATABASE\n";
    m.open();

    while(true)
    {
        if(input == "open")
        {
            m.open();
        }
        else if(input == "save")
        {
            m.save();
        }
        else if(input == "save_as")
        {
            m.save_as();
        }
        else if(input == "exit")
        {
            m.exit();
            break;
        }
        else if(input == "close")
        {
            m.close();
            std::cout << ">> open\n";
            m.open();
        }
        else if(input == "help")
        {
            m.help();
        }
        else if(input == "import")
        {
            m.import();
        }
        else if(input == "showtables")
        {
            m.showtables();
        }
        else if(input == "describe")
        {
            m.describe();
        }
        else if(input == "print")
        {
            m.print();
        }
        else if (input == "export")
        {
            m.xport();
        }
        else if(input == "select")
        {
            m.select();
        }
        else if(input == "select_onto")
        {
            m.select_onto();
        }
        else if(input == "add_column")
        {
            m.add_column();
        }
        else if(input == "update")
        {
            m.update();
        }
        else if(input == "delete")
        {
            m.remove();
        }
        else if(input == "insert")
        {
            m.insert();
        }
        else if(input == "credits")
        {
            m.credits();
        }
        else
        {
            ++help_counter;
        }
        
        std::cout << ">> ";
        std::cin >> input;

        if(help_counter % 5 == 0)
        {
            m.help();
            help_counter = 0;
        }
    }
    std::cout << "[+] [closed SUCCESSFULLY out of the system]\n";
}

#endif