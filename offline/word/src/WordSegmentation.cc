#include "../include/WordSegmentation.h"


WordSegmentation::~WordSegmentation()
{

}

vector<string> WordSegmentation::operator()(const string s)
{
    vector<string> vec;
    _jieba.CutAll(s, vec);
    return vec;
}

void WordSegmentation::CutSmall(const string & str, vector<string> & vec, size_t sz)
{
    _jieba.CutSmall(str, vec, sz);   
}
