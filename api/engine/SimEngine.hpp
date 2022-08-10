////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Object.hpp>
#include <basic/trait/not_copyable.hpp>
#include <basic/trait/not_moveable.hpp>
#include "Taskable.hpp"

namespace yq {
    namespace engine {
        class SimEngine : public Object, trait::not_copyable, trait::not_moveable {
            YQ_OBJECT_DECLARE(SimEngine, Object)
        public:
            SimEngine();
            
            void    step(Second dt);
        
            void    add_taskable(Ref<Taskable>);
            void    remove_taskable(uint64_t);
            
            Second      time() const { return m_time; }
        
        private:
            std::vector<Ref<Taskable>>   m_taskables;
            Second                       m_time;
        };
    }
}

