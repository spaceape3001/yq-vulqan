////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/typedef/manager.hpp>

namespace yq::tachyon {
    class Manager;
    struct TypedID;

    //! Utiltity to bind a viewer to the whatever...
    class ManagerBind {
    public:
        ManagerID    manager() const { return m_manager; }
        
    protected:
        constexpr ManagerBind(ManagerID v) noexcept : m_manager(v) {}
        ManagerBind(const Manager*);
        ManagerBind(TypedID);
        virtual ~ManagerBind() {}
        
        ManagerID const m_manager;
    };
}
