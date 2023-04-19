////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/MetaObject.hpp>

namespace yq::tachyon {
    class ToolInfo : public ObjectInfo {
    public:
        template <class> class Writer;
        ToolInfo(std::string_view, MetaObjectInfo&, const std::source_location& sl = std::source_location::current());
    
        //  const WidgetInfo*   widget() const;
    };
    
    
    /*! \brief Controls the camera
    
        The manipulator is about controlling the camera/viewer with user input.
    */
    class Tool : public Object {
        YQ_OBJECT_INFO(ToolInfo)
        YQ_OBJECT_DECLARE(Tool, MetaObject)
    public:
        
        //  Tool TODO
        
    protected:
        Tool();
        virtual ~Tool();
    };
    
    template <typename C>
    class ToolInfo::Writer : public MetaObjectInfo::Writer<C> {
    public:
        Writer(ToolInfo* manipInfo) : MetaObjectInfo::Writer<C>(manipInfo)
        {
        }
        
        Writer(ToolInfo& manipInfo) : Writer(&manipInfo)
        {
        }
    };
    
}
