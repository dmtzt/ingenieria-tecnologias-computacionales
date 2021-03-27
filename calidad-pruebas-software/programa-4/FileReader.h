/*
 * 1. Calcula una regresión lineal a partir de un conjunto de datos extraídos de un archivo dado
 * 2. Aplica dicha regresión para utilizar el método PROBE A, el cual es usado para realizar
 * predicciones de tamaño y tiempo de elaboración de código con base en datos históricos
 * 
 * David Alejandro Martínez Tristán A01610267
 * Fecha de modificación: 20/03/2021
 */
//.b=225

#ifndef FILEREADER_H
#define FILEREADER_H
#define INVALID_QUANTITY 0
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include "Errors.h"
#include "NumericalMethods.h"


using namespace std;

class FileReader 
{
    NumericalMethods nm;
    ifstream file;
    string line;
    vector<int> errorLog;
    bool fileStatus;
    string fileName;
    double x;
    int dof;

    int pos;
    int n;
    int xk;
    double x, y;
    double xSum, ySum, xySum, x2Sum, y2Sum;
    double xAvg, yAvg, x2Avg;
    double r, r2;
    double b0, b1;
    double yk;
    string substr;
    vector<double> xArr, yArr;

    double avg(vector<double>);
    double avgPow(vector<double>, int);
    double sum(vector<double>);
    double sumPow(vector<double>, int);
    double sumProduct(vector<double>, vector<double>);
    bool isDouble(string);
    double ceilDecimals(double);
    double calculateB1();
    double calculateB0();
    double calculateR();
    double calculateR2();
    double calculateYk();

    public:
        void reset();
        void openFile(string);
        void readFile();
        void closeFile();
        bool getFileStatus();
        void pushError(int);
        string removeSpaces(string);
        vector<int> getErrorLog();
        int getN();
        int getXk();
        double getR();
        double getR2();
        double getB0();
        double getB1();
        double getYk();
};

/*
 * Reinicia todas las variables de la clase utilizadas durante la ejecución
*/
//.i
void FileReader::reset()
{
    pos = 0;
    n = 0;
    xk = 0;
    x = y = 0.0;
    xySum = 0.0;
    xSum = ySum = xySum = x2Sum = y2Sum = 0.0;
    xAvg = yAvg = x2Avg = 0.0;
    r = r2 = 0.0;
    b0 = b1 = 0.0;
    yk = 0.0;
    xArr.clear();
    yArr.clear();
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
 * 1. Lee el valor xk
 * 2. Lee un conjunto de pares ordenados (x,y) hasta el final del archivo
 * 3. Calcula una regresión lineal con base en los datos extraídos
 * Maneja adecuadamente errores cuando un valor no existe, no es numérico o es negativo
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

    // Get xk
    if (!file.eof())
    {
        // Read first line
        getline(file, line);
        // Remove initial whitespaces
        line = removeSpaces(line);

        // End: xk does not exist
        if (line.empty())
        {
            pushError(ERROR_XK_NOT_EXISTS);
            return;
        }

        // Verify that xk exists and has the correct format
        for (char c : line)
        {
            // End: xk does nt exists or does not have the correct format
            if (!isdigit(c))
            {
                if (c == ',')
                    pushError(ERROR_XK_NOT_EXISTS);
                else
                    pushError(ERROR_XK_NOT_NUM);
                return;
            }
        }

        // Convert string to int
        xk = stoi(line);
    }
        
    // Ready line by line
    while (!file.eof())
    {
        // Read line
        getline(file, line);
        // Remove initial whitespace
        line = removeSpaces(line);
        
        // Line is not empty
        if (line.length() > 0)
        {
            // Get first token
            pos = line.find(',');
            substr = line.substr(0, pos);
            substr = removeSpaces(substr);

            // Check that value exists
            if (substr.empty())
            {
                pushError(ERROR_VALUE_NOT_EXISTS);
                continue;
            }

            // Check that token contains a floating point value
            if (!isDouble(substr))
            {
                pushError(ERROR_VALUE_NOT_NUM);
                continue;
            }
            
            // Convert from string to double
            x = stod(substr);

            // Check that value is positive or zero
            if (x < 0)
            {
                pushError(ERROR_VALUE_NEGATIVE);
                continue;
            }

            // Get second token
            if (pos + 1 == line.length())
            {
                pushError(ERROR_VALUE_NOT_EXISTS);
                continue;
            }

            substr = line.substr(pos + 1);

            // Check that token contains a floating point value
            if (!isDouble(substr))
            {
                pushError(ERROR_VALUE_NOT_NUM);
                continue;
            }

            // Convert from string to double
            y = stod(substr);

            // Check that value is positive or zero
            if (y < 0)
            {
                pushError(ERROR_VALUE_NEGATIVE);
                continue;
            }

            // Add values to its corresponding arrays
            xArr.push_back(x);
            yArr.push_back(y);

            // Update number of pairs
            n++;    
        }
    }

    if (n == 0)
    {
        errorLog.push_back(ERROR_NO_PAIRS);
        return;
    }
    xSum = sum(xArr);
    ySum = sum(yArr);
    xySum = sumProduct(xArr, yArr);
    x2Sum = sumPow(xArr, 2);
    y2Sum = sumPow(yArr, 2);
    xAvg = avg(xArr);
    yAvg = avg(yArr);
    x2Avg = pow(xAvg, 2);

    b1 = ceilDecimals(calculateB1());
    b0 = ceilDecimals(calculateB0());
    r = ceilDecimals(calculateR());
    r2 = ceilDecimals(calculateR2());
    yk = ceilDecimals((calculateYk()));
}

