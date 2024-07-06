#ifndef DATABASE_H
#define DATABASE_H

#include "table.h"

class database
{
    public:
        database();
        database(std::ifstream& catalog);
        const std::vector<table>& get_data() const;
      
        const std::size_t is_table_in_database(const std::string& name) const;
        const bool is_table_correct_in_database(std::size_t index) const;
        std::vector<std::vector<std::string>> get_string_matrix(std::size_t index);

        /*[02]*/ void save_base();
        /*[03]*/ void save_as_base(int index, const std::string& input);

        /*[07]*/ void import_base(const table& table);
        /*[08]*/ const std::vector<std::string> showtables_base() const;
        /*[09]*/ const std::string describe_base(const std::size_t index) const;

        /*[11]*/ void export_base(const std::string& name, std::size_t index);
        
        /*[14]*/ void add_column_base(std::size_t index, const std::string& info, const char type);
        /*[15]*/ void update_base(int index, int target_column, const std::string& target_info);
        /*[16]*/ void delete_base(int index, int search_column, const std::string& search_info);
        /*[17]*/ void insert_table(int index, int column_n, const std::string& input);
        
    private:
        std::vector<table> data;
};




#endif

