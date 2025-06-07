////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SimpleSpatial3UI.hpp"
#include <tachyon/spatial/SimpleSpatial3.hpp>
#include <tachyon/ui/UIEditorInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SimpleSpatial³UI)

namespace yq::tachyon {
    void SimpleSpatial³UI::init_info()
    {
        auto w = writer<SimpleSpatial³UI>();
        w.description("UIEditor for SimpleSpatial³");
        w.edits<SimpleSpatial³>();
    }
    
    SimpleSpatial³UI::SimpleSpatial³UI(UIFlags flags)
    {
    }
    
    SimpleSpatial³UI::SimpleSpatial³UI(const SimpleSpatial³UI& cp) : UIEditor(cp)
    {
    }
    
    SimpleSpatial³UI* SimpleSpatial³UI::clone() const
    {
        return new SimpleSpatial³UI(*this);
    }
    
}
