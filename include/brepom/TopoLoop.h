#pragma once

#include "TopoShape.h"

#include <memory>
#include <vector>

namespace brepom
{

class TopoEdge;

class TopoLoop : public TopoShape
{
public:
	TopoLoop() {}
	TopoLoop(const std::vector<std::shared_ptr<TopoEdge>>& edges) 
		: m_edges(edges) {}
	
	virtual TopoShapeType GetType() const override { return TOPO_LOOP; }
	virtual std::shared_ptr<TopoShape> Clone() const override;

	auto& GetEdges() const { return m_edges; }

private:
	std::vector<std::shared_ptr<TopoEdge>> m_edges;

}; // TopoLoop

}