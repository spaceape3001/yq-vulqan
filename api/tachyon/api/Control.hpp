////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Widget.hpp>
#include <variant>
#include <yq/typedef/filesystem_path.hpp>

namespace yq::tachyon {
    class InterfaceInfo;

    /*! \brief Control information
    */
    class ControlInfo : public WidgetMeta {
    public:
        
        template <typename C>  struct Writer;
        
        ControlInfo(std::string_view, WidgetMeta&, const std::source_location& sl = std::source_location::current());
        
        const std::vector<const InterfaceInfo*>& interfaces() const { return m_interfaces; }
    
    private:
        std::vector<const InterfaceInfo*>   m_interfaces;
    };
    
    //! Root for an control widget
    //!
    //! Meant to be a general base for an interface/proxy control (or similar)
    class Control : public Widget {
        YQ_TACHYON_INFO(ControlInfo)
        YQ_TACHYON_DECLARE(Control, Widget)
    public:
        
        //! Default destructor
        virtual ~Control();
        
        static void init_info();
        
    protected:
    
        //! Control default constructor
        Control();
    };
}
