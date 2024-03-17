#include "brepom/AttrPolytope.h"

namespace brepom
{

AttrPolytope::AttrPolytope(const std::shared_ptr<pm3::Polytope>& poly)
	: m_poly(poly)
{
}

}