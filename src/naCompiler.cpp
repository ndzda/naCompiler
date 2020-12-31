#include "util.cpp"
#include "pretreatment.cpp"


int main(int argc,char *argv[])
{
    if(argc<=2)
    {
        error("Please enter the source code file name and output binary file name as startup parameters.");
        return 1;
    }

    unsigned char *srcC;
    long srcCLen=readBFile(argv[1],&srcC);
    if(srcCLen)
        error("File reading exception.");

    unsigned char *apSrcC=pretreatment(srcC,srcCLen);// 预处理

    return 0;
}