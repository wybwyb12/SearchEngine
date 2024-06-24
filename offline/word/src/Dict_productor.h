#ifndef __DICT_PRODUCTOR_H__
#define __DICT_PRODUCTOR_H__

#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::endl;
using std::cout;


class Dict_productor
{
public:
    Dict_productor();
    ~Dict_productor();
    void read_en_file(const string &filename);
    void save_en_dict(const string &filename);

private:
    map<string, int> _en_dict;
};

#endif

