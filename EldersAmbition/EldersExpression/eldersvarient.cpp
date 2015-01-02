#include "eldersvarient.h"

#include <QString>

EldersVarient::EldersVarient(int data)
{
    this->data = new int(data);
    this->type = false;
}

EldersVarient::EldersVarient(QString data)
{
    this->data = new QString(data);
    this->type = true;
}

EldersVarient::EldersVarient()
{
    this->data = 0;
    this->type = false;
}

int EldersVarient::getInt() const
{
    if(!this->type)
        return *((int*)this->data);
    else
    {
        throw("Error: Trying to get int value from string EldersVatirnt.");
        return 0;
    }
}

QString EldersVarient::getString() const
{
    if(this->type)
        return *((QString*)this->data);
    else
        return QString("<Number>") + QString::number(getInt());
}

QString EldersVarient::getOutput() const
{
    if (!this->data)
        return "\"";
    if (this->type)
        return "\"" + *((QString*)this->data);
    else
        return QString::number(getInt());
}

EldersVarient EldersVarient::setInput(QString t)
{
    if (t.startsWith("\""))
        return EldersVarient(t.mid(1));
    return EldersVarient(t.toInt());
}

bool EldersVarient::isTrue() const
{
    if(this->type && *((QString*)this->data) != "") return true;
    if(!this->type && *((int*)this->data) != 0) return true;
    return false;
}

EldersVarient EldersVarient::operator==(EldersVarient a) const
{
    EldersVarient temp(0);
    if(!this->type && !a.type)
    {
        *((int*)temp.data) = *((int*)(this->data)) == *(int*)(a.data);
        return temp;
    }
    if(this->type && a.type)
    {
        *((int *)temp.data) = *((QString *)(this->data)) == *((QString *)(a.data));
        return temp;
    }
    return EldersVarient(-1);
}

EldersVarient EldersVarient::operator!=(EldersVarient a) const
{
    EldersVarient temp(0);
    if(!this->type && !a.type)
    {
        *((int*)temp.data) = *((int*)(this->data)) != *(int*)(a.data);
        return temp;
    }
    if(this->type && a.type)
    {
        *((int*)temp.data) = *((QString*)(this->data)) != *((QString *)(a.data));
        return temp;
    }
    throw("Error: Invalid use of operator !=");
    return EldersVarient(0);
}

EldersVarient EldersVarient::operator>(EldersVarient a) const
{
    EldersVarient temp(0);
    if(!this->type && !a.type)
    {
        *((int*)temp.data) = *((int*)(this->data)) > *(int*)(a.data);
        return temp;
    }
    if(this->type && a.type)
    {
        *((int*)temp.data) = *((QString*)(this->data)) > *((QString *)(a.data));
        return temp;
    }
    throw("Error: Invalid use of operator >");
    return EldersVarient(0);
}

EldersVarient EldersVarient::operator>=(EldersVarient a) const
{
    EldersVarient temp(0);
    if(!this->type && !a.type)
    {
        *((int*)temp.data) = *((int*)(this->data)) >= *(int*)(a.data);
        return temp;
    }
    if(this->type && a.type)
    {
        *((int*)temp.data) = *((QString*)(this->data)) >= *((QString *)(a.data));
        return temp;
    }
    throw("Error: Invalid use of operator >=");
    return EldersVarient(0);
}

EldersVarient EldersVarient::operator<(EldersVarient a) const
{
    EldersVarient temp(0);
    if(!this->type && !a.type)
    {
        *((int*)temp.data) = *((int*)(this->data)) < *(int*)(a.data);
        return temp;
    }
    if(this->type && a.type)
    {
        *((int*)temp.data) = *((QString*)(this->data)) < *((QString *)(a.data));
        return temp;
    }
    throw("Error: Invalid use of operator <");
    return EldersVarient(0);
}

EldersVarient EldersVarient::operator<=(EldersVarient a) const
{
    EldersVarient temp(0);
    if(!this->type && !a.type)
    {
        *((int*)temp.data) = *((int*)(this->data)) <= *(int*)(a.data);
        return temp;
    }
    if(this->type && a.type)
    {
        *((int*)temp.data) = *((QString*)(this->data)) <= *((QString *)(a.data));
        return temp;
    }
    throw("Error: Invalid use of operator <=");
    return EldersVarient(0);
}



EldersVarient EldersVarient:: operator+(EldersVarient a) const
{
    if(!this->type && !a.type)
    {
        EldersVarient temp(0);
        *((int*)temp.data) = *((int*)(this->data)) + *(int*)(a.data);
        return temp;
    }
    if(this->type && a.type)
    {
        EldersVarient temp("");
        *((QString*)temp.data) = *((QString*)(this->data)) + *((QString *)(a.data));
        return temp;
    }
    throw("Error: Invalid use of operator +");
    return EldersVarient(0);
}

