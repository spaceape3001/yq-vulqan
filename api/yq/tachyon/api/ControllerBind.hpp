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

    //! Utiltity to bind a controller to the whatever...
    class ControllerBind {
    public:
        ControllerID    controller() const { return m_controller; }
        
    protected:
        ControllerBind(ControllerID v) : m_controller(v) {}
        ControllerBind(Controller* v);
        virtual ~ControllerBind() {}
        
        ControllerID const m_controller;
    };
}
