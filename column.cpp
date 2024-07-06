#include "column.h"

const std::vector<bool>& column::get_boolen() const
{
    return this->boolen;
}

const std::string column::get_name() const
{
    return this->name;
}

void column::set_name(const std::string& name)
{
    this->name = name;
}