////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LightColorCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LightColorCommand)

namespace yq::tachyon {

    LightColorCommand::LightColorCommand(const Header&h, const RGB3F& c) : LightCommand(h), m_color(c)
    {
    }

    LightColorCommand::LightColorCommand(const LightColorCommand& cp, const Header& h) : 
        LightCommand(cp, h), m_color(cp.m_color)
    {
    }
    
    LightColorCommand::~LightColorCommand()
    {
    }

    PostCPtr    LightColorCommand::clone(rebind_k, const Header&h) const 
    {
        return new LightColorCommand(*this, h);
    }

    void    LightColorCommand::set_color(const RGB3F&v)
    {
        m_color = v;
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void LightColorCommand::init_meta()
    {
        auto w = writer<LightColorCommand>();
        w.description("Light Color Command");
        w.property("color", &LightColorCommand::m_color).tag({kTag_Save, kTag_Log});
    }
}
