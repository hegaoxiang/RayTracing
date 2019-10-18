#pragma once
#include"Object.h"
#include<vector>
class BVHNode:public Object
{
public:
	Object* m_left;
	Object* m_right;
	AABB* m_aabb;
	// Í¨¹ý Object ¼Ì³Ð
	virtual bool Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord) override;
	virtual HitRecord GetHitRecord(const Vec3& hitPoint) override;
	virtual AABB GenerateBox() override;

	BVHNode(std::vector<Object*>& objs, int left, int right);
};

