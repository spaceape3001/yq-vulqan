////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    class Controller;

    //! Utiltity to bind a controller to the whatever...
    class ControllerBind {
    public:
        Controller*    controller() const { return m_controller; }
        
    protected:
        ControllerBind(Controller* v) : m_controller(v) {}
        virtual ~ControllerBind() {}
        
        Controller* const m_controller;
    };
}
