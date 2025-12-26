////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Delegate.hpp>

namespace yq::tachyon {
    class GestureMeta : public DelegateMeta {
    public:
        template <class> class Writer;
        GestureMeta(std::string_view, ObjectMeta&, const std::source_location& sl = std::source_location::current());
    
        //  const WidgetMeta*   widget() const;
    };
    
    
    /*! A gesture is a *specific* thing the user is doing
    
        Whether it's move the current camera, etc
    */
    class Gesture : public Delegate {
        YQ_OBJECT_META(GestureMeta)
        YQ_OBJECT_DECLARE(Gesture, Delegate)
    public:
    
        //  want
        
        //  Gesture TODO
        
        static void init_meta();
        
    protected:
        Gesture();
        virtual ~Gesture();
    };
}
