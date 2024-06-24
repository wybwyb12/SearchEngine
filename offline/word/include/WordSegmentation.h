#ifndef __WORDSEGMENTATION_H__
#define __WORDSEGMENTATION_H__

#include "cppjieba/Jieba.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;


const char* const DICT_PATH = "include/cppjieba/dict/jieba.dict.utf8";
const char* const HMM_PATH = "include/cppjieba/dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "include/cppjieba/dict/user.dict.utf8";
const char* const IDF_PATH = "include/cppjieba/dict/idf.utf8";
const char* const STOP_WORD__PATH = "include/cppjieba/dict/stop_words.utf8";

class WordSegmentation
{
public:
    WordSegmentation()
    : _jieba(DICT_PATH,
            HMM_PATH,
            USER_DICT_PATH,
            IDF_PATH,
            STOP_WORD__PATH)
    {

    }
    ~WordSegmentation();
    vector<string> operator()(const string str);
    void CutSmall(const string & str, vector<string> & vec, size_t sz);

private:
    cppjieba::Jieba _jieba;
};

#endif

