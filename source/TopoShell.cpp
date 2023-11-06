#include "brepom/TopoShell.h"
#include "brepom/TopoFace.h"

namespace brepom
{

std::shared_ptr<TopoShape> TopoShell::Clone() const
{
	std::vector<std::shared_ptr<TopoFace>> faces;
	faces.reserve(m_faces.size());
	for (auto f : m_faces)
	{
		auto nf = std::dynamic_pointer_cast<TopoFace>(f->Clone());
		faces.push_back(nf);
	}
	return std::make_shared<TopoShell>(faces);
}

}