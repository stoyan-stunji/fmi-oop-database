#include "table.h"

table::table()
{   
    this->name = "NULL";
    std::size_t size = this->data.size();
    for (std::size_t i = 0; i < size; ++i) 
    {
        this->data[i] = nullptr;
    }
}

table::table(const std::string& name, const std::vector<column*>& data)
{
    this->name = name;
    this->data = data;
}

void table::set_name(const std::string& name) 
{
    this->name = name;
}

void table::set_data(const std::vector<column*>& data)
{
    this->data = data;
}

const std::string& table::get_name() const
{ 
    return this->name; 
}

const std::vector<column*>& table::get_columns() const
{ 
    return this->data;
}

const bool table::is_table_correct() const
{
    return this->is_correct;
}

//__________________________________________________________________________//

void table::write_into_files(std::ofstream& out)
{
    if(out.is_open())
    {
        std::size_t out_size = this->data.size();
        out << out_size << ' ';

        for (std::size_t i = 0; i < out_size; ++i)
        {
            char c = this->data[i]->get_type_of_column();
            out << c << ' ';
            this->data[i]->write_into_file(out);
        }
    }
}

void table::read_from_files(std::ifstream& in)
{
    std::size_t to_size = 0;

    if(in.is_open())
    {
        in >> to_size;

        if(to_size <= 0)
        {
            return;
        }


        for (std::size_t i = 0; i < to_size; ++i)
        {
            char type = 'c';
            in >> type;

            std::string to_name;
            in >> to_name;
            
            if(type == 's')
            {
                std::size_t indv_size = 0;
                in >> indv_size;

                std::vector<std::string> to_fill_vector;
                std::vector<int> to_fill_boolen;
                for (std::size_t j = 0; j < indv_size; ++j)
                {
                    int flag = -1;
                    in >> flag;
                    if(flag == 1)
                    {
                        std::string str;
                        in >> str;
                        to_fill_vector.push_back(str);
                        to_fill_boolen.push_back(1);
                    }
                    else if(flag == 0)
                    {
                        std::string str;
                        in >> str;
                        to_fill_vector.push_back(str);
                        to_fill_boolen.push_back(0);
                    }
                    else 
                    {
                        std::string str;
                        in >> str;
                        to_fill_vector.push_back("NULL");
                        to_fill_boolen.push_back(flag);
                    }
                }
                                    
                column* temp = new column_string;
                column_string* temp_column = dynamic_cast<column_string*>(temp);
                temp_column->set_content(to_fill_vector);
                std::vector<bool> final_boolen;

                for (std::size_t i = 0; i < to_fill_boolen.size(); ++i)
                {
                    if(to_fill_boolen[i] == 1)
                    {
                        final_boolen.push_back(1);
                    }
                    else
                    {
                        final_boolen.push_back(0);
                    }
                } 
                          
                temp_column->set_boolen(final_boolen);
                temp_column->set_name(to_name);
                this->data.push_back(temp);
                this->is_correct = true;
            }
            else if(type == 'i')
            {
                std::size_t indv_size = 0;
                in >> indv_size;

                std::vector<int> to_fill_vector;
                std::vector<int> to_fill_boolen;

                for (std::size_t j = 0; j < indv_size; ++j)
                {
                    int flag = -1;
                    in >> flag;
                    if(flag == 1)
                    {
                        int integer;
                        in >> integer;
                        to_fill_vector.push_back(integer);
                        to_fill_boolen.push_back(1);
                    }
                    else if(flag == 0)
                    {
                        int integer;
                        in >> integer;
                        to_fill_vector.push_back(integer);
                        to_fill_boolen.push_back(0);
                    }
                    else
                    {
                        int integer;
                        in >> integer;
                        to_fill_vector.push_back(integer);
                        to_fill_boolen.push_back(flag);
                    }
                }

                column* temp = new column_int;
                column_int* temp_column = dynamic_cast<column_int*>(temp);
                temp_column->set_content(to_fill_vector);
                temp_column->set_name(to_name);
                std::vector<bool> final_boolen;
                    
                for (std::size_t i = 0; i < to_fill_boolen.size(); ++i)
                {
                    if(to_fill_boolen[i] == 1)
                    {
                        final_boolen.push_back(1);
                    }
                    else
                    {
                        final_boolen.push_back(0);
                    }
                }

                temp_column->set_boolen(final_boolen);
                this->data.push_back(temp);
                this->is_correct = true;
            }
            else if(type == 'd')
            {
                std::size_t indv_size = 0;
                in >> indv_size;

                std::vector<double> to_fill_vector;
                std::vector<int> to_fill_boolen;

                for (std::size_t j = 0; j < indv_size; ++j)
                {
                    int flag = -1;
                    in >> flag;
                    if(flag == 1)
                    {
                        double doubler;
                        in >> doubler;
                        to_fill_vector.push_back(doubler);
                        to_fill_boolen.push_back(1);
                    }
                    else if(flag == 0)
                    {
                        double doubler;
                        in >> doubler;
                        to_fill_vector.push_back(doubler);
                        to_fill_boolen.push_back(0);
                    }
                    else
                    {
                        double doubler;
                        in >> doubler;
                        to_fill_vector.push_back(doubler);
                        to_fill_boolen.push_back(flag); 
                    }
                }
                                    
                column* temp = new column_double();
                column_double* temp_column = dynamic_cast<column_double*>(temp);
                temp_column->set_content(to_fill_vector);
                temp_column->set_name(to_name);
                std::vector<bool> final_boolen;

                for (std::size_t i = 0; i < to_fill_boolen.size(); ++i)
                {
                    if(to_fill_boolen[i] == 1)
                    {
                        final_boolen.push_back(1);
                    }
                    else
                    {
                        final_boolen.push_back(0);
                    }
                }    

                temp_column->set_boolen(final_boolen);
                this->data.push_back(temp);
                this->is_correct = true;
            }
            else
            {
                std::size_t indv_size = 0;
                in >> indv_size;

                std::vector<std::string> to_fill_vector;
                std::vector<bool> final_boolen;

                for (std::size_t i = 0; i < indv_size; ++i)
                {
                    to_fill_vector.push_back("NULL");
                }

                for (std::size_t i = 0; i < indv_size; ++i)
                {
                    final_boolen.push_back(0);
                }

                column* temp = new column_string;
                column_string* temp_column = dynamic_cast<column_string*>(temp);
                temp_column->set_content(to_fill_vector);
                temp_column->set_boolen(final_boolen);
                temp_column->set_name(to_name);
                this->data.push_back(temp);
                this->is_correct = false;
            }
        }
    }                 
}

