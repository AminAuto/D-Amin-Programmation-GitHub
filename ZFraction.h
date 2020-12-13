#ifndef ZFRACTION_H_INCLUDED
#define ZFRACTION_H_INCLUDED
class ZFraction
{
public:
    ZFraction(int up=0,int down=1);
    ~ZFraction();
    void simplifie();
    ZFraction& operator+=(ZFraction const& a);
    ZFraction& operator-=(ZFraction const& a);
    ZFraction& operator*=(ZFraction const& a);
    double nbrReel();
    int pgcd(int a,int b);
    int getNum() const;
    int getDen() const;

private:
    int m_up;
    int m_down;
    friend bool operator==(ZFraction const& a,ZFraction const& b);
    friend bool operator<(ZFraction const& a,ZFraction const& b);
    friend std::ostream& operator<<(std::ostream& flux,ZFraction const& fraction);
};

ZFraction operator+(ZFraction const& a,ZFraction const& b);

ZFraction operator-(ZFraction const& a,ZFraction const& b);

ZFraction operator*(ZFraction const& a,ZFraction const& b);

std::ostream& operator<<(std::ostream& flux,ZFraction const& fraction);

bool operator==(ZFraction const& a,ZFraction const& b);

bool operator!=(ZFraction const& a,ZFraction const& b);

bool operator<(ZFraction const& a,ZFraction const& b);

bool operator<=(ZFraction const& a,ZFraction const& b);

bool operator>(ZFraction const& a,ZFraction const& b);

bool operator>=(ZFraction const& a,ZFraction const& b);

#endif // ZFRACTION_H_INCLUDED
