#pragma once

#include <objcomp/Object.h>

#include <vector>

namespace brepom
{

class Label : public objcomp::Object
{
public:
	~Label();

	void AddChild(const std::shared_ptr<Label>& child);
	bool RemoveChild(const std::shared_ptr<Label>& child);
	void RemoveAllChildren();

	auto& GetAllChildren() const { return m_children; }
	void SetChildren(const std::vector<std::shared_ptr<Label>>& children);

	auto GetParent() const { return m_parent; }

private:
	Label* m_parent = nullptr;
	std::vector<std::shared_ptr<Label>> m_children;

}; // Label 

}