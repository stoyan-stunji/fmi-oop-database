#include "column_string.h"

column_string::column_string()
{
    std::vector<std::string> content;
    this->content = content;
}

column_string::column_string(const std::vector<std::string>& content, const std::vector<bool>& boolen)
{
    this->content = content;
    this->boolen = boolen;
}

const std::vector<std::string>& column_string::get_content() const 
{ 
    return this->content; 
}

const std::size_t column_string::get_size_of_column() const
{ 
    return this->content.size();
}

void column_string::set_content(const std::vector<std::string>& content)
{
    this->content = content;
}

void column_string::set_boolen(const std::vector<bool>& boolen)
{
    this->boolen = boolen;
}

column* column_string::clone() const 
{ 
    return new column_string(*this); 
}

const char column_string::get_type_of_column() const 
{ 
    return 's'; 
}

//__________________________________________________________________________//

void column_string::write_into_file(std::ofstream& out) const
{
    if(out.is_open())
    {
        std::string name = this->name;
        out << name << ' ';
        std::size_t out_size = this->content.size();
        out << out_size << ' ';
        for (std::size_t i = 0; i < out_size; ++i)
        {
            out << this->boolen[i] << ' ';
            out << this->content[i] << ' ';
        }
    }
}

//__________________________________________________________________________//

void column_string::insert_column(const std::string& input)
{
    bool is_number = true;
    
    try
    {
        std::stoi(input);
    }
    catch(const std::exception& e)
    {
        is_number = false;
    }

    if (is_number)
    {
        throw "[-] [number data CANNOT be parsed as string data]\n";
    }

    if(input == "NULL")
    {
        this->content.push_back(input);
        this->boolen.push_back(0);
    }
    else
    {
        this->content.push_back(input);
        this->boolen.push_back(1);
    }
}

void column_string::pop_row(int index)
{
    this->content.erase(this->content.begin() + index);
    this->boolen.erase(this->boolen.begin() + index);
}

int column_string::delete_column(const std::string& info)
{
    int index = -1;

    for (std::size_t i = 0; i < this->content.size(); ++i)
    {
        if(this->content[i] == info)
        {
            index = i;
        }
    }

    this->boolen[index] = 0;
    return index;
}

void column_string::update_column(const std::string& info)
{
    bool is_number = true;

    try
    {
        std::stoi(info);
    }
    catch(const std::exception& e)
    {
        is_number = false;
    }

    if (is_number)
    {
        throw "[-] [number data CANNOT be parsed as string data]\n";
        return;
    }

    if(info == "NULL")
    {
        for (std::size_t i = 0; i < this->content.size(); ++i)
        {
            this->content[i] = "NULL";
            this->boolen[i] = 0;
        }
    }   
    else
    {
        for (std::size_t i = 0; i < this->content.size(); ++i)
        {
            this->content[i] = info;
            this->boolen[i] = 1;
        }
    }          
}

