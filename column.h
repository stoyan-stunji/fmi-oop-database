#ifndef COLUMN_H
#define COLUMN_H

#include <iostream>
#include <vector>
#include <string>

#include "primitive_pair.h"

#include <fstream>

class column
{
    public:      
        virtual const std::vector<bool>& get_boolen() const;
        virtual const std::string get_name() const;

        virtual const char get_type_of_column() const = 0;
        virtual const std::size_t get_size_of_column() const = 0;

        virtual void set_name(const std::string& name);
        virtual void write_into_file(std::ofstream& out) const = 0;

        virtual column* clone() const = 0;
        virtual ~column() {};

        /*[15]*/ virtual void update_column(const std::string& info) = 0;
        /*[16]*/ virtual int delete_column(const std::string& info) = 0;
                 virtual void pop_row(int index) = 0;
        /*[17]*/ virtual void insert_column(const std::string& input) = 0;

    protected:
        std::vector<bool> boolen;
        std::string name;
};


#endif