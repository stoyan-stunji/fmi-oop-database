#include "column_double.h"

column_double::column_double()
{
    std::vector<double> content;
    this->content = content;
}

column_double::column_double(const std::vector<double>& content, const std::vector<bool>& boolen)
{
    this->content = content;
    this->boolen = boolen;
}

void column_double::set_content(const std::vector<double>& content)
{
    this->content = content;
}

void column_double::set_boolen(const std::vector<bool>& boolen)
{
    this->boolen = boolen;
}

const std::size_t column_double::get_size_of_column() const
{ 
    return this->content.size();
}

const std::vector<double>& column_double::get_content() const 
{ 
    return this->content;
}

const char column_double::get_type_of_column() const 
{ 
    return 'd';
}

column* column_double::clone() const 
{ 
    return new column_double(*this); 
}

//__________________________________________________________________________//

void column_double::write_into_file(std::ofstream& out) const
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

void column_double::update_column(const std::string& info)
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
        double changed = 0;

        try
        {
            changed = std::stod(info);
        }
        catch(const std::exception& e)
        {
            throw "[-] [string data CANNOT be parsed as double data]\n";
        }
                
        for (std::size_t i = 0; i < this->content.size(); ++i)
        {
            this->content[i] = changed;
            this->boolen[i] = 1;
        }
    }
}

int column_double::delete_column(const std::string& info)
{
    int index = -1;

    for (std::size_t i = 0; i < this->content.size(); ++i)
    {
        double temp = std::stod(info);
        if(this->content[i] == temp)
        {
            index = i;
        }
    }

    this->boolen[index] = 0;
    return index;
}

void column_double::pop_row(int index)
{
    this->content.erase(this->content.begin() + index);
    this->boolen.erase(this->boolen.begin() + index);
}

void column_double::insert_column(const std::string& input)
{
    if(input == "NULL")
    {
        this->content.push_back(0);
        this->boolen.push_back(0);
    }
    else
    {
        double changed = 0;

        try
        {
            changed = std::stod(input);
        }
        catch(const std::exception& e)
        {
            throw "[-] [string data cannot be parsed as integer data]\n";
        }
        this->content.push_back(changed);
        this->boolen.push_back(1);
    }
}
