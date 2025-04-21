#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <iostream>
struct Vector
{
	int X;
	int Y;

	Vector operator+(const Vector& Value) { return Vector(X + Value.X, Y + Value.Y); }
	Vector operator-(const Vector& Value) { return Vector(X - Value.X, Y - Value.Y); }
	Vector operator+(const int& Value) { return Vector(X + Value, Y + Value); }
	Vector operator-(const int& Value) { return Vector(X - Value, Y - Value); }
	Vector& operator+=(const Vector& Value)
	{
		X += Value.X;
		Y += Value.Y;
		return *this;
	}
	Vector& operator-=(const Vector& Value)
	{
		X -= Value.X;
		Y -= Value.Y;
		return *this;
	}

	friend Vector operator+(const int& Value, const Vector& Rhs) { return Vector(Value + Rhs.X, Value + Rhs.Y); }
	friend Vector operator-(const int& Value, const Vector& Rhs) { return Vector(Value - Rhs.X, Value - Rhs.Y); }

	friend std::ostream& operator<<(std::ostream& os, const Vector& Rhs)
	{
		os << Rhs << '\n';
		return os;
	}
};

#endif // !__VECTOR_H__
