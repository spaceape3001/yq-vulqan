////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LightIntensityCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LightIntensityCommand)

namespace yq::tachyon {

    LightIntensityCommand::LightIntensityCommand(const Header&h, float v) : LightCommand(h), m_intensity(v)
    {
    }

    LightIntensityCommand::LightIntensityCommand(const LightIntensityCommand& cp, const Header& h) : LightCommand(cp, h), m_intensity(cp.m_intensity)
    {
    }
    
    LightIntensityCommand::~LightIntensityCommand()
    {
    }

    PostCPtr    LightIntensityCommand::clone(rebind_k, const Header&h) const 
    {
        return new LightIntensityCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void LightIntensityCommand::init_meta()
    {
        auto w = writer<LightIntensityCommand>();
        w.description("Light Intensity Command");
        w.property("intensity", &LightIntensityCommand::m_intensity);
    }
}
