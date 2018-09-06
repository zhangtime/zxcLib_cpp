#include "Exception.h"
#include <cstring>
#include <cstdlib>
#include <string.h>

using namespace std;

namespace zxcLib {



#define strdup _strdup
#define itoa   _itoa_s
//#define strcpy   strcpy_s
//#define strcat   strcat_s



void Exception::init(const char *message,const char *file,int line)
{
    m_message = (message ? strdup(message) : NULL);

    if(NULL != file)
    {
        char s_line[16] = {0};

        itoa(line,s_line,10);

        m_location = static_cast<char*>(malloc(strlen(file)+strlen(s_line)+2));
        if(NULL != m_location)
        {
            m_location = strcpy(m_location,file);
            m_location = strcat(m_location,":");
            m_location = strcat(m_location,s_line);
        }

    }
    else
    {
        m_location = NULL;
    }
}

Exception::Exception(const char* message)
{
    init(message,NULL,0);

}

Exception::Exception(const char* file,int line)
{
    init(NULL,file,line);
}

Exception::Exception(const char* message,const char* file,int line)
{
    init(message,file,line);
}

Exception::Exception(const Exception& e)
{
    m_message = strdup(e.m_message);
    m_location = strdup(e.m_location);
}

Exception& Exception::operator =(const Exception &e)
{
    if(this != &e)
    {
        free(m_message);
        free(m_location);

        m_message = strdup(e.m_message);
        m_location = strdup(e.m_location);
    }

    return *this;
}

const char* Exception::get_message() const
{
    return m_message;
}

const char* Exception::get_location() const
{
    return m_location;
}


}
