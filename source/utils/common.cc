#include "common.h"

char buffer[1024];

char *va(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    if (strlen(fmt) >= 1024)
    {
        // LogInfo("va size > 1024\n");
        va("va size > 1024\n");
        return buffer;
    }
    int ret = vsnprintf(buffer, 1024, fmt, args);
    va_end(args);
    return buffer;
}

/*
1 2 | 3
0 1 2 3

2
2  0  -> 12
2  3

*/
void splitStr(const std::string &str, const std::string &cut, std::vector<std::string> &strArray)
{
    // strArray.clear();

    // std::string::size_type pos, prev = 0;
    // while ((pos = str.find_first_of(cut, prev)) != std::string::npos)
    // {
    //     if (pos > prev)
    //     {
    //         if (1 == pos - prev)
    //             break;
    //         strArray.emplace_back(str, prev, pos - prev);
    //     }
    //     prev = pos + 1;
    // }

    // if (prev < str.size())
    // {
    //     strArray.emplace_back(str, prev, str.size() - prev);
    // }

    char *tok;
    const int size = str.size();
    static char* cchars = new char(size + 1);
   // char cchars[size + 1];
    char *cstr = &cchars[0];
    strcpy(cstr, str.c_str());
    tok = strtok(cstr, cut.c_str());
    while (tok != NULL)
    {
        strArray.push_back(tok);
        tok = strtok(NULL, cut.c_str());
    }
}
