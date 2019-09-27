// Plane Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief The Plane Geaometrical Primitive class
 */
class CPrimPlane : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param origin Point on the plane
	 * @param normal Normal to the plane
	 */
	CPrimPlane(Vec3f color, Vec3f origin, Vec3f normal)
		: CPrim(color)
		, m_normal(normal)
		, m_origin(origin)
	{
		normalize(m_normal);
	}
	virtual ~CPrimPlane(void) = default;

	virtual bool Intersect(Ray& ray) override
	{

		// use derived formula from previous HW
		if (ray.dir.dot(m_normal) == 0){ // first check if denominator is 0
			return false;
		}
		else{
			float t = (m_origin - ray.org).dot(m_normal) / ray.dir.dot(m_normal);
			if (t < Epsilon || t > ray.t)
				return false;
			else{
				ray.t = t;
				return true;
			}

		}
		
			
	}


private:
	Vec3f m_normal;	///< Point on the plane
	Vec3f m_origin;	///< Normal to the plane
};
