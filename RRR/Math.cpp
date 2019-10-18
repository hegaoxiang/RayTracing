#include"Math.h"


float drand()
{
	return static_cast<float>(rand()) / RAND_MAX;
}

float Dot(const Vec3& v1, const Vec3& v2)
{
	auto vec1 = XMLoadFloat3(&v1.m);
	auto vec2 = XMLoadFloat3(&v2.m);

	return XMVectorGetX(XMVector3Dot(vec1, vec2));
}

Vec3 Cross(const Vec3& v1, const Vec3& v2)
{
	Vec3 ans;
	auto vv1 = XMLoadFloat3(&v1.m);
	auto vv2 = XMLoadFloat3(&v2.m);

	auto temp = XMVector3Cross(vv1, vv2);
	XMStoreFloat3(&ans.m, temp);

	return ans;
}


// other func for CG
Vec3 RandomInUnitSphere()
{
	Vec3 p;
	do
	{
		p = 2 * (Vec3{ drand(),drand(),drand() } -Vec3{ 0.5f,0.5f,0.5f });
	} while (p.Length() >= 1.0f);
	return p;
}

Vec3 Reflect(const Vec3& v, const Vec3& n)
{
	Vec3 ans;

	auto incident = XMLoadFloat3(&v.m);
	auto normal = XMLoadFloat3(&n.m);

	XMStoreFloat3(&ans.m,XMVector3Reflect(incident, normal));

	return ans;
}