//__________________________________________________________________________//

std::vector<std::vector<std::string>> table::get_transposed_string_matrix()
{
    std::size_t size = this->data.size();
    std::vector<std::vector<std::string>> matrix(size);

    for (std::size_t i = 0; i < size; ++i)
    {
        char type = this->data[i]->get_type_of_column();

        if(type == 's')
        {
            column* temp = new column_string;
            column_string* temp_column = dynamic_cast<column_string*>(this->data[i]);
            std::size_t inner_size = temp_column->get_size_of_column();

            for (std::size_t j = 0; j < inner_size; ++j)
            {
                if(temp_column->get_boolen()[j] == 1)
                {
                    matrix[i].push_back(temp_column->get_content()[j]);
                }
                else
                {
                    matrix[i].push_back("NULL");
                }
            }
        }
        else if(type == 'i')
        {
            column* temp = new column_int;
            column_int* temp_column = dynamic_cast<column_int*>(this->data[i]);
            std::size_t inner_size = temp_column->get_size_of_column();

            for (std::size_t j = 0; j < inner_size; ++j)
            {
                if(temp_column->get_boolen()[j] == 1)
                {
                    matrix[i].push_back(std::to_string(temp_column->get_content()[j]));
                }
                else
                {
                    matrix[i].push_back("NULL");
                }
            }
        }
        else if(type == 'd')
        {
            column* temp = new column_double;
            column_double* temp_column = dynamic_cast<column_double*>(this->data[i]);
            std::size_t inner_size = temp_column->get_size_of_column();

            for (std::size_t j = 0; j < inner_size; ++j)
            {
                if(temp_column->get_boolen()[j] == 1)
                {
                    std::string str_value = std::to_string(temp_column->get_content()[j]);
                    std::string truncated_value = str_value.substr(0, 5);
                    matrix[i].push_back(truncated_value);
                }
                else
                {
                    matrix[i].push_back("NULL");
                }
            }
        }
    }

    std::size_t rows = matrix.size();
    std::size_t cols = matrix[0].size();

    std::vector<std::vector<std::string>> transpose(cols, std::vector<std::string>(rows));

    for (std::size_t i = 0; i < rows; ++i) 
    {
        for (std::size_t j = 0; j < cols; ++j) 
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    return transpose;
}

//__________________________________________________________________________//

void table::add_column_table(const std::string& name, const char type)
{
    if(type == 's')
    {
        std::size_t size = this->data[0]->get_size_of_column();
        std::vector<std::string> to_add;

        for (std::size_t i = 0; i < size; ++i)
        {
            to_add.push_back("NULL");
        }
        
        std::vector<bool> to_add_bool;
        for (std::size_t i = 0; i < size; ++i)
        {
            to_add_bool.push_back(0);
        }
            
        column* temp = new column_string;
        column_string* temp_column = dynamic_cast<column_string*>(temp);
        temp_column->set_content(to_add);
        temp_column->set_boolen(to_add_bool);
        temp_column->set_name(name);
        this->data.push_back(temp);
    }
    else if(type == 'i')
    {
        std::size_t size = this->data[0]->get_size_of_column();

        std::vector<int> to_add;
        for (std::size_t i = 0; i < size; ++i)
        {
            to_add.push_back(0);
        }
        
        std::vector<bool> to_add_bool;
        for (std::size_t i = 0; i < size; ++i)
        {
            to_add_bool.push_back(0);
        }
            
        column* temp = new column_int;
        column_int* temp_column = dynamic_cast<column_int*>(temp);
        temp_column->set_content(to_add);
        temp_column->set_boolen(to_add_bool);
        temp_column->set_name(name);
        this->data.push_back(temp);
    }
    else if(type == 'd')
    {
        std::size_t size = this->data[0]->get_size_of_column();
        std::vector<double> to_add;
        for (std::size_t i = 0; i < size; ++i)
        {
            to_add.push_back(0);
        }
        
        std::vector<bool> to_add_bool;   
        for (std::size_t i = 0; i < size; ++i)
        {
            to_add_bool.push_back(0);
        }
            
        column* temp = new column_double;
        column_double* temp_column = dynamic_cast<column_double*>(temp);
        temp_column->set_content(to_add);
        temp_column->set_boolen(to_add_bool);
        temp_column->set_name(name);
        this->data.push_back(temp);
    }
}

void table::update_table(int target_column, const std::string& target_value)
{
    this->data[target_column]->update_column(target_value);
}

void table::delete_table(int search_column, const std::string& search_value)
{
    int index = this->data[search_column]->delete_column(search_value);
    for (std::size_t i = 0; i < this->data.size(); ++i)
    {
        this->data[i]->pop_row(index);
    }       
}

void table::insert_table(int column_n, const std::string& input)
{
    this->data[column_n]->insert_column(input);
}
