#ifndef COLUMN_INT_H
#define COLUMN_INT_H

#include "column.h"

class column_int : public column
{
    public:
        column_int();
        column_int(const std::vector<int>& content, const std::vector<bool>& boolen);

        const std::size_t get_size_of_column() const;
        const char get_type_of_column() const;

        const std::vector<int>& get_content() const;

        void set_content(const std::vector<int>& content);
        void set_boolen(const std::vector<bool>& boolen);

        virtual column* clone() const;
        virtual void write_into_file(std::ofstream& out) const;

        /*[15]*/ virtual void update_column(const std::string& info);
        /*[16]*/ virtual int delete_column(const std::string& info);
                 virtual void pop_row(int index);
        /*[17]*/ virtual void insert_column(const std::string& input);

    protected:
        std::vector<int> content;
};

#endif