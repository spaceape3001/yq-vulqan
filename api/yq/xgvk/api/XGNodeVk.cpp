////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGContextVk.hpp"
#include "XGNodeVk.hpp"
#include "XGNodeVkMetaWriter.hpp"

YQ_OBJECT_IMPLEMENT(yq::tachyon::XGNodeVk)

namespace yq::tachyon {
    XGContextVk::XGContextVk() = default;
    XGContextVk::~XGContextVk() = default;
    
    void XGNodeVk::init_meta()
    {
        auto w = writer<XGNodeVk>();
        w.description("Vulkan Graph Node");
        w.abstract();
    }
        
    XGNodeVk::XGNodeVk() = default;
    XGNodeVk::~XGNodeVk() = default;

    xg_result_t XGNodeVk::execute(XGContext&ctx) 
    {
        if(XGContextVk* p = dynamic_cast<XGContextVk*>(&ctx))
            return execute(*p);
        return ERROR;
    }
    
    xg_result_t XGNodeVk::execute(XGContextVk&) 
    {
        return {};
    }
}
