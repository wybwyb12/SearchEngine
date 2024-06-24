#include "../include/Dict_productor.h"

#include <fstream>
#include <sstream>

using std::cerr;
using std::ifstream;
using std::ofstream;
using std::istringstream;

Dict_productor::Dict_productor()
: _jieba()
{

};

Dict_productor::~Dict_productor(){};

void Dict_productor::read_en_file(const string &filename)
{
    ifstream ifs(filename);
    if(!ifs.good())
    {
        cerr << "open " << filename << " error" << endl;
        return;
    }

    string line;
    while(getline(ifs, line))
    {
        lowerLine(line);
        istringstream iss(line);
        string word;
        string tmp;
        int id;
        while(iss >> word)
        {
            tmp = word;
            for(size_t idx = 0; idx != word.size(); ++idx)
            {
                if(!isalpha(word[idx]))
                {
                    tmp = string();
                }
            }
            if(tmp != string())
            {
                ++_dict[word];
                id = _dict.size();
                insertEnIndex(word, id);
                _map[id] = word;
            }
        }
    }

    ifs.close();
}

void Dict_productor::save_dict(const string &filename)
{
    ofstream ofs(filename);
    if(!ofs.good())
    {
        cerr << "open " << filename << " error" << endl;
        return;
    }
    unordered_map<string, int>::iterator it;
    for(it = _dict.begin(); it != _dict.end(); ++it)
    {
        ofs << it->first << " " << it->second << endl;
    }

    ofs.close();
}


void Dict_productor::save_idMap(const string &filename)
{
    ofstream ofs(filename);
    if(!ofs.good())
    {
        cerr << "open " << filename << " error" << endl;
        return;
    }
    unordered_map<int, string>::iterator it;
    for(it = _map.begin(); it != _map.end(); ++it)
    {
        ofs << it->first << " " << it->second << endl;
    }

    ofs.close();
}


void Dict_productor::save_index(const string &filename)
{
    ofstream ofs(filename);
    if(!ofs.good())
    {
        cerr << "open " << filename << " error" << endl;
        return;
    }
    unordered_map<string, set<int>>::iterator it;
    for(it = _index.begin(); it != _index.end(); ++it)
    {
        ofs << it->first << " ";
        for(size_t idx : it->second)
        {
            ofs << idx << " ";
        }
        ofs << endl;
    }

    ofs.close();
}

void Dict_productor::read_cn_file(const string &filename)
{
    ifstream ifs(filename);
    if(!ifs.good())
    {
        cout << "open " << filename << " error" << endl;
        return;
    }

    string line;
    int id;
    while(getline(ifs, line))
    {
        vector<string> result = _jieba(line);
        for(string & elem : result)
        {
            if(elem.size() % CHSIZE == 0)
            {
                ++_dict[elem];
                id = _dict.size();
                _map[id] = elem;
                insertCnIndex(elem, id);
            }
         }   
    }
    ifs.close();
}

void Dict_productor::lowerLine(string &line)
{
    for(auto & elem : line)
    {
        if(!isalpha(elem))
        {
            elem = ' ';
        }
        else if(isupper(elem))
        {
            elem = tolower(elem);
        }
    }
}

void Dict_productor::insertEnIndex(const string &word, size_t id)
{
    for(auto & elem : word)
    {
        string ch(1,elem);
        _index[ch].insert(id);
    }
}

void Dict_productor::insertCnIndex(const string &elem, size_t id)
{
    vector<string> res;
    _jieba.CutSmall(elem, res, 1);
    for(string & it : res)
    {
        _index[it].insert(id); 
    }
}
