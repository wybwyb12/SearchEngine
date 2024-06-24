#ifndef __DICT_PRODUCTOR_H__
#define __DICT_PRODUCTOR_H__
#define CHSIZE 3

#include "WordSegmentation.h"
#include <set>
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using std::set;
using std::unordered_map;
using std::vector;
using std::string;
using std::endl;
using std::cout;


class Dict_productor
{
public:
    Dict_productor();
    ~Dict_productor();
    void read_en_file(const string &filename);
    void read_cn_file(const string &filename);
    void save_dict(const string &filename);
    void save_idMap(const string &filename);
    void save_index(const string &filename);
    void lowerLine(string &line);
    void insertEnIndex(const string &word, size_t id);
    void insertCnIndex(const string &elem, size_t id);

private:
    unordered_map<string, int> _dict;
    WordSegmentation _jieba;
    unordered_map<int, string> _map;
    unordered_map<string, set<int>> _index;
};

#endif

