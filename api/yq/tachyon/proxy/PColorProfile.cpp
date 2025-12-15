////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PColorProfile.hpp"
#include <yq/tachyon/asset/ColorProfile.hpp>
#include <yq/tachyon/command/color_profile/SetColorProfileCommand.hpp>
#include <yq/tachyon/command/color_profile/SetColorProfileUrlCommand.hpp>

namespace yq::tachyon {
    PColorProfile::PColorProfile(const IColorProfile& i) : m_colorProfile(i.color_profile()), m_url(i.color_profile(URL))
    {
        if(i.color_profile(DISABLED))
            m_flags |= F::Disabled;
        if(i.color_profile(SETTABLE))
            m_flags |= F::Settable;
    }
    
    PColorProfile::~PColorProfile()
    {
    }

    ColorProfileCPtr    PColorProfile::color_profile() const
    {
        return m_colorProfile;
    }
    
    Url     PColorProfile::color_profile(url_k) const
    {
        return m_url;
    }
    
    void    PColorProfile::color_profile(set_k, const ColorProfileCPtr& tex) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetColorProfileCommand({.target=object()}, tex));
        }
    }
    
    void    PColorProfile::color_profile(set_k, const Url& u)
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetColorProfileUrlCommand({.target=object()}, u));
        }
    }
    
    bool    PColorProfile::color_profile(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool    PColorProfile::color_profile(settable_k) const 
    {
        return m_flags(F::Settable);
    }
}
