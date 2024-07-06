#include "commands.h"

void commands::io_print_by_page(const std::vector<std::vector<std::string>>& matrix)
{
    std::size_t rows = matrix.size();
    std::size_t cols = matrix[0].size();

    long long page = -1;
    std::cout << "[>] [-1 to exit] ";
    std::string page_str;
    std::cin >> page_str;
    try
    {
        page = std::stoi(page_str);
    }
    catch(...)
    {
        return;
    }  
    system("cls");

    while(page != -1)
    {
        if(page < 0 || page >= rows)
        {
            page = 0;
        }

        for (std::size_t i = 0; i < cols; ++i)
        {
            std::cout << matrix[page][i] << ' ';   
        }
                
        std::cout << "\n[>] [-1 to exit] ";
        std::cin >> page;
        system("cls");
    }   
}

void commands::io_print_by_page_special(const std::vector<std::vector<std::string>>& matrix,
                                     const std::string& search_value, int column_n)
{
    std::size_t rows = matrix.size();
    std::size_t cols = matrix[0].size();

    long long page = -1;
    std::cout << "[>] [-1 to exit] ";
    std::string page_str;
    std::cin >> page_str;
    try
    {
        page = std::stoi(page_str);
    }
    catch(...)
    {
        return;
    }  
    system("cls");

    while(page != -1)
    {
        if(page < 0 || page >= rows)
        {
            std::cout << "[-] [invalid page]";
            page = -1;
        }

        for (std::size_t i = 0; i < rows; ++i)
        {
            if(search_value == matrix[i][page])
            {
                for (std::size_t j = 0; j < cols; ++j)
                {
                    std::cout << matrix[i][j] << ' ';
                }
            }
        }  
                
        std::cout << "\n>> [-1 to exit] ";
        std::cin >> page;
        system("cls");
    }      
}

//__________________________________________________________________________//

const int commands::open_commands()
{
    std::cin >> this->current_catalog;

    std::ifstream in(this->current_catalog + ".bin", std::ios::binary);
    if(in.is_open())
    {
        database base(in);
        this->base = base;

        std::size_t size = this->base.get_data().size();
        for (std::size_t i = 0; i < size; ++i)
        {
            bool flag = this->base.get_data()[i].is_table_correct();
            if(!flag)
            {
                std::cout << "[-] [an INCORRECT table added]\n";
            }
        }      
    }
    else
    {
        std::ofstream out("Empty.bin", std::ios::binary);
        return RETURN_ZERO;
    }

    in.close();
    save_commands();
    return RETURN_ONE;
}

void commands::save_commands()
{
    std::string current_catalog_name = this->current_catalog;
    std::ofstream out(current_catalog_name + ".bin", std::ios::binary);
    if(out.is_open())
    {
        std::size_t size = this->base.get_data().size();
        out << size << ' ';

        for (std::size_t i = 0; i < size; ++i)
        {
            std::string temp = this->base.get_data()[i].get_name();
            out << temp << ' ';
        }          
    }

    out.close();
    this->base.save_base();      
}

const int commands::save_as_commands(const std::string& path, const std::string& table_name)
{
    std::size_t index = this->base.is_table_in_database(table_name);
    if(index == -1)
    {
        return RETURN_ZERO;
    }

    bool flag = this->base.is_table_correct_in_database(index);
    if(!flag)
    {
        return RETURN_TWO;
    }

    std::string destination = path + "\\" + table_name + ".bin";
    this->base.save_as_base(index, destination);
    return RETURN_ONE;
}
    
//__________________________________________________________________________//

const int commands::import_commands(const std::string& file_name)
{
    std::ifstream in(file_name + ".bin", std::ios::binary);
    std::size_t size = this->base.get_data().size();

    for (std::size_t i = 0; i < size; ++i)
    {
        std::string temp = this->base.get_data()[i].get_name();

        if(file_name == temp)
        {
            return RETURN_ZERO;
        }
    }
            
    table table;
    table.set_name(file_name);
    table.read_from_files(in);
    this->base.import_base(table);

    if(!table.is_table_correct())
    {
        return RETURN_TWO;
    }

    return RETURN_ONE;
}

std::vector<std::string> commands::showtables_commands() const
{
    return this->base.showtables_base();
}

const primitive_pair<int, std::string> commands::describe_commands(const std::string& table_name) const
{
    primitive_pair<int, std::string> pair;

    std::size_t index = this->base.is_table_in_database(table_name);
    if(index == -1)
    {
        pair.first = RETURN_ZERO;
        return pair;
    }

    bool flag = this->base.is_table_correct_in_database(index);
    if(!flag)
    {
        pair.first = RETURN_TWO;
        return pair;
    }

    std::string types = this->base.describe_base(index);
    pair.first = RETURN_ONE;
    pair.second = types;
    return pair;
}

