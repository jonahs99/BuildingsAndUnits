#pragma once

template <typename T>
class Vector3d {

public:

	T x, y, z;

	Vector3d(T mx, T my, T mz) : x(mx), y(my), z(mz) { };

	Vector3d<T>& operator += (Vector3d<T> other)
	{ x += other.x; y += other.y; z += other.z; return *this; };

	Vector3d<T>& operator -= (Vector3d<T> other)
	{ x -= other.x; y -= other.y; z -= other.z; return *this; };

	Vector3d<T>& operator *= (T other)
	{ x *= other; y *= other; z *= other; return *this; };

	Vector3d<T>& operator /= (T other)
	{ x /= other; y /= other; z /= other; return *this; };

	Vector3d<T>& operator + (Vector3d<T> other)
	{ return Vector3d<T>(other) += *this; };

	Vector3d<T>& operator - (Vector3d<T> other)
	{ return Vector3d<T>(other) -= *this; };

	Vector3d<T>& operator * (T other)
	{ return Vector3d<T>(*this) *= other; }

	Vector3d<T>& operator / (T other)
	{ return Vector3d<T>(*this) /= other; }

};

template<typename T>
std::ostream &operator<<(std::ostream &os, Vector3d<T> const &m) {
	return os << "(" << m.x << ", " << m.y << ", " << m.z << ")";
}