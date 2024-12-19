//
// Created by komvu on 2024-12-19.
//

#ifndef WINTHER_ENGINE_ENTITYMANAGER_H
#define WINTHER_ENGINE_ENTITYMANAGER_H
#include <Entity.h>
#include <vector>
#include <memory>
#include <map>


namespace Winther
{

	typedef std::vector<std::shared_ptr<Entity>> EntityVector;
	typedef std::map<std::string, EntityVector> EntityMap;

	class EntityManager
	{
	private:
		EntityVector m_Entities;
		EntityMap 	m_EntityMap;
		size_t 		m_EntitySize;

	public:

		EntityManager();

		std::shared_ptr<Entity> addEntity(const std::string& name);

		EntityVector& GetEntities();

		EntityVector& GetEntitiesWithName(const std::string& name);

		bool LoadFile(const std::string&& filename);
		~EntityManager();


		void Update();
	};

} // Winther

#endif //WINTHER_ENGINE_ENTITYMANAGER_H
