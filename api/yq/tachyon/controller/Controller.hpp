////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/tachyon/core/Tachyon.hpp>
#include <yq/tachyon/typedef/controller.hpp>

namespace yq::tachyon {

    class ControllerInfo : public TachyonInfo {
    public:
        template <typename C> class Writer;

        ControllerInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl=std::source_location::current());
    };
    
    /*! \brief Controller of Posts/Events/etc
    
        Business of a controller is to translate events/posts/commands into 
        commands for some recipient object.  (ie, a camera controller)
        
        
    */
    class Controller : public Tachyon, public RefCount {
        YQ_OBJECT_INFO(ControllerInfo)
        YQ_OBJECT_DECLARE(Controller, Tachyon)
    public:
    
        Controller(const Param& p={});
        ~Controller();
        
        static void init_info();
    };

}
