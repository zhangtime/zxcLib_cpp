#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string.h>
#include "Object.h"
using namespace std;



namespace zxcLib
{

#define THROW_EXCEPTION(E,M)   (throw E(M,__FILE__,__LINE__))

class Exception : public Object
{
protected:
    char* m_message;
    char* m_location;

    void init(const char* meaage,const char* file,int line);

public:
    Exception(const char* message);
    Exception(const char* file,int line);
    Exception(const char* message,const char* file,int line);

    Exception(const Exception& e);
    Exception& operator= (const Exception& e);

    virtual const char* get_message() const;
    virtual const char* get_location() const;

    ~Exception()
    {
        ;
    }

};

class ArithmeticException : public Exception
{
public:
    ArithmeticException() : Exception(NULL,NULL,0){}
    ArithmeticException(const char* message) : Exception(message,NULL,0){}
    ArithmeticException(const char* file,int line) : Exception(NULL,file,line){}
    ArithmeticException(const char* message,const char* file,int line) : Exception(message,file,line)
    {
         Exception::Exception("ArithmeticException",file,line);
    }

    ArithmeticException(const ArithmeticException& e) : Exception(e){}
    ArithmeticException& operator =(const ArithmeticException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

class IndexOutOfBoundsException : public Exception
{
public:
    IndexOutOfBoundsException() : Exception(NULL,NULL,0){}
    IndexOutOfBoundsException(const char* message) : Exception(message){}
    IndexOutOfBoundsException(const char* file,int line) : Exception(file,line){}
    IndexOutOfBoundsException(const char* message,const char* file,int line) : Exception(message,file,line){}

    IndexOutOfBoundsException(IndexOutOfBoundsException& e):Exception(e){}
    IndexOutOfBoundsException& operator =(const IndexOutOfBoundsException& e)
    {
        Exception::operator=(e);

        return *this;
    }

};

class NoEnoughMemoryException : public Exception
{
public:
    NoEnoughMemoryException():Exception(NULL,NULL,0){}
    NoEnoughMemoryException(const char* message):Exception(message){}
    NoEnoughMemoryException(const char* file,int line):Exception(file,line){}

    NoEnoughMemoryException(const char* message,const char* file,int line):Exception(message,file,line){}
    NoEnoughMemoryException(NoEnoughMemoryException& e):Exception(e){}

    NoEnoughMemoryException& operator =(NoEnoughMemoryException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

class InvalidParameterException : public Exception
{
public:
    InvalidParameterException():Exception(NULL,NULL,0){}
    InvalidParameterException(const char* message):Exception(message){}
    InvalidParameterException(const char* file,int line):Exception(file,line){}
    InvalidParameterException(const char* message,const char* file,int line):Exception(message,file,line){}

    InvalidParameterException(InvalidParameterException& e):Exception(e){}

    InvalidParameterException& operator =(InvalidParameterException& e)
    {
        Exception::operator =(e);

        return *this;
    }

};

class NullPointerException : public Exception
{
public:
    NullPointerException() :Exception (NULL,NULL,0) {}
    NullPointerException(const char* message):Exception(message){}
    NullPointerException(const char* file,int line):Exception(file,line){}

    NullPointerException(const char* message,const char* file,int line):Exception(message,file,line){}
    NullPointerException(NullPointerException& e):Exception(e){}

    NullPointerException& operator =(NullPointerException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

class InvalidOperatorException : public Exception
{
public:
    InvalidOperatorException():Exception(NULL,NULL,0){}
    InvalidOperatorException(const char* message):Exception(message){}
    InvalidOperatorException(const char* file,int line):Exception(file,line){}
    InvalidOperatorException(const char* message,const char* file,int line):Exception(message,file,line){}

    InvalidOperatorException(InvalidOperatorException& e):Exception(e){}

    InvalidOperatorException& operator =(InvalidOperatorException& e)
    {
        Exception::operator =(e);

        return *this;
    }

};

}
#endif // EXCEPTION_H
