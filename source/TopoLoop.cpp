#include "brepom/TopoLoop.h"
#include "brepom/TopoEdge.h"

namespace brepom
{

std::shared_ptr<TopoShape> TopoLoop::Clone() const
{
	std::vector<std::shared_ptr<TopoEdge>> edges;
	edges.reserve(m_edges.size());
	for (auto e : m_edges) {
		auto ce = std::dynamic_pointer_cast<TopoEdge>(e->Clone());
		edges.push_back(ce);
	}
	return std::make_shared<TopoLoop>(edges);
}

}