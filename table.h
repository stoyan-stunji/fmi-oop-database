#ifndef TABLE_H
#define TABLE_H

#include "column.h"
#include "column_string.h"
#include "column_int.h"
#include "column_double.h"

class table
{
    public:
        table();
        table(const std::string& name, const std::vector<column*>& data);

        const std::string& get_name() const;
        const std::vector<column*>& get_columns() const;
        
        void set_name(const std::string& name);
        void set_data(const std::vector<column*>& data);

        void write_into_files(std::ofstream& out);
        void read_from_files(std::ifstream& in);

        std::vector<std::vector<std::string>> get_transposed_string_matrix();

        /*[14]*/ void add_column_table(const std::string& info, const char type);
        /*[15]*/ void update_table(int target_column, const std::string& target_value);
        /*[16]*/ void delete_table(int search_column, const std::string& search_value);
        /*[17]*/ void insert_table(int column_n, const std::string& input);

        const bool is_table_correct() const;

    private:
        std::string name;
        std::vector<column*> data;

        bool is_correct;
};

#endif