////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/manager.hpp>

namespace yq::tachyon {
    class Manager;

    //! Utiltity to bind a viewer to the whatever...
    class ManagerBind {
    public:
        ManagerID    manager() const { return m_manager; }
        
    protected:
        ManagerBind(ManagerID v) : m_manager(v) {}
        ManagerBind(const Manager* v);
        virtual ~ManagerBind() {}
        
        ManagerID const m_manager;
    };
}
