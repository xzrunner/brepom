#pragma once

#include "TopoShapeType.h"

#include <objcomp/Object.h>

namespace brepom
{

class TopoShape : public objcomp::Object
{
public:
	virtual ~TopoShape() {}

	virtual TopoShapeType GetType() const = 0;
	virtual std::shared_ptr<TopoShape> Clone() const = 0;

}; // TopoShape

}