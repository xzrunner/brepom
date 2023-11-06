#pragma once

#include "Object.h"
#include "TopoShapeType.h"

namespace brepom
{

class TopoShape : public Object
{
public:
	virtual ~TopoShape() 
	{
		int zz = 0;
	}

	virtual TopoShapeType GetType() const = 0;
	virtual std::shared_ptr<TopoShape> Clone() const = 0;

}; // TopoShape

}