#include "brepom/TopoEdge.h"
#include "brepom/TopoVertex.h"

namespace brepom
{

std::shared_ptr<TopoShape> TopoEdge::Clone() const
{
	auto p1 = std::static_pointer_cast<TopoVertex>(m_p1->Clone());
	auto p2 = std::static_pointer_cast<TopoVertex>(m_p2->Clone());
	return std::make_shared<TopoEdge>(p1, p2);
}

}