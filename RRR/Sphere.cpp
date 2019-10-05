#include "Sphere.h"
#include"Ray.h"

HitRecord Sphere::Hit(const Ray& ray)
{
	HitRecord hitRecord ;

	auto o = XMLoadFloat3(&m_orgin);
	auto p = XMLoadFloat3(&ray.m_origin);
	
	auto pSubO = p - o;

	auto d = XMLoadFloat3(&ray.m_dir);

	// xmvector3dot计算得到一个vector，其中每个分量都是点积值。
	float A = XMVectorGetX( XMVector3Dot(d, d));
	float B = 2 * XMVectorGetX(XMVector3Dot(d, pSubO));
	float C = XMVectorGetX(XMVector3Dot(pSubO, pSubO)) - powf(m_radius, 2);

	float discriminant = B * B - 4 * A * C;
	if (discriminant >= 0)
	{

		hitRecord.m_bHit = true;
		hitRecord.m_t = (-B + sqrtf(discriminant)) / 2 * A;
		//hitRecord.m_color = m_material.m_rgb;// need fix
		hitRecord.m_normal = unit(sub(ray.PointAtPara(hitRecord.m_t), m_orgin));
		hitRecord.m_color = mul(puls(hitRecord.m_normal, XMFLOAT3(1, 1, 1)), 0.5);
	}
	else
		hitRecord.m_t = -1;

	return  hitRecord;
}
