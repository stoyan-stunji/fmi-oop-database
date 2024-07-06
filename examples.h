#ifndef EXAMPLES_H
#define EXAMPLES_H

#include "database.h"

void generate_first_table()
{
    std::vector<std::string> strs = {"Iron_Maiden", "Judas_Priest", "Deep_Purple"};
    column* first = new column_string();
    column_string* first_column = dynamic_cast<column_string*>(first);
    first_column->set_content(strs);
    std::vector<bool> bool_1 = {1, 1, 1};
    first_column->set_boolen(bool_1);
    std::string name_1 = "bands";
    first_column->set_name(name_1);
    
    std::vector<int> ints = {180, 120, 150};
    column* second = new column_int();
    column_int* second_column = dynamic_cast<column_int*>(second);
    second_column->set_content(ints);
    second_column->set_boolen(bool_1);
    std::string name_2 = "tickets";
    second_column->set_name(name_2);

    std::vector<double> doubles = {1.3, 1.05, 1.58};
    column* third = new column_double();
    column_double* third_column = dynamic_cast<column_double*>(third);
    third_column->set_content(doubles);
    third_column->set_boolen(bool_1);
    std::string name_3 = "playtime";
    third_column->set_name(name_3);

    std::vector<std::string> strs_1 = {"VIP", "FRONT_ROW", "STANDARD"};
    column* forth = new column_string();
    column_string* forth_column = dynamic_cast<column_string*>(forth);
    forth_column->set_content(strs_1);
    forth_column->set_boolen(bool_1);
    std::string name_4 = "seats";
    forth_column->set_name(name_4);

    std::vector<column*> data = {first, second, third, forth};
    table tab("Heavy_Metal", data);

    std::ofstream out("Heavy_Metal.bin", std::ios::binary);
    tab.write_into_files(out);
    out.close();
}

void generate_second_table()
{
    std::vector<std::string> strs = {"S", "M", "L", "XL"};
    column* first = new column_string();
    column_string* first_column = dynamic_cast<column_string*>(first);
    first_column->set_content(strs);
    std::vector<bool> bool_1 = {1, 1, 1, 1};
    first_column->set_boolen(bool_1);
    std::string name_1 = "sizes";
    first_column->set_name(name_1);

    std::vector<int> ints = {15, 20, 13, 6};
    column* second = new column_int();
    column_int* second_column = dynamic_cast<column_int*>(second);
    second_column->set_content(ints);
    second_column->set_boolen(bool_1);
    std::string name_2 = "quantity";
    second_column->set_name(name_2);

    std::vector<double> doubles = {15.99, 25.99, 15.99, 15.99};
    column* third = new column_double();
    column_double* third_column = dynamic_cast<column_double*>(third);
    third_column->set_content(doubles);
    third_column->set_boolen(bool_1);
    std::string name_3 = "prices";
    third_column->set_name(name_3);

    std::vector<column*> data = {first, second, third};
    table tab("T_Shirts", data);

    std::ofstream out("T_Shirts.bin", std::ios::binary);
    tab.write_into_files(out);
    out.close();
}

void generate_table_with_holes()
{
    std::vector<std::string> strs_1 = {"Velizar", "Georgi", "Stoyan", "Dimitar", "Petar"};
    column* first = new column_string();
    column_string* first_column = dynamic_cast<column_string*>(first);
    first_column->set_content(strs_1);
    std::vector<bool> bool_1 = {1, 1, 1, 1, 1};
    first_column->set_boolen(bool_1);
    std::string name_1 = "firstnames";
    first_column->set_name(name_1);

    std::vector<std::string> strs_2 = {"NULL", "NULL", "Stoyanov", "Ivanov", "Ognqnov"};
    column* second = new column_string();
    column_string* second_column = dynamic_cast<column_string*>(second);
    second_column->set_content(strs_2);
    std::vector<bool> bool_2 = {0, 0, 1, 1, 1};
    second_column->set_boolen(bool_2);
    std::string name_2 = "secondnames";
    second_column->set_name(name_2);

    std::vector<std::string> strs_3 = {"Telbiiski", "NULL", "Ivanov", "NULL", "NULL"};
    column* third = new column_string();
    column_string* third_column = dynamic_cast<column_string*>(third);
    third_column->set_content(strs_3);
    std::vector<bool> bool_3 = {1, 0, 1, 0, 0};
    third_column->set_boolen(bool_3);
    std::string name_3 = "thirdnames";
    third_column->set_name(name_3);

    std::vector<int> arr = {30, -24, -20, -21, 20};
    column* forth = new column_int();
    column_int* forth_column = dynamic_cast<column_int*>(forth);
    forth_column->set_content(arr);
    std::vector<bool> bool_4 = {1, 0, 0, 0, 1};
    forth_column->set_boolen(bool_4);
    std::string name_4 = "ages";
    forth_column->set_name(name_4);

    std::vector<column*> data = {first, second, third, forth};
    table tab("People", data);

    std::ofstream out("People.bin", std::ios::binary);
    tab.write_into_files(out);
    out.close();
}

void generate_table_to_add()
{
    std::vector<std::string> strs = {"Motorhead", "Megadeth", "Sepultura"};
    column* first = new column_string();
    column_string* first_column = dynamic_cast<column_string*>(first);
    first_column->set_content(strs);
    std::vector<bool> bool_1 = {1, 1, 1};
    first_column->set_boolen(bool_1);
    std::string name_1 = "bands";
    first_column->set_name(name_1);
    
    std::vector<int> ints = {160, 130, 140};
    column* second = new column_int();
    column_int* second_column = dynamic_cast<column_int*>(second);
    second_column->set_content(ints);
    second_column->set_boolen(bool_1);
    std::string name_2 = "tickets";
    second_column->set_name(name_2);

    std::vector<double> doubles = {1.4, 1.01, 1.08};
    column* third = new column_double();
    column_double* third_column = dynamic_cast<column_double*>(third);
    third_column->set_content(doubles);
    third_column->set_boolen(bool_1);
    std::string name_3 = "playtime";
    third_column->set_name(name_3);

    std::vector<std::string> strs_1 = {"STANDARD", "FRONT_ROW", "STANDARD"};
    column* forth = new column_string();
    column_string* forth_column = dynamic_cast<column_string*>(forth);
    forth_column->set_content(strs_1);
    forth_column->set_boolen(bool_1);
    std::string name_4 = "seats";
    forth_column->set_name(name_4);

    std::vector<column*> data = {first, second, third, forth};
    table tab("Hard_Rock", data);

    std::ofstream out("Hard_Rock.bin", std::ios::binary);
    tab.write_into_files(out);
    out.close();
}

void generate_examples()
{
    generate_first_table();
    generate_second_table();
    generate_table_with_holes();
    generate_table_to_add();
    std::ofstream cat_1("Catalog_1.bin", std::ios::binary);
    cat_1 << 3 << ' '
        << "Heavy_Metal" << ' ' 
        << "T_Shirts" << ' '
        << "People";
    cat_1.close();

    std::ofstream cat_2("Catalog_2.bin", std::ios::binary);
    cat_2 << 2 << ' '
        << "Heavy_Metal" << ' ' 
        << "Hard_Rock";
    cat_2.close();
}

#endif