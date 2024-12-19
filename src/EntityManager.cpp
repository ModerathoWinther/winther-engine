//
// Created by komvu on 2024-12-19.
//

#include "EntityManager.h"

namespace Winther
{
	std::shared_ptr<Entity> EntityManager::addEntity(const std::string& name)
	{
		return std::shared_ptr<Entity>();
	}

	EntityManager::~EntityManager()
	{

	}

	EntityManager::EntityManager()
	{

	}

	void EntityManager::Update()
	{
		// Update state of all Entities before each frame has been rendered
		// in order to ensure safe iteration.

	}

	bool EntityManager::LoadFile(const std::string&& filename)
	{
		return false;
	}

	EntityVector& EntityManager::GetEntitiesWithName(const std::string& name)
	{
		EntityVector vec;
		return vec;
	}

	EntityVector& EntityManager::GetEntities()
	{
		EntityVector vec;
		return vec;
	}
} // Winther