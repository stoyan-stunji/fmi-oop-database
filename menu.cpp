#include "menu.h"

void menu::open()
{
    std::cout << ">> ";

    int flag = this->menu_commands.open_commands();

    if(flag == RETURN_ZERO)
    {
        std::cout << "[-] [database NOT loaded]\n";
    }
    else if(flag == RETURN_ONE)
    {
        std::cout << "[+] [database loaded]\n";
    }
}

void menu::save()
{
    this->menu_commands.save_commands();
    std::cout << "[+] [saved changes]\n"; 
}

void menu::save_as()
{
    std::cout << "[>] [path]\n";
    std::cout << ">> ";
    std::string path;
    std::cin >> path;

    std::cout << "[>] [table_name]\n";
    std::cout << ">> ";
    std::string table_name;
    std::cin >> table_name;

    int flag = this->menu_commands.save_as_commands(path, table_name);

    if(flag == RETURN_ZERO)
    {
        std::cout << "[-] [table NOT found]\n";
    }
    else if(flag == RETURN_ONE)
    {
        std::cout << "[+] [saved changes at specified path]\n"; 
    }
    else if(flag == RETURN_TWO)
    {
        std::cout << "[-] [incorrect table CANNOT be accessed]\n";
    }
}

void menu::exit()
{
    std::string input;
    std::cout << "[?] [save] [yes|no]\n";
    std::cout << ">> ";
    std::cin >> input;

    while(input != "yes" || input != "no")
    {
        if(input == "yes")
        {
            this->menu_commands.save_commands();
            std::cout << "[+] [changes saved]\n";
            break;
        }
        else if(input == "no")
        {
            std::cout << "[-] [changes NOT saved]\n";
            break;
        }
        std::cout << "[?] [save] [yes|no]\n";
        std::cout << ">> ";
        std::cin >> input;
    }        
}

void menu::close()
{
    this->menu_commands.save_commands();
}

void menu::help()
{
    std::cout << "[01] open [catalog_name] || opens the program;\n";
    std::cout << "[02] save || saves the changes;\n";
    std::cout << "[03] save as || saves changes by path;\n";
    std::cout << "[04] exit || closes the program, asks to save;\n";
    std::cout << "[05] close || closes the program, automatically saves;\n";
    std::cout << "[06] help || shows the functions of the system;\n";
    std::cout << "[07] import [table_name] || adds a table to the database;\n";
    std::cout << "[08] showtables || shows a list with the names of the tables;\n";
    std::cout << "[09] describe [table_name] || shows the types of columns in the table;\n";
    std::cout << "[10] print [table_name] || shows the table data by pages;\n";
    std::cout << "[11] export [new_name] [table_name] || exports table as .txt;\n";
    std::cout << "[12] select [column_n] [value] [table_name] || shows all rows of the table with the value by pages;\n";
    std::cout << "[13] select_onto [result_table_name] [column_indexes] [column_n] [value] [table_name]\n";
    std::cout << "[14] add_column [table_name] [column_name] [column_type] || adds a column\n";
    std::cout << "[15] update [table_name] [search_column_n] [search_value] [target_column_n] [target_value]\n";
    std::cout << "[16] delete [table_name] [search_column_n] [search_value]\n";
    std::cout << "[17] insert [table_name] [column_1, column_2 ... column_n]\n";
    std::cout << "[18] credits || shows infomation about the author\n\n";
    std::cout << "[+] || successful action\n";
    std::cout << "[-] || unsuccessful action\n";
    std::cout << "[>] || waiting for user's input\n";
    std::cout << "[?] || system question\n";
    std::cout << '\n';
}

void menu::import()
{
    std::cout << "[>] [file_name]\n";
    std::cout << ">> ";
    std::string file_name;
    std::cin >> file_name;

    int flag = this->menu_commands.import_commands(file_name);

    if(flag == RETURN_ZERO)
    {
        std::cout << "[-] [table ALREADY in system]\n";
    }
    else if(flag == RETURN_ONE)
    {
        std::cout << "[+] [table ADDED to the system]\n";
    }
    else if(flag == RETURN_TWO)
    {
        std::cout << "[-] [an INCORRECT table added]\n";
    }
}

