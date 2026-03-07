////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/xg/XGElement.hpp>

namespace yq::tachyon {
    struct XGContextVk;
    
    class XGNodeVk : public XGElement {
        YQ_OBJECT_DECLARE(XGNodeVk, XGElement)
    public:
        
        virtual xg_result_t         execute(XGContext&) final;
        virtual xg_result_t         execute(XGContextVk&) = 0;
        static void init_meta();
        
    protected:
        XGNodeVk();
        ~XGNodeVk();
    };
}