/*
 * Elimina los primeros espacios vacíos consecutivos hallados en una línea dada
 * Método utilizado para facilitar la extracción de datos
 */
//.i
string FileReader::removeSpaces(string line)
{
    if (line.length() > 0)
    {
        // Remove all spaces and tabs from indentation
        while(line[0] == ' ' || line[0] == '\t')
            line.erase(line.begin());
    }

    return line;
}

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
 * Calcula el promedio de un conjunto dado de valores de tipo double dado
 */
//.i
double FileReader::avg(vector<double> arr)
{    
    return sum(arr) / arr.size();
}

/*
 * Calcula el promedio de un conjunto dado de valores de tipo double elevados a cierta potencia
 */
//.i
double FileReader::avgPow(vector<double> arr, int exp)
{   
    return sumPow(arr, exp) / arr.size();
}

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

/*
 * Calcula el valor b1 utilizado para calcular la regresión lineal
 * Utiliza la fórmula especificada en los requerimientos
 */
//.i
double FileReader::calculateB1()
{
    double num = xySum - n * xAvg * yAvg;
    double denom = x2Sum - n * x2Avg;

    if (denom == 0)
    {
        errorLog.push_back(ERROR_DIVISION_BY_ZERO);
        return INVALID_OPERATION;
    }

    return num / denom;
}

/*
 * Calcula el valor b0 utilizado para calcular la regresión lineal
 * Utiliza la fórmula especificada en los requerimientos
 */
//.i
double FileReader::calculateB0()
{
    return yAvg - b1 * xAvg;
}

/*
 * Calcula el valor r utilizado para calcular la regresión lineal
 * Utiliza la fórmula especificada en los requerimientos
 */
//.i
double FileReader::calculateR()
{
    double num = n * xySum - xSum * ySum;
    double denom = sqrt((n * x2Sum - pow(xSum, 2)) * (n * y2Sum - pow(ySum, 2)));

    if (denom == 0)
    {
        errorLog.push_back(ERROR_DIVISION_BY_ZERO);
        return INVALID_OPERATION;
    }

    return num / denom;
}

/*
 * Calcula el valor r^2 utilizado para calcular la regresión lineal
 * Utiliza la fórmula especificada en los requerimientos
 */
//.i
double FileReader::calculateR2()
{
    return r * r;
}

/*
 * Calcula la regresión lineal
 * Utiliza la fórmula especificada en los requerimientos
 */
//.i
double FileReader::calculateYk()
{
    return b0 + b1 * xk;
}

/*
 * Verifica si un string contiene caracteres propios de un double
 * Utilizada para asegurar una conversión correcta de string a double
 */
//.i
bool FileReader::isDouble(string s)
{
    for (char c : s)
    {
        if (!isdigit(c) && c != '-' && c != '.')
            return false;
    }

    return true;
}

/*
 * Redondea un valor de tipo double a 5 decimales hacia arriba según la especificación
 */
//.i
double FileReader::ceilDecimals(double d)
{
    string s = to_string(d);

    if (s[s.size() - 1] >= '5')
    {
        s[s.size() - 1] = '0';
        s[s.size() - 2] = s[s.size() - 2] + 1;
    }
    
    return stod(s);
}

//.d=14
#endif