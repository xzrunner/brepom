#include "brepom/Object.h"
#include "brepom/Component.h"

namespace brepom
{

Object::~Object()
{
}

void Object::Clear()
{
	if (m_comps)
	{
		for (size_t i = 0; i < m.comp_sz; ++i) {
			delete m_comps[i];
		}
		delete[] m_comps;
		m_comps = nullptr;
	}
	m.Clear();
}

}