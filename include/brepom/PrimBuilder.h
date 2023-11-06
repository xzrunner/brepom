#pragma once

#include <SM_Vector.h>

#include <memory>

namespace brepom
{

class TopoShape;

class PrimBuilder
{
public:
	static std::shared_ptr<TopoShape> Box(const sm::vec3& center, const sm::vec3& size);

}; // PrimBuilder

}