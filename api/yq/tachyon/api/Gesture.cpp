////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Gesture.hpp"
#include "GestureMetaWriter.hpp"
#include <yq/tachyon/api/Widget.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Gesture)

namespace yq::tachyon {
    
    GestureMeta::GestureMeta(std::string_view name, ObjectMeta& base, const std::source_location& sl) :
        ObjectMeta(name, base, sl)
    {
    }
    
    thread_local Widget*        Gesture::s_widget       = nullptr;
    thread_local ViContext*     Gesture::s_viContext    = nullptr;
    thread_local const Context* Gesture::s_context      = nullptr;

    void            Gesture::gesture(GestureUPtr&& g)
    {
        if(s_widget)
            s_widget -> gesture(ADD, std::move(g));
    }

    void           Gesture::mail(const PostCPtr& pp)
    {
        if(s_widget)
            s_widget -> mail(pp);
    }
    
    void           Gesture::send(const PostCPtr& pp)
    {
        if(s_widget)
            s_widget -> send(pp, TARGET);
    }

    ///////////////

    Gesture::Gesture()
    {
    }
    
    Gesture::Gesture(const Gesture&)
    {
    }
    
    Gesture::~Gesture()
    {
    }

    
    void Gesture::init_meta()
    {
        auto w = writer<Gesture>();
        w.abstract();
        w.description("Gesture base");
    }
}
