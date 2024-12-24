////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/controller.hpp>


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