const int commands::io_print_commands(const std::string& table_name)
{
    std::size_t index = this->base.is_table_in_database(table_name);
    if(index == -1)
    {
        return RETURN_ZERO;
    }

    bool flag = this->base.is_table_correct_in_database(index);
    if(!flag)
    {
        return RETURN_TWO;
    }

    std::vector<std::vector<std::string>> matrix = this->base.get_string_matrix(index);
    io_print_by_page(matrix);  
    return RETURN_ONE; 
}

const int commands::export_commands(const std::string& table_name, const std::string& new_name)
{
    std::size_t index = this->base.is_table_in_database(table_name);
    if(index == -1)
    {
        return RETURN_ZERO;
    }

    bool flag = this->base.is_table_correct_in_database(index);
    if(!flag)
    {
        return RETURN_TWO;
    }

    this->base.export_base(new_name, index);
    return RETURN_ONE;
}

const int commands::select_commands(int column_n, const std::string& search_value, const std::string table_name)
{
    std::size_t index = this->base.is_table_in_database(table_name);
    if(index == -1)
    {
        return RETURN_ZERO;
    }

    bool flagger = this->base.is_table_correct_in_database(index);
    if(!flagger)
    {
        return RETURN_FOUR;
    }

    std::size_t size = this->base.get_data()[index].get_columns().size();
    if(column_n < 0 || column_n >= size)
    {
        return RETURN_ONE;
    }

    std::vector<std::vector<std::string>> matrix = this->base.get_string_matrix(index);
    
    std::size_t rows = matrix.size();
    std::size_t cols = matrix[0].size();

    bool flag = false;
    for (std::size_t i = 0; i < rows; ++i)
    {
        if(search_value == matrix[i][column_n])
        {
            flag = true;
        }      
    }

    if(!flag)
    {
        return RETURN_TWO;
    }
    else
    {
        io_print_by_page_special(matrix, search_value, column_n);   
    }

    return RETURN_THREE;
}

const int commands::select_onto_commands(const std::string& result_table_name, std::vector<int>& column_numbers, int column_n, const std::string& value, const std::string& table_name)
{
    std::size_t index = this->base.is_table_in_database(table_name);
    if(index == -1)
    {
        return RETURN_ZERO;
    }

    bool flagger = this->base.is_table_correct_in_database(index);
    if(!flagger)
    {
        return RETURN_FIVE;
    }

    std::size_t size = this->base.get_data()[index].get_columns().size();
    for (std::size_t i = 0; i < size; ++i)
    {
        if(column_numbers[i] < 0 || column_numbers[i] >= size)
        {
            return RETURN_ONE;
        }
    }

    if(column_n < 0 || column_n >= size)
    {
        return RETURN_TWO;
    }
    
    std::vector<std::vector<std::string>> matrix = this->base.get_string_matrix(index);
    std::size_t rows = matrix.size();
    std::size_t cols = matrix[0].size();

    bool flag = false;
    for (std::size_t i = 0; i < rows; ++i)
    {
        if(value == matrix[i][column_n])
        {
            flag = true;
        }      
    }

    if(!flag)
    {
        return RETURN_THREE;
    }

    std::vector<column*> column_vector = this->base.get_data()[index].get_columns();
    std::vector<column*> result_columns;
    for (std::size_t i = 0; i < column_numbers.size(); ++i)
    {
        result_columns.push_back(column_vector[column_numbers[i]]);
    }

    table table;
    table.set_data(result_columns);
    table.set_name(result_table_name);
    std::ofstream out(result_table_name + ".bin", std::ios::binary);
    table.write_into_files(out);

    return RETURN_FOUR;
}

const int commands::add_column_commands(const std::string& table_name, const std::string& column_name, char column_type)
{
    std::size_t index = this->base.is_table_in_database(table_name);
    if(index == -1)
    {       
        return RETURN_ZERO;
    }

    bool flag = this->base.is_table_correct_in_database(index);
    if(!flag)
    {
        return RETURN_THREE;
    }

    if(column_type == 's' || column_type == 'i' || column_type == 'd')
    {  
        this->base.add_column_base(index, column_name, column_type);
        return RETURN_ONE;
    }
    else
    {
        return RETURN_TWO;
    }
}

