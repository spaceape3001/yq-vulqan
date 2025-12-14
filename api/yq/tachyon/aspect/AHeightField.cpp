////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AHeightField.hpp"
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/asset/HeightField.hpp>
#include <yq/tachyon/command/SetHeightFieldCommand.hpp>
#include <yq/tachyon/command/SetHeightFieldSpecCommand.hpp>
#include <yq/tachyon/command/SetHeightFieldUrlCommand.hpp>
#include <yq/tachyon/event/SetHeightFieldEvent.hpp>
#include <yq/tachyon/asset/TextureInfo.hpp>

namespace yq::tachyon {
    AHeightField::AHeightField()
    {
    }
    
    AHeightField::~AHeightField()
    {
    }

    HeightFieldCPtr        AHeightField::height_field() const
    {
        return m_heightField;
    }

    Url         AHeightField::height_field(url_k) const 
    {
        return m_heightFieldUrl;
    }

    void        AHeightField::height_field(emit_k)
    {
        send(new SetHeightFieldEvent({.source=typed()}, m_heightField, m_heightFieldUrl));
    }
    
    void        AHeightField::height_field(set_k, const HeightFieldCPtr& tex) 
    {
        m_heightField           = tex;
        m_heightFieldUrl        = tex ? tex->url() : Url();
        mark();
        height_field(EMIT);
    }
    
    void        AHeightField::height_field(set_k, const Url& u)
    {
        m_heightFieldUrl    = u;
        if(u.empty()){
            m_heightField   = {};
        } else {
            m_heightField   = HeightField::IO::load(u);
            if(!m_heightField)
                tachyonWarning << "Unable to load heightfield: " << to_string(u);
        }
        mark();
        height_field(EMIT);
    }
    
    void        AHeightField::on_set_height_field(const SetHeightFieldCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        height_field(SET, cmd.height_field());
    }
    
    void        AHeightField::on_set_height_field_spec(const SetHeightFieldSpecCommand& cmd)
    {
        if(cmd.target() != typed())
            return;
        height_field(SET, Resource::resolve(cmd.spec()));
    }

    void        AHeightField::on_set_height_field_url(const SetHeightFieldUrlCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        height_field(SET, cmd.url());
    }
}
