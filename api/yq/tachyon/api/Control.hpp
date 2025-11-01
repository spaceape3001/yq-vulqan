////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Widget.hpp>
#include <variant>
#include <yq/typedef/filesystem_path.hpp>

namespace yq::tachyon {
    class InterfaceMeta;

    /*! \brief Control information
    */
    class ControlMeta : public WidgetMeta {
    public:
        
        template <typename C>  struct Writer;
        
        ControlMeta(std::string_view, WidgetMeta&, const std::source_location& sl = std::source_location::current());
        
        const std::vector<const InterfaceMeta*>& interfaces() const { return m_interfaces; }
    
    private:
        std::vector<const InterfaceMeta*>   m_interfaces;
    };
    
    //! Root for an control widget
    //!
    //! Meant to be a general base for an interface/proxy control (or similar)
    class Control : public Widget {
        YQ_TACHYON_META(ControlMeta)
        YQ_TACHYON_DECLARE(Control, Widget)
    public:
        
        //! Default destructor
        virtual ~Control();
        
        static void init_meta();
        
    protected:
    
        //! Control default constructor
        Control();
    };
}
