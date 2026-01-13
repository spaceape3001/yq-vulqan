////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGProject.hpp"
#include <yq/vkqt/app/YTachyonMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::XGProject)

namespace yq::tachyon {
    
    XGProject::XGProject()
    {
    }
    
    XGProject::~XGProject()
    {
    }
    
    void XGProject::init_meta()
    {
        auto w = writer<XGProject>();
        w.description("Executive Graph Project");
    }
}

#include "moc_XGProject.cpp"
