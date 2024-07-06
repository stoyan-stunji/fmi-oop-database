#ifndef MENU_H
#define MENU_H

#include "commands.h"

class menu
{
    public:
        /*[01]*/ void open();
        /*[02]*/ void save();
        /*[03]*/ void save_as(); /* TEST_PATH : C:\Users\Nitro\Desktop\test */
        /*[04]*/ void exit();      
        /*[05]*/ void close();
        /*[06]*/ void help();
        /*[07]*/ void import();
        /*[08]*/ void showtables();
        /*[09]*/ void describe();
        /*[10]*/ void print();
        /*[11]*/ void xport();
        /*[12]*/ void select();
        /*[13]*/ void select_onto();
        /*[14]*/ void add_column();
        /*[15]*/ void update();
        /*[16]*/ void remove();
        /*[17]*/ void insert();
        /*[18]*/ void credits();

    private:
        commands menu_commands;
};



#endif