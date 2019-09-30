#include"Math.h"

XMFLOAT3 mul(XMFLOAT3 v1, float t)
{
	return XMFLOAT3{ v1.x * t,v1.y * t,v1.z * t };
}
XMFLOAT3 puls(XMFLOAT3 v1, XMFLOAT3 v2)
{
	return XMFLOAT3{ v1.x + v2.x,v1.y + v2.y,v1.z + v2.z };
}