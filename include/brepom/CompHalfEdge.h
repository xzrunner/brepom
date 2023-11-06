#pragma once

#include "Attribute.h"

#include <halfedge/typedef.h>

namespace brepom
{

class TopoShape;

class CompHalfEdge : public Attribute
{
public:
	CompHalfEdge(const std::shared_ptr<TopoShape>& shape);

private:
	void BuildTopo(const std::shared_ptr<TopoShape>& shape);

private:
	he::PolyhedronPtr m_topo = nullptr;

}; // CompHalfEdge 

}