#include "BVHNode.h"
#include"AABB.h"
#include<algorithm>
bool BVHNode::Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord)
{
	if (m_aabb->Hit(ray, t_min, t_max))
	{
		HitRecord lHitR,rHitR;
		auto leftHit = m_left->Hit(ray, t_min, t_max, lHitR);
		auto rightHit = m_right->Hit(ray, t_min, t_max, rHitR);

		if (leftHit && rightHit)
		{
			if (lHitR.m_t <= rHitR.m_t)
				hitRecord = lHitR;
			else
				hitRecord = rHitR;
			return true;
		}
		else if (leftHit)
		{
			hitRecord = lHitR;
			return true;
		}
		else if (rightHit)
		{
			hitRecord = rHitR;

			return true;
		}
	}

	return false;
}

HitRecord BVHNode::GetHitRecord(const Vec3& hitPoint)
{
	return HitRecord();
}

AABB BVHNode::GenerateBox()
{
	if(m_aabb != nullptr)

	return *m_aabb;
}

BVHNode::BVHNode(std::vector<Object*>& objs, int left , int right)
{	
	
	if (left != right)
	{
		int mid = (right + left) / 2;
		m_left = new BVHNode(objs, left, mid);
		m_right = new BVHNode(objs, mid + 1, right);
		m_aabb = new AABB(m_left->GenerateBox(), m_right->GenerateBox());
	}
	else
	{
		m_left = m_right = objs[left];
		m_aabb = new AABB(m_left->GenerateBox());
	}
}
