#include <cstring>
#include "NDArray.cpp"
#include "reader.cpp"



unsigned char *pretreatment(const unsigned char *src, long &len)
{
    nda::NASProcessor *proc = new nda::NASProcessor();
    nda::NASReader *reader = new nda::NASReader(src, len);
    proc->loadReader(reader);
    
    return 0;
}