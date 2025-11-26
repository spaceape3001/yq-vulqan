////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/typedef/material.hpp>

namespace yq::tachyon {
    class PMaterial;
    
    class IMaterial {
    public:
        YQ_INTERFACE_DECLARE(IMaterial, PMaterial)

        virtual MaterialCPtr    material() const = 0;
        virtual void            material(set_k, const MaterialCPtr&){}

        virtual bool            material(disabled_k) const { return false; }
        virtual bool            material(settable_k) const { return false; }

        static void init_meta();
    };
}
