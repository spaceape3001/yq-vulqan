////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/core/Tachyon.hpp>
#include <yq/tachyon/typedef/controller.hpp>

namespace yq::tachyon {
    class ControllingInfo : public TachyonInfo {
    public:
        template <typename> class Writer;
        
        ControllingInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl=std::source_location::current());
    };
    
    class Controlling : public Tachyon {
        YQ_OBJECT_INFO(ControllingInfo)
        YQ_OBJECT_DECLARE(Controlling, Tachyon)
    public:
    
        using Tachyon::attached;
    
        void    attach(controller_t, ControllerPtr);
        void    detach(controller_t, ControllerPtr);
        
        bool    attached(controller_t, Controller*) const;
        
        static void init_info();
    
    protected:
    
        Controlling(const Param&p={});
        ~Controlling();
    
        using Tachyon::attach;
        using Tachyon::detach;
    
    private:
        std::vector<ControllerPtr>      m_controllers;
    };

}
