////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/typedef/height_field.hpp>
#include <yq/typedef/url.hpp>

namespace yq::tachyon {
    class PHeightField;
    
    class IHeightField {
    public:
        YQ_INTERFACE_DECLARE(IHeightField, PHeightField)

        virtual HeightFieldCPtr height_field() const = 0;
        virtual Url             height_field(url_k) const = 0;
        virtual void            height_field(set_k, const HeightFieldCPtr&){}
        virtual void            height_field(set_k, const Url&){}

        virtual bool            height_field(disabled_k) const { return false; }
        virtual bool            height_field(settable_k) const { return false; }

        static void init_meta();
    };
}
