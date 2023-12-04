#include <bits/stdc++.h>
using namespace std;
/*
E -> TE'
T -> +TE'|e
T' -> *FT'|e
F -> (E)|id
*/
void advance(int *curr);
void E(string input, int *curr);
void T(string input, int *curr);
void Edash(string input, int *curr);
void Tdash(string input, int *curr);
void F(string input, int *curr);
int main()
{
    string input;
    cout << "Enter the expression" << endl;
    cin >> input;
    int curr = 0;
    E(input, &curr);
    if (curr == input.size())
    {
        cout << "String is matched" << endl;
    }
    else
    {
        cout << "String is not matched" << endl;
    }
    return 0;
}
void advance(int *curr)
{
    *curr += 1;
}
void E(string input, int *curr)
{
    cout << "E" << input[*curr] << " " << *curr << endl;
    T(input, curr);
    Edash(input, curr);
}
void T(string input, int *curr)
{
    cout << "T" << input[*curr] << " " << *curr << endl;
    F(input, curr);
    Tdash(input, curr);
}
void Edash(string input, int *curr)
{
    cout << "Edash" << input[*curr] << " " << *curr << endl;
    if (input[*curr] == '+')
    {
        advance(curr);
        T(input, curr);
        Edash(input, curr);
    }
}
void Tdash(string input, int *curr)
{
    cout << "Tdash" << input[*curr] << " " << *curr << endl;
    if (input[*curr] == '*')
    {
        advance(curr);
        F(input, curr);
        Tdash(input, curr);
    }
}
void F(string input, int *curr)
{
    cout << "F" << input[*curr] << " " << *curr << endl;
    if (input[*curr] == '(')
    {
        advance(curr);
        E(input, curr);
        if (input[*curr] == ')')
        {
            advance(curr);
        }
        else
        {
            cout << "String is not matched";
            exit(1);
        }
    }
    else if (input[*curr] == 'i' && input[*curr + 1] == 'd')
    {
        advance(curr);
        advance(curr);
    }
    else
    {
        cout << "String is not matched" << endl;
        exit(1);
    }
}