void menu::showtables()
{
    std::vector<std::string> names = this->menu_commands.showtables_commands();
    for (std::size_t i = 0; i < names.size(); ++i)
    {
        std::cout << names[i] << '\n';
    }
}

void menu::describe()
{
    std::cout << "[>] [table_name]\n";
    std::cout << ">> ";
    std::string table_name;
    std::cin >> table_name;

    primitive_pair<int, std::string> flag = this->menu_commands.describe_commands(table_name);

    if(flag.first == RETURN_ZERO)
    {
        std::cout << "[-] [table NOT found]\n";
    }
    else if(flag.first == RETURN_ONE)
    {
        std::cout << flag.second << '\n';
    }
    else if(flag.first == RETURN_TWO)
    {
        std::cout << "[-] [incorrect table CANNOT be accessed]\n";
    }
}

void menu::print()
{
    std::cout << "[>] [table_name]\n";
    std::cout << ">> ";
    std::string table_name;
    std::cin >> table_name;

    int flag = this->menu_commands.io_print_commands(table_name);

    if(flag == RETURN_ZERO)
    {
        std::cout << "[-] [table NOT found]\n";
    }
    else if(flag == RETURN_TWO)
    {
        std::cout << "[-] [incorrect table CANNOT be accessed]\n";
    }
    else if(flag == RETURN_ONE)
    {
        std::cout << "[+] [printed]\n";
    }
}

void menu::xport()
{
    std::cout << "[>] [table_name]\n";
    std::cout << ">> ";
    std::string table_name;
    std::cin >> table_name;

    std::cout << "[>] [new_name]\n";
    std::cout << ">> ";
    std::string new_name;
    std::cin >> new_name;

    int flag = this->menu_commands.export_commands(table_name, new_name);

    if(flag == RETURN_ZERO)
    {
        std::cout << "[-] [table NOT found]\n";
    }
    else if(flag == RETURN_ONE)
    {
        std::cout << "[+] [table SUCCESFULLY exported]\n";
    }
    else if(flag == RETURN_TWO)
    {
        std::cout << "[-] [incorrect table CANNOT be accessed]\n"; 
    }
}

void menu::select()
{
    std::cout << "[>] [column_n]\n";
    std::cout << ">> ";
    std::string column_n_str;
    std::cin >> column_n_str;

    int column_n = 0;
    try
    {
        column_n = std::stoi(column_n_str);
    }
    catch(const std::exception& e)
    {
        std::cout << "[-] [argument NOT valid for column_n]\n";
        return;
    }

    std::cout << "[>] [search_value]\n";
    std::cout << ">> ";
    std::string search_value;
    std::cin >> search_value;

    std::cout << "[>] [table_name]\n";
    std::cout << ">> ";
    std::string table_name;
    std::cin >> table_name;

    int flag = this->menu_commands.select_commands(column_n, search_value, table_name);

    if(flag == RETURN_ZERO)
    {
        std::cout << "[-] [table NOT found]\n";
    }
    else if(flag == RETURN_ONE)
    {
        std::cout << "[-] [column NOT valid]\n";
    }
    else if(flag == RETURN_TWO)
    {
        std::cout << "[-] [such value at such position NOT in table]\n";
    }
    else if(flag == RETURN_FOUR)
    {
        std::cout << "[-] [incorrect table CANNOT be accessed]\n"; 
    }
    else if(flag == RETURN_THREE)
    {
        std::cout << "[+] [printed]\n";
    }
}

