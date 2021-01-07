#include <cstring>
#include "NDArray.cpp"
#include "reader.cpp"



nda::DArray<char *> RefDocString; // Processed file 处理后的文件
nda::DArray<long> RefDocLen;      // The length of each string in the processed file array 处理后的文件数组中每一个字符串的长度

unsigned char *pretreatment(const unsigned char *src, long &len)
{
    nda::NASProcessor proc = nda::NASProcessor();
    nda::NASReader reader = nda::NASReader(src, len);
    
    return 0;
}