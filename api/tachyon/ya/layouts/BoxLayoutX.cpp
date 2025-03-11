////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "BoxLayoutX.hpp"
#include <yt/ui/LayoutInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::BoxLayoutˣ)

namespace yq::tachyon {
    void BoxLayoutˣ::init_info()
    {
        auto w = writer<BoxLayoutˣ>();
        w.description("Box layout in the X-direction");
    }
    
    BoxLayoutˣ::BoxLayoutˣ()
    {
    }
    
    BoxLayoutˣ::~BoxLayoutˣ()
    {
    }
}
