#ifndef TYPE_H
#define TYPE_H

#include "mypch.h"

class BaseType
{
public:
    virtual void* allocate() = 0;
    virtual void* allocate(size_t size) = 0;
    virtual void deallocate(void* obj) = 0;
    virtual void construct(void*) = 0;
    virtual int size() = 0;
private:

};

template <typename T>
class Type : BaseType
{
public:
    void* allocate() override { return new char[sizeof(T)]; }
    void* allocate(size_t size) override { return new char[sizeof(T) * size]; }
    void deallocate(void* obj) override { delete (T*)obj; }
    int size() override { return sizeof(T); }
    void construct(void* address) { new (address) T(); }
private:
    T dummyData;
};

#endif