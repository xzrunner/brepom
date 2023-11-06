#include "brepom/LabelBuilder.h"
#include "brepom/Label.h"
#include "brepom/AttrNamedShape.h"
#include "brepom/TopoShape.h"
#include "brepom/TopoShell.h"
#include "brepom/TopoFace.h"

namespace brepom
{

void LabelBuilder::BuildFromShape(const std::shared_ptr<Label>& label,
	                              const std::shared_ptr<TopoShape>& shape)
{
	if (label->HasComponent<AttrNamedShape>()) {
		label->GetComponent<AttrNamedShape>().SetShape(nullptr, shape);
	} else {
		label->AddComponent<AttrNamedShape>(nullptr, shape);
	}

	if (shape->GetType() != TOPO_SHELL) {
		return;
	}

	auto shell = std::static_pointer_cast<TopoShell>(shape);
	auto& faces = shell->GetFaces();
	if (faces.empty()) {
		return;
	}

	label->RemoveAllChildren();
	for (auto& face : faces)
	{
		auto child = std::make_shared<Label>();
		child->AddComponent<AttrNamedShape>(nullptr, face);
		label->AddChild(child);
	}
}

}