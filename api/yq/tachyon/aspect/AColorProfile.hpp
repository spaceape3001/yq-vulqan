////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/net/Url.hpp>
#include <yq/tachyon/interface/IColorProfile.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class SetColorProfileSpecCommand;
    class SetColorProfileCommand;
    class SetColorProfileUrlCommand;

    class AColorProfile : public IColorProfile, public virtual Tachyon::Helper {
    public:
    
        ColorProfileCPtr        color_profile() const override;
        Url                     color_profile(url_k) const override;
        virtual void            color_profile(set_k, const ColorProfileCPtr&) override;
        virtual void            color_profile(set_k, const Url&) override;

        bool                    color_profile(disabled_k) const { return false; }
        bool                    color_profile(settable_k) const { return true; }

        const ColorProfileCPtr&  color_profile(ref_k) const { return m_colorProfile; }

    protected:
        ColorProfileCPtr         m_colorProfile;
        Url                     m_colorProfileUrl;
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AColorProfile();
        virtual ~AColorProfile();

        virtual void            color_profile(emit_k);
        
    private:
        void        on_set_color_profile(const SetColorProfileCommand&);
        void        on_set_color_profile_url(const SetColorProfileUrlCommand&);
        void        on_set_color_profile_spec(const SetColorProfileSpecCommand&);
        
    };

}
