////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/typedef/controller.hpp>


namespace yq::tachyon {
    class Controller;
    struct TypedID;

    //! Utiltity to bind a controller to the whatever...
    class ControllerBind {
    public:
        ControllerID    controller() const { return m_controller; }
        
    protected:
        constexpr ControllerBind(ControllerID v) noexcept : m_controller(v) {}
        ControllerBind(Controller*);
        ControllerBind(TypedID);
        virtual ~ControllerBind() {}
        
        ControllerID const m_controller;
    };
}
