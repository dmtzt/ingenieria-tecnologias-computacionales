/*
 * Calcula una regresion multiple para estimar el numero de horas para un nuevo proyecto
 * con un numero determinado de LOC agregadas, reusadas y modificadas
 *
 * Utiliza datos almacenados en un archivo de horas de desarrollo y LOC agregadas, reusadas
 * y modificadas de proyectos anteriores para realizar el calculo
 * 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de modificación: 10/05/2021
 */
//.b=229

#ifndef FILEREADER_H
#define FILEREADER_H
#define INVALID_QUANTITY 0
#define B0 0
#define B1 1
#define B2 2
#define B3 3
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include "Errors.h"

using namespace std;

class FileReader 
{
    int n;
    double wk, xk, yk, zk; //.m
    double b0, b1, b2, b3; //.m
    double w, x, y, z; //.m
    vector<double> wArr, xArr, yArr, zArr; //.m
    vector<vector<double>> matrix;

    ifstream file;
    string line;
    vector<int> errorLog; 

    bool fileStatus;

    string fileName;
    
    //.d=6

    void gaussMethod();

    //.d=2
    double sum(vector<double>);
    double sumPow(vector<double>, int);
    double sumProduct(vector<double>, vector<double>);
    //.d=7

    public:
        void reset();
        void openFile(string);
        void readFile();
        void closeFile();
        bool getFileStatus();
        void pushError(int);
        //.d=1
        vector<int> getErrorLog(); 
        int getN();
        double getWk();
        double getXk();
        double getYk();
        double getZk();
        double getB0();
        double getB1();
        double getB2();
        double getB3();
        //.d=3
};

/*
 * Reinicia todas las variables de la clase utilizadas durante la ejecución
*/
//.i
void FileReader::reset()
{
    //.d=1
    n = 0;
    wk = xk = yk = zk = 0.0; //.m
    w = x = y = z = 0.0; //.m
    //.d=5
    b0 = b1 = b2 = b3= 0.0; //.m
    wArr.clear();
    xArr.clear();
    yArr.clear();
    zArr.clear();
}

//.i
void FileReader::openFile(string fileName)
{
    this->fileName = fileName;
    // Get class name from the given file name
    file.open(fileName);
    if (file)
        fileStatus = true;
    else
    {
        fileStatus = false;
        pushError(ERROR_FILE_NOT_EXISTS); 
    }    
}

/*
 * Método central de la clase
 * Calcula una regresion multiple para estimar el numero de horas para un nuevo proyecto
 * con un numero determinado de LOC agregadas, reusadas y modificadas
 *
 * Utiliza datos almacenados en un archivo de horas de desarrollo y LOC para obtener
 * los coeficientes de los valores Beta a partir de una regresion multiple con el metodo
 * de Gauss Jordan.
 */
//.i
void FileReader::readFile()
{    
    // File is empty: update error log
    if (file.peek() == std::ifstream::traits_type::eof())
    {
        pushError(ERROR_FILE_EMPTY); 
        return;
    }

    string value;

    if (!file.eof())
    {
        // Read line
        getline(file, line);

        stringstream ss(line);

        if (getline(ss, value, ','))
            wk = stod(value);
        
        if (getline(ss, value, ','))
            xk = stod(value);
        
        if (getline(ss, value, ','))
            yk = stod(value);
        //.d=11
    }
        
    // Ready line by line
    while (!file.eof())
    {
        //.d=29
        vector<double> row;

        // Read line
        getline(file, line);

        stringstream ss(line);

        if (getline(ss, value, ','))
        {
            w = stod(value);
            wArr.push_back(w);
        }   
            
        
        if (getline(ss, value, ','))
        {
            x = stod(value);
            xArr.push_back(x);
        }
            
        
        if (getline(ss, value, ','))
        {
            y = stod(value);
            yArr.push_back(y);
        }
            

        if (getline(ss, value, ','))
        {
            z = stod(value);
            zArr.push_back(z);
        }
    }

    n = wArr.size();

    // Row 1
    vector<double> row1;
    row1.push_back(n);
    row1.push_back(sum(wArr));
    row1.push_back(sum(xArr));
    row1.push_back(sum(yArr));
    row1.push_back(sum(zArr));
    //row1.push_back(0);
    matrix.push_back(row1);

    // Row 2
    vector<double> row2;
    row2.push_back(sum(wArr));
    row2.push_back(sumPow(wArr, 2));
    row2.push_back(sumProduct(wArr, xArr));
    row2.push_back(sumProduct(wArr, yArr));
    row2.push_back(sumProduct(wArr, zArr));
    // row2.push_back(0);
    matrix.push_back(row2);

    // Row 3
    vector<double> row3;
    row3.push_back(sum(xArr));
    row3.push_back(sumProduct(wArr, xArr));
    row3.push_back(sumPow(xArr, 2));
    row3.push_back(sumProduct(xArr, yArr));
    row3.push_back(sumProduct(xArr, zArr));
    // row3.push_back(0);
    matrix.push_back(row3);

    // Row 4
    vector<double> row4;
    row4.push_back(sum(yArr));
    row4.push_back(sumProduct(wArr, yArr));
    row4.push_back(sumProduct(xArr, yArr));
    row4.push_back(sumPow(yArr, 2));
    row4.push_back(sumProduct(yArr, zArr));
    // row4.push_back(0);
    matrix.push_back(row4);

    gaussMethod();

    zk = b0 + wk * b1 + xk * b2 + yk * b3;

    //.d=16
}

