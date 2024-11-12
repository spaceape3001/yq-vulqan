////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Controlling.hpp"
#include "ControllingInfoWriter.hpp"
#include <yq/tachyon/controller/Controller.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Controlling)

namespace yq::tachyon {
    ControllingInfo::ControllingInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
    {
    }

    Controlling::Controlling(const Param&p) : Tachyon(p)
    {
    
    }
    
    Controlling::~Controlling()
    {
    }

    void    Controlling::attach(controller_t, ControllerPtr pController)
    {
        if(!pController)
            return ;
        if(attached(CONTROLLER, pController.ptr()))
            return ;
        m_controllers.push_back(pController);
        attach(FORWARD, pController.ptr());
    }
    
    bool    Controlling::attached(controller_t, Controller* pController) const
    {
        for(auto& p : m_controllers){
            if(p.ptr() == pController)
                return true;
        }
        return false;
    }
    
    void    Controlling::detach(controller_t, ControllerPtr pController)
    {
        detach(FORWARD, pController.ptr());
        std::erase_if(m_controllers, [&](const ControllerPtr& cand) -> bool {
            return cand.ptr() == pController.ptr();
        });
    }

    void Controlling::init_info()
    {
        auto w = writer<Controlling>();
        w.description("Controlling Personality");
    }
}
