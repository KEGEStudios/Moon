#pragma once

#include "../../include/gtx/gtx.hpp"

namespace Moon::Core {
    template<Moon::Concepts::Ent_t Type>
    GameContext_t<Type>::GameContext_t()
    {
        this->entities.reserve(NUM_ENTITIES);
    }

    template<Moon::Concepts::Ent_t Type>
    GameContext_t<Type>::~GameContext_t()
    {
        /*Nada*/
    }

    template<Moon::Concepts::Ent_t Type>
    Moon::Alias::GameContextType
    GameContext_t<Type>::getGameContextType() noexcept
    {
        static Moon::Alias::GameContextType type = ++nextType;
        return type;
    }

    template<Moon::Concepts::Ent_t Type>
    Type& GameContext_t<Type>::addEntity()
    {
        auto& ent = this->entities.emplace_back(this->nextId++);
        return ent;
    }

    template<Moon::Concepts::Ent_t Type>
    Type* GameContext_t<Type>::getEntityById(Moon::Alias::EntityId eid)
    {
        auto it = std::find_if(this->entities.begin(),
                               this->entities.end(),
                               [&](Type& e) { return eid == e.eid; });
        if (it == this->entities.end()) {
            return nullptr;
        }
        return it.base();
    }

} // namespace Moon::Core