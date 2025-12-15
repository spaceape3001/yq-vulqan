////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/typedef/color_profile.hpp>
#include <yq/typedef/url.hpp>

namespace yq::tachyon {
    class PColorProfile;
    
    class IColorProfile {
    public:
        YQ_INTERFACE_DECLARE(IColorProfile, PColorProfile)

        virtual ColorProfileCPtr color_profile() const = 0;
        virtual Url             color_profile(url_k) const = 0;
        virtual void            color_profile(set_k, const ColorProfileCPtr&){}
        virtual void            color_profile(set_k, const Url&){}

        virtual bool            color_profile(disabled_k) const { return false; }
        virtual bool            color_profile(settable_k) const { return false; }

        static void init_meta();
    };
}
