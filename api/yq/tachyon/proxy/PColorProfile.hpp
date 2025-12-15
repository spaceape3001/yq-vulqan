////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/net/Url.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IColorProfile.hpp>

namespace yq::tachyon {
    class PColorProfile : public Proxy, public IColorProfile {
    public:
    
        virtual ColorProfileCPtr color_profile() const override;
        virtual Url             color_profile(url_k) const override;
        virtual void            color_profile(set_k, const ColorProfileCPtr&) override;
        virtual void            color_profile(set_k, const Url&) override;
        virtual bool            color_profile(disabled_k) const override;
        virtual bool            color_profile(settable_k) const override;


        PColorProfile(const IColorProfile&);
        virtual ~PColorProfile();
        
    private:
        ColorProfileCPtr     m_colorProfile;
        Url                 m_url;
    };
}
