/*
 * Clase que permite almacenar en un solo condensado el nombre, el número de items y 
 * el número de LDC totales, base, eliminadas, modificadas y agregadas de una clase
 * 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de modificación: 12/03/2021
 */
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

/*
 * Constructor
 * Recibe el nombre de la clase, el número de items y el número de LDC totales, base, 
 * eliminadas, modificadas y agregadas
 */
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

/*
 * Devuelve el nombre de la clase
 */
string ClassEntry::getClassName()
{
    return className;
}

/*
 * Devuelve el número de LDC totales
 */
int ClassEntry::getTotal()
{
    return total;
}

/*
 * Devuelve el número de items
 */
int ClassEntry::getItems()
{
    return items;
}

/*
 * Devuelve el número de LDC base
 */
int ClassEntry::getBase()
{
    return base;
}

/*
 * Devuelve el número de LDC eliminadas
 */
int ClassEntry::getDeleted()
{
    return deleted;
}

/*
 * Devuelve el número de LDC modificadas
 */
int ClassEntry::getModified()
{
    return modified;
}

/*
 * Devuelve el número de LDC agregadas
 */
int ClassEntry::getAdded()
{
    return added;
}

/*
 * Actualiza el número de LDC totales
 */
void ClassEntry::setTotal(int total)
{
    this->total = total;
}

/*
 * Actualiza el número de items
 */
void ClassEntry::setItems(int items)
{
    this->items = items;
}

/*
 * Actualiza el número de LDC base
 */
void ClassEntry::setBase(int base)
{
    this->base = base;
}

/*
 * Actualiza el número de LDC eliminadas
 */
void ClassEntry::setDeleted(int deleted)
{
    this->deleted = deleted;
}

/*
 * Actualiza el número de LDC modificadas
 */
void ClassEntry::setModified(int modified)
{
    this->modified = modified;
}

/*
 * Actualiza el número de LDC agregadas
 */
void ClassEntry::setAdded(int added)
{
    this->added = added;
}

/*
 * Actualiza el número de items y el número LDC totales, base, eliminadas, modificadas y agregadas
 * Método utilizado cuando se lee un nuevo archivo de una clase con registros existentes
 */
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