#ifndef CLASSENTRY_H
#define CLASSENTRY_H
#include <string>

using namespace std;

class ClassEntry
{
private:
    string className;
    int total;
    int items;
    int base;
    int deleted;
    int modified;
    int added;

public:
    ClassEntry(string, int, int, int, int, int, int);
    string getClassName();
    int getTotal();
    int getItems();
    int getBase();
    int getDeleted();
    int getModified();
    int getAdded();
    void setTotal(int);
    void setItems(int);
    void setBase(int);
    void setDeleted(int);
    void setModified(int);
    void setAdded(int);
    void updateCounters(int, int, int, int, int, int);
};

//.i
ClassEntry::ClassEntry(string className, int total, int items, int base, int deleted, int modified, int added)
{
    this->className = className;
    this->total = total;
    this->items = items;
    this->base = base;
    this->deleted = deleted;
    this->modified = modified;
    this->added = added;
}

string ClassEntry::getClassName()
{
    return className;
}

int ClassEntry::getTotal()
{
    return total;
}

int ClassEntry::getItems()
{
    return items;
}

int ClassEntry::getBase()
{
    return base;
}

int ClassEntry::getDeleted()
{
    return deleted;
}

int ClassEntry::getModified()
{
    return modified;
}

int ClassEntry::getAdded()
{
    return added;
}

void ClassEntry::setTotal(int total)
{
    this->total = total;
}

void ClassEntry::setItems(int items)
{
    this->items = items;
}

void ClassEntry::setBase(int base)
{
    this->base = base;
}

void ClassEntry::setDeleted(int deleted)
{
    this->deleted = deleted;
}

void ClassEntry::setModified(int modified)
{
    this->modified = modified;
}

void ClassEntry::setAdded(int added)
{
    this->added = added;
}

//.i
void ClassEntry::updateCounters(int total, int items, int base, int deleted, int modified, int added)
{
    this->total = total;
    this->items = items;
    this->base = base;
    this->deleted = deleted;
    this->modified = modified;
    this->added = added;
}
#endif