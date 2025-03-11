////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "BoxLayout.hpp"
#include <yt/ui/LayoutInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::BoxLayout)

namespace yq::tachyon {
    void BoxLayout::init_info()
    {
        auto w = writer<BoxLayout>();
        w.description("Linear Box Layout");
    }

    BoxLayout::BoxLayout()
    {
    }
    
    BoxLayout::~BoxLayout()
    {
    }
    
    void BoxLayout::tick(const TickAPI& api) 
    {
        //  TODO
    }
}
