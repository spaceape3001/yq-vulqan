////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Object.hpp>

namespace yq::tachyon {
    class ToolInfo : public ObjectInfo {
    public:
        template <class> class Writer;
        ToolInfo(std::string_view, ObjectInfo&, const std::source_location& sl = std::source_location::current());
    
        //  const WidgetInfo*   widget() const;
    };
    
    
    /*! \brief Controls the camera
    
        The manipulator is about controlling the camera/viewer with user input.
    */
    class Tool : public Object {
        YQ_OBJECT_INFO(ToolInfo)
        YQ_OBJECT_DECLARE(Tool, Object)
    public:
        
        //  Tool TODO
        
        static void init_info();
        
    protected:
        Tool();
        virtual ~Tool();
    };
}
