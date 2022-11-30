// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <locale>
#include <math.h>
using namespace std;

//If user enter incorrect value, for example, character, then program should generate exception.
void checkValidInput()
{
    if (cin.fail())
    {
        throw "Incorrect input";
    }
}

//If user enter incorrect value for from, step or n; for example, the value of n is less than 3, 
//then program should generate exception.
void checkValidParams(double from, double to, double step, int n)
{
    if (from >= to || step <= 0 || n < 3)
    {
        throw "Input correct data";
    }
}

//The function “Calculate” shows how to calculate value on definite range of expression from lab 2
double calculate(double from, double to, double step, double& x, int n)
{
    if (x < 0)
    {
        double y = 0;
        for (int i = 0; i <= n; i++)
        {
            double p = 1;
            for (int j = i; j <= n - 1; j++)
            {
                p *= (pow(i, i) + j);
            }
            y += p;
        }
        return y;
    }
    else
    {
        double y = 0;
        for (int i = 1; i <= n - 2; i++)
        {
            y += (i - x);
        }
        return y;
    }
}

//The “Main” function
int main()
{
    double from, to, step, x, y;
    int n;
    bool value;
    ofstream fout("result.txt");
    try
    {
        cout << "Enter from = ";
        cin >> from;
        cout << "Enter to = ";
        cin >> to;
        cout << "Enter step = ";
        cin >> step;
        cout << "Enter n = ";
        cin >> n;
        checkValidInput();
        checkValidParams(from, to, step, n);

        //Save on file "result.txt" from, to, step and n if user enters 1
        cout << "Enter 1 if you want to save from, to, step and n on file" << endl;
        cout << "Enter 0 if you don't want to save from, to, step and n on file" << endl;
        cin >> value;
        if (value)
        {
            fout << "from = " << from << endl;
            fout << "to = " << to << endl;
            fout << "step = " << step << endl;
            fout << "n = " << n << endl;
        }
        //Save on file "result.txt" the result of every step if user enters 1
        cout << "Enter 1 if you want to save the result of every step on file" << endl;
        cout << "Enter 0 if you don't want to save the result of every step on file" << endl;
        cin >> value;
        for (x = from; x <= to; x += step)
        {
            cout << " x = " << x << "; " << "y = " << calculate(from, to, step, x, n) << endl;
            if (value)
            {
                fout << "x = " << x << "; ";
                fout << "y = " << calculate(from, to, step, x, n) << " " << endl;
            }
        }
       
    }
    catch (const char* ex)
    {
        cout << ex << endl;
        return -1;
    }
    catch (...)
    {
        cout << "Unknown error" << endl;
        return -2;
    }

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
