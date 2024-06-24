#include "../include/Dict_productor.h"
#include <iostream>

int main(int argc, char **argv)
{
    Dict_productor dict_productor;
    cout << "begin reading ..." << endl;
    dict_productor.read_en_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/EN/english.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0002.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0003.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0005.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0007.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0009.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0011.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0013.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0015.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0017.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0019.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0021.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0023.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0025.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0027.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0029.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0031.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0033.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0035.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0037.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0039.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0041.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0043.txt");
    dict_productor.read_cn_file("/home/wuyibo/homeworks/SearchEngine/offline/word/data/CN/art/C3-Art0045.txt");
    cout << "end reading ..." << endl;
    dict_productor.save_dict("/home/wuyibo/homeworks/SearchEngine/offline/word/data/dict.dat");
    dict_productor.save_idMap("/home/wuyibo/homeworks/SearchEngine/offline/word/data/idMap.dat");
    dict_productor.save_index("/home/wuyibo/homeworks/SearchEngine/offline/word/data/index.dat");
    return 0;
}

