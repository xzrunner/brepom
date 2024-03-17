#pragma once

#include <memory>

namespace pm3 { class Polytope; }

namespace brepom
{

class Label;
class TopoShape;

class LabelBuilder
{
public:
	static void BuildFromShape(const std::shared_ptr<Label>& label,
		const std::shared_ptr<TopoShape>& shape);

	static void BuildFromPolytope(const std::shared_ptr<Label>& label,
		const std::shared_ptr<pm3::Polytope>& poly);

}; // LabelBuilder

}