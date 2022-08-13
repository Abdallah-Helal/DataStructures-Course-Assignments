#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include"BigInt.h"
using namespace std;

bool removeSign(BigInt& ob)
{
    string s = "";

    if (ob.num[0] == '+')
    {

        s = ob.num.substr(1);
        ob.num = s;
        return 0;
    }

    else if (ob.num[0] == '-')
    {
        s = ob.num.substr(1);
        ob.num = s;
        return 1;
    }

    else
    {
        return 0;
    }
}
int checkNum(string s1, string s2)
{

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] > s2[i])
        {

            return 1;
        }
        else if (s2[i] > s1[i])
        {

            return 2;
        }
    }
    return 3;


}
void removezeros(string& s)
{
    if (s[0] == '0')
    {
        int j = 0;
        while (s[j] == '0')
            j++;

        string str = "";
        if (j == s.length())
            str = s.substr(j - 1);
        else
            str = s.substr(j);

        s = str;
    }

    else if (s[0] == '-' && s[1] == '0')
    {
        int j = 0;   string str = "";
        while (s[j + 1] == '0')
            j++;
        if (j == s.length())
            str = s.substr(j - 1);
        else
            str = s.substr(j);
        s = '-' + str;
    }
}

//constructors
BigInt::BigInt()
{
    num = "";
    Onum = num;
}
BigInt::BigInt(string str)
{
    num = str;
    Onum = num;
}
BigInt::BigInt(int number)
{
    num = to_string(number);
    Onum = num;

}
int BigInt::size()
{
    return num.size();
}


BigInt BigInt::operator+(BigInt ob)
{

    if (num[0] == '-' && (ob.num[0] <= '9' && ob.num[0] >= '0'))
    {
        removeSign(*this);
        return ob - *this;
    }

    if ((num[0] <= '9' && num[0] >= '0') && ob.num[0] == '-')
    {
        removeSign(ob);
        return *this - ob;
    }


    if (num.length() < ob.num.length())
    {

        bool check = (removeSign(ob) && removeSign(*this));

        int dif = ob.num.length() - num.length();

        BigInt c;
        c.num = "";
        int carry = 0;

        for (int i = (num.length() - 1); i >= 0; i--)
        {
            int sum = 0;
            sum = num[i] + ob.num[i + dif] - 2 * '0' + carry;
            carry = 0;
            if (sum > 9)
            {
                sum -= 10;
                carry++;
            }
            c.num += sum + '0';

        }
        for (int i = dif - 1; i >= 0; i--)
        {
            int sum = 0;
            sum += ob.num[i] - '0' + carry;
            carry = 0;
            if (sum > 9)
            {
                sum -= 10;
                carry++;
            }

            c.num += sum + '0';
        }
        if (carry > 0)
        {
            c.num += carry + '0';
        }
        if (check)
        {
            c.num += '-';
        }
        reverse(c.num.begin(), c.num.end());
        num = Onum;
        ob.num = ob.Onum;
        return c;

    }


    else if (num.length() > ob.num.length())
    {
        bool check = removeSign(ob) && removeSign(*this);
        int diff = num.length() - ob.num.length();
        BigInt c;
        num = "";
        int carry = 0;

        for (int i = (ob.num.length() - 1); i >= 0; i--)
        {
            int sum = 0;
            sum = num[i + diff] + ob.num[i] - 2 * '0' + carry;
            carry = 0;
            if (sum >= 10)
            {
                sum -= 10;
                carry++;
            }
            c.num += sum + '0';

        }
        for (int i = diff - 1; i >= 0; i--)
        {
            int sum = 0;
            sum += num[i] + carry - '0';
            carry = 0;
            if (sum >= 10)
            {
                sum -= 10;
                carry++;

            }
            c.num += sum + '0';

        }

        if (carry > 0)
            c.num += carry + '0';

        if (check)
            c.num += '-';

        reverse(c.num.begin(), c.num.end());
        num = Onum;
        ob.num = ob.Onum;
        return c;
    }


    else
    {
        bool check = (removeSign(ob) && removeSign(*this));
        BigInt c;
        c.num = "";
        int carry = 0;

        for (int i = (num.length() - 1); i >= 0; i--)
        {
            int sum = 0;
            sum = num[i] + ob.num[i] - 2 * '0' + carry;
            carry = 0;
            if (sum >= 10)
            {
                sum -= 10;
                carry++;
            }
            c.num += sum + '0';
        }

        if (carry > 0)
            c.num += carry + '0';

        if (check)
            c.num += '-';

        reverse(c.num.begin(), c.num.end());

        ob.num = ob.Onum; num = Onum;
        return c;
    }
}
BigInt BigInt::operator-(BigInt ob)
{

    if (num.length() > ob.num.length())
    {

        int dif = num.length() - ob.num.length();
        BigInt c;
        c.num = "";
        int carry = 0;
        for (int i = (ob.num.length() - 1); i >= 0; i--)
        {
            int sum = 0;
            sum = num[i + dif] - ob.num[i] + carry;
            carry = 0;
            if (sum < 0)
            {
                sum += 10;
                carry--;
            }
            c.num += sum + '0';

        }

        for (int i = dif - 1; i >= 0; i--)
        {
            int sum = 0;
            sum += num[i] - '0' + carry;
            carry = 0;
            if (sum < 0)
            {
                sum += 10;
                carry--;
            }

            c.num += sum + '0';
        }

        reverse(c.num.begin(), c.num.end());
        removezeros(c.num);
        num = Onum;
        ob.num = ob.Onum;
        return c;
    }

    if (num.length() < ob.num.length())
    {

        int dif = ob.num.length() - num.length();
        BigInt c;
        c.num = "";
        int carry = 0;
        for (int i = (num.length() - 1); i >= 0; i--)
        {

            int sum = 0;
            sum = ob.num[i + dif] - num[i] + carry;
            carry = 0;
            if (sum < 0)
            {
                sum += 10;
                carry--;
            }
            c.num += sum + '0';

        }

        for (int i = dif - 1; i >= 0; i--)
        {
            int sum = 0;
            sum += ob.num[i] + carry - '0';
            carry = 0;
            if (sum < 0)
            {
                sum += 10;
                carry--;
            }
            c.num += sum + '0';
        }

        c.num += '-';
        reverse(c.num.begin(), c.num.end());
        removezeros(c.num);
        num = Onum;
        ob.num = ob.Onum;

        return c;
    }

    if (num.length() == ob.num.length())
    {
        int x = checkNum(num, ob.num);
        if (x == 3)
        {
            BigInt c;
            c.num = "0";
            return c;
        }

        BigInt c;
        c.num = "";
        int carry = 0;
        int len = 0;

        if (x == 1)
            len = num.length();
        else
            len = ob.num.length();

        for (int i = len - 1; i >= 0; i--)
        {
            int sum = 0;
            if (x == 1)
                sum = num[i] - ob.num[i] + carry;
            else
                sum = ob.num[i] - num[i] + carry;
            carry = 0;
            if (sum < 0)
            {
                sum += 10;
                carry--;
            }
            c.num += sum + '0';
        }
        reverse(c.num.begin(), c.num.end());
        removezeros(c.num);
        num = Onum;
        ob.num = ob.Onum;
        return c;
    }

}

ostream& operator<< (ostream& output, BigInt ob)
{
    output << ob.num;
    return output;
}