void menu::select_onto()
{
    std::cout << "[>] [result_table]\n";
    std::cout << ">> ";
    std::string result_table_name;
    std::cin >> result_table_name;

    while (std::cin.get() != '\n');

    std::cout << "[>] [columns_1, columns_2 ... columns_n]\n";
    std::cout << ">> ";
    std::string columns;
    std::getline(std::cin, columns);

    std::vector<int> column_numbers;
    for (std::size_t i = 0; i < columns.size(); ++i) 
    {
        if (std::isdigit(columns[i])) 
        {
            column_numbers.push_back(columns[i] - '0');
        }
    } 

    std::cout << "[>] [column_n]\n";
    std::cout << ">> ";
    std::string column_n_str;
    std::cin >> column_n_str;

    int column_n = 0;
    try
    {
        column_n = std::stoi(column_n_str);
    }
    catch(const std::exception& e)
    {
        std::cout << "[-] [argument NOT valid for column_n]\n";
        return;
    }

    std::cout << "[>] [value]\n";
    std::cout << ">> ";
    std::string value;
    std::cin >> value;
         
    std::cout << "[>] [table_name]\n";
    std::cout << ">> ";
    std::string table_name;
    std::cin >> table_name;

    int flag = this->menu_commands.select_onto_commands(result_table_name, column_numbers, column_n, value, table_name);

    if(flag == RETURN_ZERO)
    {
        std::cout << "[-] [table NOT found]\n";
    }
    else if(flag == RETURN_ONE)
    {
        std::cout << "[-] [a column NOT valid]\n";
    }
    else if(flag == RETURN_TWO)
    {
        std::cout << "[-] [column NOT valid]\n";
    }
    else if(flag == RETURN_THREE)
    {
        std::cout << "[-] [such value at such position NOT found]\n";
    }
    else if(flag == RETURN_FOUR)
    {
        std::cout << "[+] [new file SUCCESSFULLY created]\n";
    }
    else if(flag == RETURN_FIVE)
    {
        std::cout << "[-] [incorrect table CANNOT be accessed]\n"; 
    }
}

void menu::add_column()
{
    std::cout << "[>] [table_name]\n";
    std::cout << ">> ";
    std::string table_name;
    std::cin >> table_name;

    std::cout << "[>] [column_name]\n";
    std::cout << ">> ";
    std::string column_name;
    std::cin >> column_name;

    std::cout << "[>] [column_type]\n";
    std::cout << ">> ";
    char column_type = 'c';
    std::cin >> column_type;

    int flag = this->menu_commands.add_column_commands(table_name, column_name, column_type);

    if(flag == RETURN_ZERO)
    {
        std::cout << "[-] [table NOT found]\n";
    }
    else if(flag == RETURN_ONE)
    {
        std::cout << "[+] [column ADDED to the table]\n";
    }
    else if(flag == RETURN_TWO)
    {
        std::cout << "[-] [type NOT valid]\n";
    }
    else if(flag == RETURN_THREE)
    {
        std::cout << "[-] [incorrect table CANNOT be accessed]\n"; 
    }
}

void menu::update()
{
    std::cout << "[>] [table_name]\n";
    std::cout << ">> ";
    std::string table_name;
    std::cin >> table_name;

    std::cout << "[>] [search_column]\n";
    std::cout << ">> ";
    std::string search_column_str;
    std::cin >> search_column_str;

    int search_column = 0;
    try
    {
        search_column = std::stoi(search_column_str);
    }
    catch(const std::exception& e)
    {
        std::cout << "[-] [argument NOT valid for search_column]\n";
        return;
    }

    std::cout << "[>] [search_value]\n";
    std::cout << ">> ";
    std::string search_value;
    std::cin >> search_value;

    std::cout << "[>] [target_column]\n";
    std::cout << ">> ";
    std::string target_column_str;
    std::cin >> target_column_str;

    int target_column = 0;
    try
    {
        target_column = std::stoi(target_column_str);
    }
    catch(const std::exception& e)
    {
        std::cout << "[-] [argument NOT valid for target_column]\n";
        return;
    }

    std::cout << "[>] [target_value]\n";
    std::cout << ">> ";
    std::string target_value;
    std::cin >> target_value;

    primitive_pair<int, std::string> flag = this->menu_commands.update_commands(table_name, search_column, search_value, target_column, target_value);

    if(flag.first == RETURN_ZERO)
    {
        std::cout << "[-] [table NOT found]\n";
    }
    else if(flag.first == RETURN_ONE)
    {
        std::cout << "[-] [column NOT valid]\n";
    }
    else if(flag.first == RETURN_TWO)
    {
        std::cout << "[-] [such value at such position NOT in table]\n";
    }
    else if(flag.first == RETURN_THREE)
    {
        std::cout << "[-] [column NOT valid]\n";
    }
    else if(flag.first == RETURN_FOUR)
    {
        std::cout << "[+] [table SUCCESSFULLY updated]\n";
    }
    else if(flag.first == RETURN_FIVE)
    {
        std::cout << flag.second;
    }
    else if(flag.first == RETURN_SIX)
    {
        std::cout << "[-] [incorrect table CANNOT be accessed]\n"; 
    }
}