//.d=5

/*
 * Agrega errores al log de errores
 */
//.i
void FileReader::pushError(int error)
{
    errorLog.push_back(error);
}

/*
 * Cierra el archivo abierto en cuestión
 */
//.i
void FileReader::closeFile()
{
    file.close();
}

/*
 * Devuelve el status del archivo
 * True: el archivo fue abierto exitosamente
 * False: el archivo no fue abierto porque no existe
*/
//.i
bool FileReader::getFileStatus()
{
    return fileStatus;
}

vector<int> FileReader::getErrorLog()
{
    return errorLog;
}

/*
 * Resuelve un sistema de ecuaciones de 4 incognitas utilizando el metodo
 * de Gauss Jordan y los almacena en las variables b0-b3.
 *
 * Utiliza los coeficientes de los valores Beta, los cuales fueron obtenidos a partir de
 * los valores leídos del archivo de entrada.
*/
//.i
void FileReader::gaussMethod()
{
    const int matrix_size = 4;
    vector<double> x(matrix_size);

    for (int i = 0; i < matrix_size; i++)
	{
	    for (int j = 0; j < matrix_size; j++)
		{
            if (i != j)
            {
                double ratio = matrix[j][i] / matrix[i][i];

                for (int k = 0; k < matrix_size + 1; k++)
                    matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
            }
        }
    }

    for (int i = 0; i < matrix_size; i++)
        x[i] = matrix[i][matrix_size] / matrix[i][i];

    b0 = x[B0];
    b1 = x[B1];
    b2 = x[B2];
    b3 = x[B3];
}

//.d=4

/*
 * Calcula la sumatoria de un conjunto dado de valores de tipo double
 */
//.i
double FileReader::sum(vector<double> arr)
{
    double s = 0;
    for (double d : arr)
        s += d;
    
    return s;
}

/*
 * Calcula la sumatoria de un conjunto dado de valores de tipo double elevados a cierta potencia
 */
//.i
double FileReader::sumPow(vector<double> arr, int exp)
{
    double s = 0;
    for (double d : arr)
        s += pow(d, exp);
        
    return s;
}

/*
 * Calcula la sumatoria del producto escalar de dos conjuntos dados de valores de tipo double
 */
//.i
double FileReader::sumProduct(vector<double> arr1, vector<double> arr2)
{
    double s;

    for (int i = 0; i < arr1.size(); i++)
        s += arr1[i] * arr2[i];

    return s;
}

//.d=31

int FileReader::getN()
{
    return n;
}

//.d=4

double FileReader::getWk()
{
    return wk;
}

double FileReader::getXk() //.m
{
    return xk;
}

double FileReader::getYk()
{
    return yk;
}

double FileReader::getZk()
{
    return zk;
}

double FileReader::getB0()
{
    return b0;
}

double FileReader::getB1()
{
    return b1;
}

double FileReader::getB2()
{
    return b2;
}

double FileReader::getB3()
{
    return b3;
}
#endif