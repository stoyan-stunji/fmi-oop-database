#ifndef COMMANDS_H
#define COMMANDS_H

#include "database.h"

const int RETURN_ZERO = 0;
const int RETURN_ONE = 1;
const int RETURN_TWO = 2;
const int RETURN_THREE = 3;
const int RETURN_FOUR = 4;
const int RETURN_FIVE = 5;
const int RETURN_SIX = 6;
const int RETURN_SEVEN = 7;

class commands
{
    public:
        /*[01]*/ const int open_commands();
        /*[02]*/ void save_commands();
        /*[03]*/ const int save_as_commands(const std::string& path, const std::string& table_name);

        /*[07]*/ const int import_commands(const std::string& file_name);
        /*[08]*/ std::vector<std::string> showtables_commands() const;
        /*[09]*/ const primitive_pair<int, std::string> describe_commands(const std::string& table_name) const;
        /*[10]*/ const int io_print_commands(const std::string& table_name);
        /*[11]*/ const int export_commands(const std::string& table_name, const std::string& new_name);
        /*[12]*/ const int select_commands(int column_n, const std::string& search_value, const std::string table_name);
        /*[13]*/ const int select_onto_commands(const std::string& result_table_name, std::vector<int>& column_numbers, int column_n, const std::string& value, const std::string& table_name);
        /*[14]*/ const int add_column_commands(const std::string& table_name, const std::string& column_name, char column_type);
        /*[15]*/ const primitive_pair<int, std::string> update_commands(const std::string& table_name, int search_column, const std::string& search_value, int target_column, const std::string& target_value);
        /*[16]*/ const int delete_commands(const std::string& table_name, int search_column, const std::string& search_value);
        /*[17]*/ const primitive_pair<int, std::string> insert_commands(const std::string& table_name, const std::vector<int>& columns);

    private:
        database base;
        std::string current_catalog;

        void io_print_by_page(const std::vector<std::vector<std::string>>& matrix);
        void io_print_by_page_special(const std::vector<std::vector<std::string>>& matrix,
                                   const std::string& search_value, int column_n);
};

#endif