EldersVarient EldersVarient::operator-(EldersVarient a) const
{
    EldersVarient temp(0);
    if(!this->type && !a.type)
    {
        *((int*)temp.data) = *((int*)(this->data)) - *(int*)(a.data);
        return temp;
    }
    throw("Error: Invalid use of operator -");
    return EldersVarient(0);
}

EldersVarient EldersVarient::operator*(EldersVarient a) const
{
    EldersVarient temp(0);
    if(!this->type && !a.type)
    {
        *((int*)temp.data) = *((int*)(this->data)) * *(int*)(a.data);
        return temp;
    }
    throw("Error: Invalid use of operator *");
    return EldersVarient(0);
}
EldersVarient EldersVarient::operator/(EldersVarient a) const
{
    EldersVarient temp(0);
    if(!this->type && !a.type)
    {
        *((int*)temp.data) = *((int*)(this->data)) / *(int*)(a.data);
        return temp;
    }
    throw("Error: Invalid use of operator /");
    return EldersVarient(0);
}
EldersVarient EldersVarient::operator%(EldersVarient a) const
{
    EldersVarient temp(0);
    if(!this->type && !a.type)
    {
        *((int*)temp.data) = *((int*)(this->data)) % *(int*)(a.data);
        return temp;
    }
    throw("Error: Invalid use of operator %");
    return EldersVarient(0);
}
EldersVarient EldersVarient::operator^(EldersVarient a) const
{
    EldersVarient temp(0);
    if(!this->type && !a.type)
    {
        *((int*)temp.data) = *((int*)(this->data)) ^ *(int*)(a.data);
        return temp;
    }
    throw("Error: Invalid use of operator ^");
    return EldersVarient(0);
}
EldersVarient EldersVarient::operator&(EldersVarient a) const
{
    EldersVarient temp(0);
    if(!this->type && !a.type)
    {
        *((int*)temp.data) = *((int*)(this->data)) & *(int*)(a.data);
        return temp;
    }
    throw("Error: Invalid use of operator &");
    return EldersVarient(0);
}

EldersVarient EldersVarient::operator<<(EldersVarient a) const
{
    EldersVarient temp(0);
    if(!this->type && !a.type)
    {
        *((int*)temp.data) = *((int*)(this->data)) << *(int*)(a.data);
        return temp;
    }
    throw("Error: Invalid use of operator <<");
    return EldersVarient(0);
}

EldersVarient EldersVarient::operator>>(EldersVarient a) const
{
    EldersVarient temp(0);
    if(!this->type && !a.type)
    {
        *((int*)temp.data) = *((int*)(this->data)) >> *(int*)(a.data);
        return temp;
    }
    throw("Error: Invalid use of operator >>");
    return EldersVarient(0);
}

EldersVarient EldersVarient::operator~() const
{
    EldersVarient temp(0);
    if(!this->type)
    {
        *((int*)temp.data) = ~(*((int*)(this->data)));
        return temp;
    }
    throw("Error: Invalid use of operator ~");
    return EldersVarient(0);
}

EldersVarient & EldersVarient::operator+=(EldersVarient a)
{
    return *this = *this + a;
}

EldersVarient & EldersVarient::operator-=(EldersVarient a)
{
    return *this = *this - a;
}

EldersVarient & EldersVarient::operator*=(EldersVarient a)
{
    return *this = *this * a;
}
EldersVarient & EldersVarient::operator/=(EldersVarient a)
{
    return *this = *this / a;
}
EldersVarient & EldersVarient::operator%=(EldersVarient a)
{
    return *this = *this % a;
}

EldersVarient EldersVarient::operator=(int x)
{
    type = false;
    data = new int(x);
    return *this;
}

EldersVarient EldersVarient::operator=(QString x)
{
    type = true;
    data = new QString(x);
    return *this;
}

EldersVarient EldersVarient::input(QString source, int &i)
{
    if (source[i] >= '0' && source[i] <= '9')
    {
        int temp = 0;
        while (source[i] >= '0' && source[i] <= '9' && i < source.size())
        {
            temp *= 10;
            temp += source[i].digitValue();
            i++;
        }
        return EldersVarient(temp);
    }
    else if (source[i] == '\"')
    {
        QString temp("");
        while (++i < source.size() && source[i] != '\"')
            temp += source[i];
        if (i++ == source.size())
            throw("Error: input reaches data end!");
        return EldersVarient(temp);
    }
    throw "Invalid number or string...";
}
