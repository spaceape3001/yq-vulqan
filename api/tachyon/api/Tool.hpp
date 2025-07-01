////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Object.hpp>

namespace yq::tachyon {
    class ToolMeta : public ObjectMeta {
    public:
        template <class> class Writer;
        ToolMeta(std::string_view, ObjectMeta&, const std::source_location& sl = std::source_location::current());
    
        //  const WidgetMeta*   widget() const;
    };
    
    
    /*! \brief A tool (like paint brush, pan to target, etc)
    
        A tool is supposed to be hooked to gesture recognition/commands.
    */
    class Tool : public Object {
        YQ_OBJECT_INFO(ToolMeta)
        YQ_OBJECT_DECLARE(Tool, Object)
    public:
        
        //  Tool TODO
        
        static void init_meta();
        
    protected:
        Tool();
        virtual ~Tool();
    };
}
