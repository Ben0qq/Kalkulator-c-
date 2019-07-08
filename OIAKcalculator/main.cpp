#include <QCoreApplication>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "czas.h"
using namespace std;

void multiply () {
    string number1;
    string number2;
    string resultstr;
    int digit;
    char resultdigit=0;
    fstream file, res;
    file.open("number.txt", ios::in);
    res.open("result.txt",ios::out | ios::app);
    if(file.good() == true)
    {
        while(!file.eof())
        {
            char sign1=0, sign2=0;
            int digit1=0, digit2=0, result =0, carry=0, addCarry=0, position=0;
            getline(file, number1);
            getline(file, number2);
            for(int i=0; i<number1.length()+number2.length();i++)
            {
                resultstr.insert(0,"0");
            }
            for(int i=0; i<number2.length();i++)
            {
                sign1=number2.at(number2.length()-1-i);
                digit1=sign1-'0';
                carry=0;
                for(int j=0; j<number1.length(); j++)
                {
                    sign2=number1.at(number1.length()-1-j);
                    digit2=sign2-'0';
                    result=digit2*digit1;
                    result+=carry;
                    carry=result/10;
                    digit=result%10;
                    //generating result
                    resultdigit=resultstr.at(number1.length()+number2.length()-1-j-position);
                    int temp =resultdigit-'0';
                    resultdigit=((temp+digit+addCarry)%10);
                    addCarry=(temp+digit+addCarry)/10;
                    resultstr.replace(number1.length()+number2.length()-1-j-position,1,to_string(resultdigit));
                }
                resultstr.replace(number2.length()-1-position,1,to_string(carry+addCarry));
                position++;
            }
        }
        res<<resultstr<<endl;
        cout<<resultstr<<endl;
        res.close();
        file.close();
    }
}

string multiply (string number1,string number2) {
    string resultstr;
    int digit;
    char resultdigit=0;
            char sign1=0, sign2=0;
            int digit1=0, digit2=0, result =0, carry=0, addCarry=0, position=0;
            for(int i=0; i<number1.length()+number2.length();i++)
            {
                resultstr.insert(0,"0");
            }
            for(int i=0; i<number2.length();i++)
            {
                sign1=number2.at(number2.length()-1-i);
                digit1=sign1-'0';
                carry=0;
                for(int j=0; j<number1.length(); j++)
                {
                    sign2=number1.at(number1.length()-1-j);
                    digit2=sign2-'0';
                    result=digit2*digit1;
                    result+=carry;
                    carry=result/10;
                    digit=result%10;
                    //generating result
                    resultdigit=resultstr.at(number1.length()+number2.length()-1-j-position);
                    int temp =resultdigit-'0';
                    resultdigit=((temp+digit+addCarry)%10);
                    addCarry=(temp+digit+addCarry)/10;
                    resultstr.replace(number1.length()+number2.length()-1-j-position,1,to_string(resultdigit));
                }
                resultstr.replace(number2.length()-1-position,1,to_string(carry+addCarry));
                position++;
    }
            return resultstr;
}

string subtract (string number1, string number2)
{
    //in square root subtracting you never get negative number
    char sign1=0, sign2=0;
    int digit1=0, digit2=0;
    int carry=0;
    for(int i = 0; i<number1.length()-number2.length();i++)
    {
        number2.insert(0,"0");
    }
    for(int i = 0; i<number1.length();i++)
    {
        sign1=number1.at(number1.length()-1-i);
        digit1=sign1-'0';
        sign2=number2.at(number2.length()-1-i);
        digit2=sign2-'0';
        if(digit2+carry>digit1)
        {
            digit1+=10;
            digit1=digit1-digit2-carry;
            carry=1;
        }
        else {
           digit1=digit1-digit2-carry;
           carry=0;
        }
        number1.replace(number1.length()-1-i,1,to_string(digit1));
    }
    return number1;
}

string add (string number1, string number2)
{
    //adding when number1>=number2
    char sign1=0, sign2=0;
    int digit1=0, digit2=0;
    int carry=0;
    int iterator=number1.length()-number2.length();
    for(int i = 0; i<iterator;i++)
    {
        number2.insert(0,"0");
    }
    for(int i = 0; i<number1.length();i++)
    {
        sign1=number1.at(number1.length()-1-i);
        digit1=sign1-'0';
        sign2=number2.at(number1.length()-1-i);
        digit2=sign2-'0';
        int result =digit1+digit2+carry;
        carry=result/10;
        number1.replace(number1.length()-1-i,1,to_string(result%10));
    }
    if(carry>0)
    number1.insert(0,to_string(carry));
    return number1;
}

void squareRoot ()
{
    string number1;
    string resultstr;
    int precision = 600;
    precision=precision*2;
    string partialRes;
    fstream file, res;
    file.open("numbersqrt.txt", ios::in);
    res.open("resultsqrt.txt",ios::out | ios::app);
    if(file.good() == true)
    {
        while(!file.eof())
        {
            getline(file, number1);
            int length = number1.length();
            if(length%2==1)
            {
                number1.insert(0,"0");
            }
            length = number1.length();
            for(int i=0;i<precision*2-length;i++)
            {
                number1.append("0");
            }
            partialRes.append(to_string(number1.at(0)-'0'));
            partialRes.append(to_string(number1.at(1)-'0'));
            int number =stoi(partialRes);
            int digit=0;
            for(int i=0;i<11;i++)
            {
                if(number<i*i)
                {
                    digit=i-1;
                    partialRes=subtract(partialRes,to_string((i-1)*(i-1)));
                    break;
                }
            }
            resultstr.append(to_string(digit));
            for(int i=2; i<precision; i+=2)
            {
                partialRes.append(to_string(number1.at(i)-'0'));
                partialRes.append(to_string(number1.at(i+1)-'0'));
                string temp;
                for(int j=0;j<11;j++)
                {
                    temp=multiply(add(multiply(resultstr,"20"),to_string(j)),to_string(j));
                    while(temp.length()<i+2)
                    {
                        temp.insert(0,"0");
                    }
                    if(temp>partialRes)
                    {
                        temp=multiply(add(multiply(resultstr,"20"),to_string(j-1)),to_string(j-1));
                        while(temp.length()<i+2)
                        {
                            temp.insert(0,"0");
                        }
                        partialRes=subtract(partialRes,temp);
                        digit=j-1;
                        resultstr.append(to_string(digit));
                        break;
                    }

                }
            }
            if(resultstr.length()>length/2)
            resultstr.insert(length/2,",");
        res<<resultstr<<endl;
        cout<<resultstr<<endl;
        res.close();
        file.close();
        }
    }
}

int main()
{
    cout<<"Wybierz operacje: \n1.Mnozenie \n2.Pierwiastek\n";
    int x=0;
    cin>>x;
    czas czas;
    switch (x)
    {
    case 1:
        czas.czasStart();
        multiply();
        czas.czasStop();
        cout<<"Czas wykonania (mikrosekundy): "<<czas.czasWykonania()<<endl;
        break;
    case 2:
        czas.czasStart();
        squareRoot();
        czas.czasStop();
        cout<<"Czas wykonania (mikrosekundy): "<<czas.czasWykonania()<<endl;
        break;
    default:
        cout<<"Zla komenda";
    }
}