void menu::remove()
{
    std::cout << "[>] [table_name]\n";
    std::string table_name;
    std::cout << ">> ";
    std::cin >> table_name;

    std::cout << "[>] [search_column]\n";
    std::cout << ">> ";
    std::string search_column_str;
    std::cin >> search_column_str;

    int search_column = 0;
    try
    {
        search_column = std::stoi(search_column_str);
    }
    catch(const std::exception& e)
    {
        std::cout << "[-] [argument NOT valid for search_column]\n";
        return;
    }

    std::cout << "[>] [search_value]\n";
    std::string search_value;
    std::cout << ">> ";
    std::cin >> search_value;

    int flag = this->menu_commands.delete_commands(table_name, search_column, search_value);

    if(flag == RETURN_ZERO)
    {
        std::cout << "[-] [table NOT found]\n";
    }
    else if(flag == RETURN_ONE)
    {
        std::cout << "[-] [column NOT valid]\n";
    }
    else if(flag == RETURN_TWO)
    {
        std::cout << "[+] [deleted SUCCESSFULLY infomation]\n";
    }
    else if(flag == RETURN_THREE)
    {
        std::cout << "[-] [incorrect table CANNOT be accessed]\n"; 
    }
    else if(flag == RETURN_FOUR)
    {
        std::cout << "[-] [such value at such position NOT in table]\n";
    }
}

void menu::insert()
{
    std::cout << "[>] [table_name]\n";
    std::string table_name;
    std::cout << ">> ";
    std::cin >> table_name;

    while (std::cin.get() != '\n');

    std::cout << "[>] [columns_1, columns_2 ... columns_n]\n";
    std::cout << ">> ";
    std::string columns_n;
    std::getline(std::cin, columns_n);

    std::vector<int> columns;
    for (std::size_t i = 0; i < columns_n.size(); ++i) 
    {
        if (std::isdigit(columns_n[i])) 
        {
            columns.push_back(columns_n[i] - '0');
        }
    }

    primitive_pair<int, std::string> flag = this->menu_commands.insert_commands(table_name, columns);

    if(flag.first == RETURN_ZERO)
    {
        std::cout << "[-] [table NOT found]\n";
    }
    else if(flag.first == RETURN_ONE)
    {
        std::cout << "[-] [a column NOT valid]\n";
    }
    else if(flag.first == RETURN_TWO)
    {
        std::cout << "[+] [information SUCCESSFULLY inserted]\n";
    }
    else if(flag.first == RETURN_FOUR)
    {
        std::cout << flag.second;
    }
    else if(flag.first == RETURN_SIX)
    {
        std::cout << "[-] [incorrect table CANNOT be accessed]\n"; 
    }
    else if(flag.first == RETURN_SEVEN)
    {
        std::cout << "[-] [there CANNOT be duplicate column numbers]\n";
    }
}

void menu::credits()
{
    std::cout << "[+] [Stoyan_Ivanov][9MI0400132][Informatics][II]\n";
}