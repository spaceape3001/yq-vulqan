////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/keywords.hpp>
#include <tachyon/api/Interface.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    class PFieldOfView;
    
    class IFieldOfView {
    public:
        YQ_INTERFACE_DECLARE(IFieldOfView, PFieldOfView)
    
        virtual unit::Degree  field_of_view() const = 0;

        virtual bool    field_of_view(disabled_k) const { return false; }
        virtual bool    field_of_view(settable_k) const { return false; }
        
        virtual void    field_of_view(set_k, unit::Degree){}
        
        IFieldOfView();
        virtual ~IFieldOfView();
        
        static void init_meta();
    };
}
