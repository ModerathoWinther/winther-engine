//
// Created by komvu on 2024-12-19.
//

#ifndef WINTHER_ENGINE_ENTITY_H
#define WINTHER_ENGINE_ENTITY_H


#include <string>

namespace Winther
{

	class Entity
	{
	public:
		Entity(size_t id, const std::string& name);

	private:

		const size_t m_Id;
		const std::string m_Name;
		bool m_Exists;

	};

} // Winther

#endif //WINTHER_ENGINE_ENTITY_H
