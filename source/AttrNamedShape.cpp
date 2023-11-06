#include "brepom/AttrNamedShape.h"

namespace brepom
{

AttrNamedShape::AttrNamedShape(const std::shared_ptr<TopoShape>& src, const std::shared_ptr<TopoShape>& dst)
	: m_src(src)
	, m_dst(dst)
{
}

}