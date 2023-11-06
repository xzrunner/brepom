#include "brepom/TopoBody.h"
#include "brepom/TopoShell.h"

namespace brepom
{

std::shared_ptr<TopoShape> TopoBody::Clone() const
{
	std::vector<std::shared_ptr<TopoShell>> shells;
	shells.reserve(m_shells.size());
	for (auto s : m_shells)
	{
		auto ns = std::dynamic_pointer_cast<TopoShell>(s->Clone());
		shells.push_back(ns);
	}

	auto b = std::make_shared<TopoBody>();
	b->m_shells = shells;
	return b;
}

}