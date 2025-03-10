////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Layout1.hpp"
#include "Layout1InfoWriter.hpp"

YQ_OBJECT_IMPLEMENT(yq::tachyon::Layout¹)

namespace yq::tachyon {
    Layout¹Info::Layout¹Info(std::string_view kName, LayoutInfo& pMeta, const std::source_location& sl) :
        LayoutInfo(kName, pMeta, sl)
    {
        set(Flag::D1);
    }

////////////////////////////////////////////////////////////////////////////////
    void Layout¹::init_info()
    {
        auto w = writer<Layout¹>();
        w.description("1D Layout");
    }
        
    Layout¹::Layout¹()
    {
    }
    
    Layout¹::~Layout¹()
    {
    }
}

