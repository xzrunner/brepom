#include "brepom/PrimBuilder.h"
#include "brepom/BRepBuilder.h"
#include "brepom/TopoShell.h"

#include <vector>

namespace brepom
{

std::shared_ptr<TopoShape> PrimBuilder::Box(const sm::vec3& center, const sm::vec3& size)
{
	float hx = size.x * 0.5f;
	float hy = size.y * 0.5f;
	float hz = size.z * 0.5f;

	float xmin = center.x - hx;
	float xmax = center.x + hx;
	float ymin = center.y - hy;
	float ymax = center.y + hy;
	float zmin = center.z - hz;
	float zmax = center.z + hz;

    sm::vec3 top_left_front  = sm::vec3(xmin, ymax, zmin);
    sm::vec3 top_left_back   = sm::vec3(xmin, ymax, zmax);
    sm::vec3 top_right_front = sm::vec3(xmax, ymax, zmin);
    sm::vec3 top_right_back  = sm::vec3(xmax, ymax, zmax);
    sm::vec3 btm_left_front  = sm::vec3(xmin, ymin, zmin);
    sm::vec3 btm_left_back   = sm::vec3(xmin, ymin, zmax);
    sm::vec3 btm_right_front = sm::vec3(xmax, ymin, zmin);
    sm::vec3 btm_right_back  = sm::vec3(xmax, ymin, zmax);

	std::vector<sm::vec3> points = { 
		top_left_front,
		top_left_back,
		top_right_front,
		top_right_back,
		btm_left_front,
		btm_left_back,
		btm_right_front,
		btm_right_back
	};

	std::vector<std::vector<uint32_t>> faces = {
		{ 0, 4, 6, 2 },
		{ 1, 3, 7, 5 },
		{ 0, 4, 5, 1 },
		{ 2, 6, 7, 3 },
		{ 0, 2, 3, 1 },
		{ 4, 5, 7, 6 },
	};

	return BRepBuilder::BuildShell(points, faces);
}

}