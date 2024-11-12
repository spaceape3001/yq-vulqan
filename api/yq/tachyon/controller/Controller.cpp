////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Controller.hpp"
#include "ControllerInfoWriter.hpp"

YQ_OBJECT_IMPLEMENT(yq::tachyon::Controller);

namespace yq::tachyon {
    ControllerInfo::ControllerInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
    {
    }

    Controller::Controller(const Param& p) : Tachyon(p) 
    {
    }
    
    Controller::~Controller()
    {
    }
    
    void Controller::init_info()
    {
        auto w = writer<Controller>();
        w.description("Abstract Controller");
    }
}
