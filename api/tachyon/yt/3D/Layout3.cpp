////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Layout3.hpp"
#include "Layout3InfoWriter.hpp"

YQ_OBJECT_IMPLEMENT(yq::tachyon::Layout³)

namespace yq::tachyon {
    Layout³Info::Layout³Info(std::string_view kName, LayoutInfo& pMeta, const std::source_location& sl) :
        LayoutInfo(kName, pMeta, sl)
    {
        set(Flag::D3);
    }

////////////////////////////////////////////////////////////////////////////////
    void Layout³::init_info()
    {
        auto w = writer<Layout³>();
        w.description("3D Layout");
    }
        
    Layout³::Layout³()
    {
    }
    
    Layout³::~Layout³()
    {
    }
}

