#pragma once
#include<random>
#include<DirectXMath.h>
using namespace DirectX;

float drand();

class Vec3
{
	friend float Dot(const Vec3& v1, const Vec3& v2);
	friend Vec3 Cross(const Vec3& v1, const Vec3& v2);
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
		m = XMFLOAT3(0, 0, 0);
	}
	Vec3(XMFLOAT3 xmfloat3)
	{
		m = xmfloat3;
	}
	Vec3(float x, float y, float z)
	{
		m = XMFLOAT3{ x,y,z };
	}

	float operator[](int i)const 
	{
		switch (i)
		{
		case 0:
			return m.x;
		case 1:
			return m.y;
		case 2:
			return m.z;
		default:
			throw i;
		}
	}
	float& operator[](int i)
	{
		switch (i)
		{
		case 0:
			return m.x;
		case 1:
			return m.y;
		case 2:
			return m.z;
		default:
			throw i;
		}
	}

	Vec3& operator+=(const Vec3& v2)
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
		float k = 1.0f / t;
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


class Vec4
{
	
public:
	float X()const
	{
		return m.w;
	}
	float Y()const
	{
		return m.y;
	}
	float Z()const
	{
		return m.z;
	}
	float W()const
	{
		return m.w;
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
	float A()const
	{
		return m.w;
	}

	Vec4()
	{
		m = XMFLOAT4(0, 0, 0,0);
	}
	Vec4(XMFLOAT4 xmfloat4)
	{
		m = xmfloat4;
	}
	Vec4(float x, float y, float z,float w)
	{
		m = XMFLOAT4{ x,y,z,w };
	}

	float operator[](int i)const
	{
		switch (i)
		{
		case 0:
			return m.x;
		case 1:
			return m.y;
		case 2:
			return m.z;
		case 3:
			return m.w;
		default:
			throw i;
		}
	}

	Vec4& operator+=(const Vec4& v2)
	{
		m.x += v2.X();
		m.y += v2.Y();
		m.z += v2.Z();
		m.w += v2.W();
		return *this;
	}
	Vec4& operator-=(const Vec4& v2)
	{
		m.x -= v2.X();
		m.y -= v2.Y();
		m.z -= v2.Z();
		m.w -= v2.W();
		return *this;
	}
	Vec4& operator*=(const Vec4& v2)
	{
		m.x *= v2.X();
		m.y *= v2.Y();
		m.z *= v2.Z();
		m.w *= v2.W();
		return *this;
	}
	Vec4& operator/=(const Vec4& v2)
	{
		m.x /= v2.X();
		m.y /= v2.Y();
		m.z /= v2.Z();
		m.w /= v2.W();
		return *this;
	}
	Vec4& operator*=(const float t)
	{
		m.x *= t;
		m.y *= t;
		m.z *= t;
		m.w *= t;
		return *this;
	}
	Vec4& operator/=(const float t)
	{
		float k = 1.0f / t;
		m.x *= k;
		m.y *= k;
		m.z *= k;
		m.w *= t;
		return *this;
	}
	XMFLOAT4& GetXMFLOAT4()
	{
		return m;
	}

	Vec4 UnitVector()
	{
		Vec4 ans;

		auto vec = XMLoadFloat4(&m);

		vec = XMVector4Normalize(vec);

		XMStoreFloat4(&ans.GetXMFLOAT4(), vec);

		return ans;
	}
	float Length()
	{
		auto vp = XMLoadFloat4(&m);

		return XMVectorGetX(XMVector4Length(vp));
	}
private:
	XMFLOAT4 m;
};
float Dot(const Vec3& v1, const Vec3& v2);
Vec3 Cross(const Vec3& v1, const Vec3& v2);
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
inline Vec3 operator*(float t, const Vec3& v1)
{
	/*auto vv1 = XMLoadFloat3(&v1.GetXMFLOAT3());
	auto vv2 = XMLoadFloat3(&v2.GetXMFLOAT3());

	vv1 + vv2;*/

	return Vec3(v1.X() * t, v1.Y() * t, v1.Z() * t);
}


Vec3 RandomInUnitSphere();

Vec3 Reflect(const Vec3& v, const Vec3& n);

unsigned char float2uchar(float value);