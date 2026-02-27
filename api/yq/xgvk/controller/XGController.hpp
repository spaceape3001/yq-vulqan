////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Controller.hpp>

namespace yq {
    class XGRuntime;
}

namespace yq::tachyon {
    class XGController : public Controller {
        YQ_TACHYON_DECLARE(XGController, Controller)
    public:
    
        XGController();
        ~XGController();
        
        static void init_meta();
        
    private:
        //GGraph          m_primary;
        
        //  TBD... XGEngine ... primary?
    };
}
