////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Controller.hpp"
#include "ControllerInfoWriter.hpp"
#include <yq/tachyon/controller/ControllerBind.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Controller);

namespace yq::tachyon {
    ControllerInfo::ControllerInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
    {
    }

    Controller::Controller(Tachyon* tgt, const Param& p) : Tachyon(p), m_target(tgt), m_enable(true)
    {
        _attach(TARGET);
    }
    
    Controller::~Controller()
    {
        _detach(TARGET);
    }

    void    Controller::_attach(target_t)
    {
        if(m_target)
            connect(RX, *m_target);
    }
    
    void    Controller::_detach(target_t)
    {
        if(m_target)
            disconnect(RX, *m_target);
    }

    bool  Controller::enabled() const 
    { 
        return m_enable; 
    }
    
    void  Controller::enable() 
    { 
        m_enable = true; 
    }
    
    void  Controller::disable() 
    { 
        m_enable = false; 
    }
    
    void    Controller::receive(const post::PostCPtr&pp)
    {
        if(!pp)
            return;
        if(const ControllerBind* p = dynamic_cast<const ControllerBind*>(pp.ptr())){
            if(p->controller() != this)
                return ;
            if(!in_replay())
                forward(pp);
        } else if(!enabled()){   
            return ;
        } else if(!in_replay()){
            forward(pp);
        }
        Tachyon::receive(pp);
    }


    void Controller::tick()
    {
        replay(ALL);
    }

    void Controller::init_info()
    {
        auto w = writer<Controller>();
        w.abstract();
        w.description("Abstract Controller");
    }
}
