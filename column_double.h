#ifndef COLUMN_DOUBLE_H
#define COLUMN_DOUBLE_H

#include "column.h"

#include <iomanip> // for the .00;

class column_double : public column
{
    public:
        column_double();
        column_double(const std::vector<double>& content, const std::vector<bool>& boolen);

        const std::size_t get_size_of_column() const;
        const char get_type_of_column() const;

        const std::vector<double>& get_content() const;

        void set_content(const std::vector<double>& content);
        void set_boolen(const std::vector<bool>& boolen);

        virtual column* clone() const;
        virtual void write_into_file(std::ofstream& out) const;

        /*[15]*/ virtual void update_column(const std::string& info);
        /*[16]*/ virtual int delete_column(const std::string& info);
                 virtual void pop_row(int index);
        /*[17]*/ virtual void insert_column(const std::string& input);

    protected:
        std::vector<double> content;
};

#endif