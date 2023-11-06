#include "brepom/TopoFace.h"
#include "brepom/TopoLoop.h"

namespace brepom
{

std::shared_ptr<TopoShape> TopoFace::Clone() const
{
	std::vector<std::shared_ptr<TopoLoop>> loops;
	loops.reserve(m_loops.size());
	for (auto l : m_loops)
	{
		auto nl = std::dynamic_pointer_cast<TopoLoop>(l->Clone());
		loops.push_back(nl);
	}

	auto f = std::make_shared<TopoFace>();
	f->SetLoops(loops);
	return f;
}

}