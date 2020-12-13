#include <iostream>
#include "ZFraction.h"
using namespace std;

ZFraction::ZFraction(int up,int down):m_up(up),m_down(down)
{
    simplifie();
}
ZFraction::~ZFraction(){}

int ZFraction::pgcd(int a, int b)
{
while (b != 0)
{
const int t = b;
b = a%b;
a=t;
}
return a;
}

int ZFraction::getNum() const
{
    return m_up;
}

int ZFraction::getDen() const
{
    return m_down;
}

double ZFraction::nbrReel()
{
    double s,s1(m_up),s2(m_down);
    s=s1/s2;
    return s;
}

ZFraction& ZFraction::operator+=(ZFraction const& a)
{
    m_up=(m_up*a.m_down)+(m_down*a.m_up);
    m_down*=a.m_down;
    simplifie();
    return *this;
}

ZFraction operator+(ZFraction const& a,ZFraction const& b)
{
    ZFraction s(a);
    s+=b;
    return s;
}

ZFraction& ZFraction::operator-=(ZFraction const& a)
{
    m_up=(m_up*a.m_down)-(m_down*a.m_up);
    m_down*=a.m_down;
    simplifie();
    return *this;
}

ZFraction operator-(ZFraction const& a,ZFraction const& b)
{
    ZFraction s(a);
    s-=b;
    return s;
}

ZFraction& ZFraction::operator*=(ZFraction const& a)
{
    m_up*=a.m_up;
    m_down*=a.m_down;
    simplifie();
    return *this;
}


ZFraction operator*(ZFraction const& a,ZFraction const& b)
{
    ZFraction s(a);
    s*=b;
    return s;
}


ostream& operator<<(std::ostream& flux,ZFraction const& fraction)
{
    if(fraction.m_up==fraction.m_down || fraction.m_down==1)
    {
        flux<<fraction.m_up;
    }
    else
    flux<<fraction.m_up<<"/"<<fraction.m_down;
    return flux;
}

void ZFraction::simplifie()
{
    int s(pgcd(m_up,m_down));
    m_up/=s;
    m_down/=s;
    if(m_down<0)
    {
        m_up=-m_up;
        m_down=-m_down;
    }
}

bool operator==(ZFraction const& a,ZFraction const& b)
{
    return (a.m_up==b.m_up && a.m_down==b.m_down);
}

bool operator!=(ZFraction const& a,ZFraction const& b)
{
    return !(a==b);
}

bool operator<(ZFraction const& a,ZFraction const& b)
{
    double s1,s2,s3(a.m_up),s4(a.m_down),s5(b.m_up),s6(b.m_down);
    s1=s3/s4;
    s2=s5/s6;
    if(s1<s2)
    return true;
    else
    return false;
}

bool operator<=(ZFraction const& a,ZFraction const& b)
{
    return (a<b || a==b) ;
}

bool operator>(ZFraction const& a,ZFraction const& b)
{
    return !(a<b || a==b);
}

bool operator>=(ZFraction const& a,ZFraction const& b)
{
    return !(a<b) ;
}
