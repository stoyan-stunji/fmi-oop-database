#include "column_int.h"

column_int::column_int()
{
    std::vector<int> content;
    this->content = content;
}

column_int::column_int(const std::vector<int>& content, const std::vector<bool>& boolen)
{
    this->content = content; 
    this->boolen = boolen; 
}

void column_int::set_content(const std::vector<int>& content)
{
    this->content = content;
}

void column_int::set_boolen(const std::vector<bool>& boolen)
{
    this->boolen = boolen;
}

const std::size_t column_int::get_size_of_column() const
{ 
    return this->content.size();
}

const std::vector<int>& column_int::get_content() const 
{ 
    return this->content;
}

const char column_int::get_type_of_column() const 
{ 
    return 'i';
}

column* column_int::clone() const 
{ 
    return new column_int(*this); 
}

//__________________________________________________________________________//

void column_int::write_into_file(std::ofstream& out) const
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


void column_int::update_column(const std::string& info)
{        
    if(info == "NULL")
    {
        for (std::size_t i = 0; i < this->content.size(); ++i)
        {
            this->content[i] = 0;
            this->boolen[i] = 0;
        }
    }   
    else
    {
        int changed = 0;

        try
        {
            changed = std::stoi(info);
        }
        catch(const std::exception& e)
        {
            throw "[-] [string data CANNOT be parsed as integer data]\n";
        }
                
        for (std::size_t i = 0; i < this->content.size(); ++i)
        {
            this->content[i] = changed;
            this->boolen[i] = 1;
        }
    }          
}

int column_int::delete_column(const std::string& info)
{
    int index = -1;

    for (std::size_t i = 0; i < this->content.size(); ++i)
    {
        int temp = std::stoi(info);
        if(this->content[i] == temp)
        {
            index = i;
        }
    }
    this->boolen[index] = 0;
    return index;
}

void column_int::pop_row(int index)
{
    this->content.erase(this->content.begin() + index);
    this->boolen.erase(this->boolen.begin() + index);
}

void column_int::insert_column(const std::string& input)
{
    if(input == "NULL")
    {
        this->content.push_back(0);
        this->boolen.push_back(0);
    }
    else
    {
        int changed = 0;
        try
        {
            changed = std::stoi(input);
        }
        catch(const std::exception& e)
        {
            throw "[-] [string data CANNOT be parsed as integer data]\n";
        }
                
        this->content.push_back(std::stoi(input));
        this->boolen.push_back(1);
    }
}