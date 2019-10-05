#include"Math.h"

XMFLOAT3 mul(XMFLOAT3 v1, float t)
{
	return XMFLOAT3{ v1.x * t,v1.y * t,v1.z * t };
}
XMFLOAT3 puls(XMFLOAT3 v1, XMFLOAT3 v2)
{
	return XMFLOAT3{ v1.x + v2.x,v1.y + v2.y,v1.z + v2.z };
}

XMFLOAT3 sub(XMFLOAT3 vl, XMFLOAT3 vr)
{
	return XMFLOAT3{ vl.x - vr.x, vl.y - vr.y, vl.z - vr.z };
}
float dot(XMFLOAT3 v1, XMFLOAT3 v2)
{
	auto vec1 = XMLoadFloat3(&v1);
	auto vec2 = XMLoadFloat3(&v2);

	return XMVectorGetX(XMVector3Dot(vec1, vec2));
}

XMFLOAT3 unit(XMFLOAT3 v)
{
	auto vec = XMLoadFloat3(&v);

	vec = XMVector3Normalize(vec);

	XMStoreFloat3(&v, vec);

	return v;
}
