#pragma once

#include "TopoShape.h"

#include <memory>
#include <vector>

namespace brepom
{

class TopoShell;

class TopoBody : public TopoShape
{
public:
	TopoBody() {}

	virtual TopoShapeType GetType() const override { return TOPO_BODY; }
	virtual std::shared_ptr<TopoShape> Clone() const override;

private:
	std::vector<std::shared_ptr<TopoShell>> m_shells;

}; // TopoBody

}