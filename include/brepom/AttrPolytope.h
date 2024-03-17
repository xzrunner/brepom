#pragma once

#include "Attribute.h"

namespace pm3 { class Polytope; }

namespace brepom
{

class AttrPolytope : public Attribute
{
public:
	AttrPolytope(const std::shared_ptr<pm3::Polytope>& poly);

	virtual const char* Type() const override { return "polytope"; }
	virtual objcomp::CompID TypeID() const override { return objcomp::GetCompTypeID<AttrPolytope>(); }
	virtual Attribute* Clone() const override { return nullptr; }

	void SetPoly(const std::shared_ptr<pm3::Polytope>& poly) { m_poly = poly; }
	auto GetPoly() const { return m_poly; }

private:
	std::shared_ptr<pm3::Polytope> m_poly;

}; // AttrPolytope 

}