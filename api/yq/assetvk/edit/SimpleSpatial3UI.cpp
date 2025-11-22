////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SimpleSpatial3UI.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/spatial/SimpleSpatial3.hpp>
#include <yq/tachyon/ui/UIEditorMetaWriter.hpp>
#include <yq/tachyon/proxy/PPosition3.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SimpleSpatial³UI)

namespace yq::tachyon {
    void SimpleSpatial³UI::init_meta()
    {
        auto w = writer<SimpleSpatial³UI>();
        w.description("UIEditor for SimpleSpatial³");
        w.edits<SimpleSpatial³>();
        //w.field("Position", &SimpleSpatial³UI::position);
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
