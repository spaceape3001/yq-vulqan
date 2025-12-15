////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AColorProfile.hpp"
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/asset/ColorProfile.hpp>
#include <yq/tachyon/command/color_profile/SetColorProfileCommand.hpp>
#include <yq/tachyon/command/color_profile/SetColorProfileSpecCommand.hpp>
#include <yq/tachyon/command/color_profile/SetColorProfileUrlCommand.hpp>
#include <yq/tachyon/event/SetColorProfileEvent.hpp>
#include <yq/tachyon/asset/TextureInfo.hpp>

namespace yq::tachyon {
    AColorProfile::AColorProfile()
    {
    }
    
    AColorProfile::~AColorProfile()
    {
    }

    ColorProfileCPtr        AColorProfile::color_profile() const
    {
        return m_colorProfile;
    }

    Url         AColorProfile::color_profile(url_k) const 
    {
        return m_colorProfileUrl;
    }

    void        AColorProfile::color_profile(emit_k)
    {
        send(new SetColorProfileEvent({.source=typed()}, m_colorProfile, m_colorProfileUrl));
    }
    
    void        AColorProfile::color_profile(set_k, const ColorProfileCPtr& tex) 
    {
        m_colorProfile           = tex;
        m_colorProfileUrl        = tex ? tex->url() : Url();
        mark();
        color_profile(EMIT);
    }
    
    void        AColorProfile::color_profile(set_k, const Url& u)
    {
        m_colorProfileUrl    = u;
        if(u.empty()){
            m_colorProfile   = {};
        } else {
            m_colorProfile   = ColorProfile::IO::load(u);
            if(!m_colorProfile)
                tachyonWarning << "Unable to load heightfield: " << to_string(u);
        }
        mark();
        color_profile(EMIT);
    }
    
    void        AColorProfile::on_set_color_profile(const SetColorProfileCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        color_profile(SET, cmd.color_profile());
    }
    
    void        AColorProfile::on_set_color_profile_spec(const SetColorProfileSpecCommand& cmd)
    {
        if(cmd.target() != typed())
            return;
        color_profile(SET, Resource::resolve(cmd.spec()));
    }

    void        AColorProfile::on_set_color_profile_url(const SetColorProfileUrlCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        color_profile(SET, cmd.url());
    }
}
