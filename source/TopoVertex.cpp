#include "brepom/TopoVertex.h"

namespace brepom
{

std::shared_ptr<TopoShape> TopoVertex::Clone() const
{
	return std::make_shared<TopoVertex>(m_pos);
}

}