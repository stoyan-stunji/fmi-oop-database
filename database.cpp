#include "database.h"

database::database()
{
    table table;
    this->data.push_back(table);
}

database::database(std::ifstream& catalog)
{
    std::size_t to_size;
    std::vector<std::string> names;

    if(catalog.is_open())
    {
        catalog >> to_size;

        for (std::size_t i = 0; i < to_size; ++i)
        {
            std::string to_push;
            catalog >> to_push;
            names.push_back(to_push);
        }             
    }

    for (std::size_t i = 0; i < to_size; ++i)
    {
        std::string to_name = names[i] + ".bin";
        std::ifstream in(to_name, std::ios::binary);
        table table;
        table.read_from_files(in);
        this->data.push_back(table);
        in.close();
    }       

    for (std::size_t i = 0; i < to_size; ++i)
    {
        std::string to_name = names[i];
        this->data[i].set_name(to_name);
    }        
}

const std::vector<table>& database::get_data() const
{
    return this->data;
}

//__________________________________________________________________________//

const std::size_t database::is_table_in_database(const std::string& name) const
{
    std::size_t index = -1;
    std::size_t size = this->data.size();
    for (std::size_t i = 0; i < size; ++i)
    {
        if(name == this->data[i].get_name())
        {
            index = i;
        }
    }
    return index;
}

const bool database::is_table_correct_in_database(std::size_t index) const
{
    return this->data[index].is_table_correct();
}

std::vector<std::vector<std::string>> database::get_string_matrix(std::size_t index)
{
    std::vector<std::vector<std::string>> matrix = this->data[index].get_transposed_string_matrix();
    return matrix;
}

//__________________________________________________________________________//

void database::save_base()
{
    std::size_t size = this->data.size();
    for (std::size_t i = 0; i < size; ++i)
    {
        std::string to_name = this->data[i].get_name() + ".bin";
        std::ofstream out(to_name, std::ios::binary);
        bool flag = this->data[i].is_table_correct();
        if(!flag)
        {
            out << '0';
        }
        else
        {
            this->data[i].write_into_files(out);
        }
        out.close();
    }       
}

void database::save_as_base(int index, const std::string& input)
{
    std::string to_name = input;
    std::ofstream out(to_name, std::ios::binary);
    if(out.is_open())
    {
        this->data[index].write_into_files(out);
    }
    out.close();
}

//__________________________________________________________________________//

void database::import_base(const table& table)
{
    this->data.push_back(table);
    std::size_t end = this->data.size() - 1;
    std::string to_name = this->data[end].get_name();
    this->data[end].set_name(to_name);
}

const std::vector<std::string> database::showtables_base() const
{
    std::vector<std::string> names;
    std::size_t size = this->data.size();

    for (std::size_t i = 0; i < size; ++i)
    {
        std::string temp;
        std::string str = this->data[i].get_name(); 
        temp += ("[" + std::to_string((i + 1)) + "] " + str);
        names.push_back(temp);
    } 

    return names;
}

const std::string database::describe_base(const std::size_t index) const
{
    std::string types;   
    std::size_t size = this->data[index].get_columns().size();

    for (std::size_t i = 0; i < size; ++i)
    {
        char type = this->data[index].get_columns()[i]->get_type_of_column();

        if(type == 's')
        {
            types += ("[string]");
        }
        else if(type == 'i')
        {
            types += ("[integer]");
        }
        else if(type == 'd')
        {
            types += ("[double]");
        }
    }

    return types;
}

void database::export_base(const std::string& name, std::size_t index)
{
    std::vector<std::vector<std::string>> matrix = get_string_matrix(index);
    std::ofstream out(name + ".txt", std::ios::binary);

    std::size_t rows = matrix.size();
    std::size_t cols = matrix[0].size();
    
    for (std::size_t i = 0; i < rows; ++i)
    {
        for (std::size_t j = 0; j < cols; ++j)
        {
            out << matrix[i][j] << ' ';
        }
        out << '\n';
    }
    out.close();
}

void database::add_column_base(std::size_t index, const std::string& name, const char type)
{
    this->data[index].add_column_table(name, type);
}

void database::update_base(int index, int target_column, const std::string& target_info)
{
    this->data[index].update_table(target_column, target_info);
}

void database::delete_base(int index, int search_column, const std::string& search_info)
{
    this->data[index].delete_table(search_column, search_info);
}

void database::insert_table(int index, int column_n, const std::string& input)
{
    this->data[index].insert_table(column_n, input);
}