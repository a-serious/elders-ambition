#ifndef ELDERSVARIENT_H
#define ELDERSVARIENT_H

#include <QString>

class EldersVarient
{
    bool type;
    void *data;

public:
    EldersVarient(int);
    EldersVarient(QString);
    EldersVarient();

    int getInt() const;
    QString getString() const;
    QString getOutput() const;
    static EldersVarient setInput(QString);
    bool isTrue() const;

    EldersVarient operator==(EldersVarient) const;
    EldersVarient operator!=(EldersVarient) const;
    EldersVarient operator>(EldersVarient) const;
    EldersVarient operator>=(EldersVarient) const;
    EldersVarient operator<(EldersVarient) const;
    EldersVarient operator<=(EldersVarient) const;

    EldersVarient operator+(EldersVarient) const;
    EldersVarient operator-(EldersVarient) const;
    EldersVarient operator*(EldersVarient) const;
    EldersVarient operator/(EldersVarient) const;
    EldersVarient operator%(EldersVarient) const;
    EldersVarient operator^(EldersVarient) const;
    EldersVarient operator&(EldersVarient) const;
    EldersVarient operator<<(EldersVarient) const;
    EldersVarient operator>>(EldersVarient) const;
    EldersVarient operator~() const;

    EldersVarient &operator+=(EldersVarient);
    EldersVarient &operator-=(EldersVarient);
    EldersVarient &operator*=(EldersVarient);
    EldersVarient &operator/=(EldersVarient);
    EldersVarient &operator%=(EldersVarient);

    EldersVarient operator=(int);
    EldersVarient operator=(QString);

    static EldersVarient input(QString, int &);
};


#endif // ELDERSVARIENT_H
