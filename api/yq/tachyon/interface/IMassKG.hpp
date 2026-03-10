////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PMassKG;
    
    class IMassKG {
    public:
        YQ_INTERFACE_DECLARE(IMassKG, PMassKG)
        
        virtual Kilogram  mass() const = 0;
        virtual void    mass(add_k, Kilogram){}
        virtual void    mass(multiply_k, double){}
        virtual void    mass(set_k, Kilogram){}

        virtual bool    mass(disabled_k) const { return false; }
        virtual bool    mass(settable_k) const { return false; }
        virtual bool    mass(addable_k) const { return false; }
        virtual bool    mass(multipliable_k) const { return false; }

        static void init_meta();
    };
}
