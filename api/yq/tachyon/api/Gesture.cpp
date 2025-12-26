////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Gesture.hpp"
#include "GestureMetaWriter.hpp"

YQ_OBJECT_IMPLEMENT(yq::tachyon::Gesture)

namespace yq::tachyon {
    GestureMeta::GestureMeta(std::string_view name, ObjectMeta& base, const std::source_location& sl) :
        DelegateMeta(name, base, sl)
    {
        set(Flag::TOOL);
    }
    
    Gesture::Gesture()
    {
    }
    
    Gesture::~Gesture()
    {
    }
    
    void Gesture::init_meta()
    {
        auto w = writer<Gesture>();
        w.description("Gesture base");
    }
}
