#pragma once
#include<random>
#include<DirectXMath.h>
using namespace DirectX;

float drand();

class Vec3
{
	friend float Dot(const Vec3& v1, const Vec3& v2);

	friend Vec3 Reflect(const Vec3& v, const Vec3& n);
public:
	float X()const
	{
		return m.x;
	}
	float Y()const
	{
		return m.y;
	}
	float Z()const
	{
		return m.z;
	}
	float R()const
	{
		return m.x;
	}
	float G()const
	{
		return m.y;
	}
	float B()const
	{
		return m.z;
	}
	
	Vec3()
	{
	}
	Vec3(XMFLOAT3 xmfloat3)
	{
		m = xmfloat3;
	}
	Vec3(float x, float y, float z)
	{
		m = XMFLOAT3{ x,y,z };
	}

	Vec3& operator+=(const Vec3 &v2)
	{
		m.x += v2.X();
		m.y += v2.Y();
		m.z += v2.Z();
		return *this;
	}
	Vec3& operator-=(const Vec3& v2)
	{
		m.x -= v2.X();
		m.y -= v2.Y();
		m.z -= v2.Z();
		return *this;
	}
	Vec3& operator*=(const Vec3& v2)
	{
		m.x *= v2.X();
		m.y *= v2.Y();
		m.z *= v2.Z();
		return *this;
	}
	Vec3& operator/=(const Vec3& v2)
	{
		m.x /= v2.X();
		m.y /= v2.Y();
		m.z /= v2.Z();
		return *this;
	}
	Vec3& operator*=(const float t)
	{
		m.x *= t;
		m.y *= t;
		m.z *= t;
		return *this;
	}
	Vec3& operator/=(const float t)
	{
		float k = 1.0 / t;
		m.x *= k;
		m.y *= k;
		m.z *= k;
		return *this;
	}
	XMFLOAT3& GetXMFLOAT3()
	{
		return m;
	}

	Vec3 UnitVector()
	{
		Vec3 ans;

		auto vec = XMLoadFloat3(&m);

		vec = XMVector3Normalize(vec);

		XMStoreFloat3(&ans.GetXMFLOAT3(), vec);

		return ans;
	}
	float Length()
	{
		auto vp = XMLoadFloat3(&m);

		return XMVectorGetX(XMVector3Length(vp));
	}
private:
	XMFLOAT3 m;
};

float Dot(const Vec3& v1, const Vec3& v2);
inline Vec3 operator-(const Vec3& v1, const Vec3& v2)
{
	/*auto vv1 = XMLoadFloat3(&v1.GetXMFLOAT3());
	auto vv2 = XMLoadFloat3(&v2.GetXMFLOAT3());

	vv1 + vv2;*/
	
	return Vec3(v1.X() - v2.X(), v1.Y() - v2.Y(), v1.Z() - v2.Z());
}
inline Vec3 operator+(const Vec3& v1, const Vec3& v2)
{
	/*auto vv1 = XMLoadFloat3(&v1.GetXMFLOAT3());
	auto vv2 = XMLoadFloat3(&v2.GetXMFLOAT3());

	vv1 + vv2;*/

	return Vec3(v1.X() + v2.X(), v1.Y() + v2.Y(), v1.Z() + v2.Z());
}
inline Vec3 operator*(const Vec3& v1, const Vec3& v2)
{
	/*auto vv1 = XMLoadFloat3(&v1.GetXMFLOAT3());
	auto vv2 = XMLoadFloat3(&v2.GetXMFLOAT3());

	vv1 + vv2;*/

	return Vec3(v1.X() * v2.X(), v1.Y() * v2.Y(), v1.Z() * v2.Z());
}
inline Vec3 operator*(const Vec3& v1, float t)
{
	/*auto vv1 = XMLoadFloat3(&v1.GetXMFLOAT3());
	auto vv2 = XMLoadFloat3(&v2.GetXMFLOAT3());

	vv1 + vv2;*/

	return Vec3(v1.X() * t, v1.Y() * t, v1.Z() * t);
}
inline Vec3 operator*( float t, const Vec3& v1)
{
	/*auto vv1 = XMLoadFloat3(&v1.GetXMFLOAT3());
	auto vv2 = XMLoadFloat3(&v2.GetXMFLOAT3());

	vv1 + vv2;*/

	return Vec3(v1.X() * t, v1.Y() * t, v1.Z() * t);
}


Vec3 RandomInUnitSphere();

Vec3 Reflect(const Vec3& v, const Vec3& n);