const primitive_pair<int, std::string> commands::update_commands(const std::string& table_name, int search_column, const std::string& search_value, int target_column, const std::string& target_value)
{
    primitive_pair<int, std::string> pair;

    std::size_t index = this->base.is_table_in_database(table_name);
    if(index == -1)
    {
        pair.first = RETURN_ZERO;
        return pair;
    }

    bool flagger = this->base.is_table_correct_in_database(index);
    if(!flagger)
    {
        pair.first = RETURN_SIX;
        return pair;
    }

    std::size_t size = this->base.get_data()[index].get_columns().size();
    if(search_column < 0 || search_column >= size)
    {
        pair.first = RETURN_ONE;
        return pair;
    }

    std::vector<std::vector<std::string>> matrix = this->base.get_string_matrix(index);
    std::size_t rows = matrix.size();
    std::size_t cols = matrix[0].size();

    bool flag = false;
    for (std::size_t i = 0; i < rows; ++i)
    {
        for (std::size_t j = 0; j < cols; ++j)
        {
            if(search_value == matrix[i][j])
            {
                flag = true;
            }
        }
    }
    
    if(!flag)
    {      
        pair.first = RETURN_TWO;
        return pair;
    }

    if(target_column < 0 || target_column >= size)
    {
        pair.first = RETURN_THREE;
        return pair;
    }

    try
    {
        this->base.update_base(index, target_column, target_value);
    }
    catch(const char* e)
    {
        std::string str = e;
        pair.first = RETURN_FIVE;
        pair.second = str;
        return pair;
    }
    
    pair.first = RETURN_FOUR;
    return pair;
}

const int commands::delete_commands(const std::string& table_name, int search_column, const std::string& search_value)
{
    std::size_t index = this->base.is_table_in_database(table_name);
    if(index == -1)
    {
        return RETURN_ZERO;
    }

    bool flag = this->base.is_table_correct_in_database(index);
    if(!flag)
    {
        return RETURN_THREE;
    }

    std::size_t size = this->base.get_data()[index].get_columns().size();
    if(search_column < 0 || search_column >= size)
    {
        return RETURN_ONE;
    }

    std::vector<std::vector<std::string>> matrix = this->base.get_string_matrix(index);
    std::size_t rows = matrix.size();
    std::size_t cols = matrix[0].size();

    bool flagger = false;
    for (std::size_t j = 0; j < rows; ++j)
    {
        if(search_value == matrix[j][search_column])
        {
            flagger = true;
        }
    }

    if(flagger)
    {
        this->base.delete_base(index, search_column, search_value);
    }
    else
    {
        return RETURN_FOUR;
    }

    return RETURN_TWO;
}

const primitive_pair<int, std::string> commands::insert_commands(const std::string& table_name, const std::vector<int>& columns)
{
    primitive_pair<int, std::string> pair;

    std::size_t index = this->base.is_table_in_database(table_name);
    if(index == -1)
    {
        pair.first = RETURN_ZERO;
        return pair;
    }

    bool flagger = this->base.is_table_correct_in_database(index);
    if(!flagger)
    {
        pair.first = RETURN_SIX;
        return pair;
    }

    std::vector<int> copy_columns = columns;
    int copy_size = copy_columns.size();

    for (std::size_t i = 0; i < copy_size - 1; ++i)
    {
        for (std::size_t j = 0; j <  copy_size - i - 1; ++j) 
        {
            if (copy_columns[j] > copy_columns[j + 1])
            {
                std::swap(copy_columns[j], copy_columns[j + 1]);
            }
        }
    }

    for (std::size_t i = 1; i < copy_size; ++i)
    {
        if (copy_columns[i] == copy_columns[i - 1])
        {
            pair.first = RETURN_SEVEN;
            return pair;
        }
    }

    std::size_t size = this->base.get_data()[index].get_columns().size();
    for (std::size_t i = 0; i < columns.size(); ++i)
    {
        if(columns[i] < 0 || columns[i] >= size)
        {
            pair.first = RETURN_ONE;
            return pair;
        }
    }
    
    for (std::size_t i = 0; i < columns.size(); ++i)
    {
        char c = this->base.get_data()[index].get_columns()[columns[i]]->get_type_of_column();
        std::cout << ">> [" << columns[i] << "] [" << c << "] ";
        std::string input;
        std::cin >> input;

        try
        {
            this->base.insert_table(index, columns[i], input);
        }
        catch(const char* e)
        {
            pair.first = RETURN_THREE;
            std::string str = e;
            pair.second = str;
            return pair;
        }
        
    }

    std::vector<int> rest_columns;
    std::vector<int> all_column_numbers;
    
    for (std::size_t i = 0; i < size; ++i)
    {
        all_column_numbers.push_back(i);
    }
       
    for (int first : all_column_numbers) 
    {
        bool found = false;
        for (int second : columns) 
        {
            if (first == second) 
            {
                found = true;
                break;
            }
        }

        if (!found) 
        {
            rest_columns.push_back(first);
        }
    }

    for (std::size_t i = 0; i < rest_columns.size(); ++i)
    {
        this->base.insert_table(index, rest_columns[i], "NULL");
    }    

    pair.first = RETURN_TWO;
    return pair;
}
