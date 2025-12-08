////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Circular3RadiusCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Circular³RadiusCommand)

namespace yq::tachyon {
    Circular³RadiusCommand::Circular³RadiusCommand(const Header& h, double _radius) : Circular³Command(h), m_radius(_radius)
    {
    }
    
    Circular³RadiusCommand::Circular³RadiusCommand(const Circular³RadiusCommand&cp, const Header&h) : 
        Circular³Command(cp, h), m_radius(cp.m_radius)
    {
    }

    Circular³RadiusCommand::~Circular³RadiusCommand()
    {
    }
    
    PostCPtr    Circular³RadiusCommand::clone(rebind_k, const Header&h) const
    {
        return new Circular³RadiusCommand(*this, h);
    }

    void Circular³RadiusCommand::init_meta()
    {
        auto w = writer<Circular³RadiusCommand>();
        w.description("Circular³ Radius Command");
        w.property("radius", &Circular³RadiusCommand::m_radius);
    }
}
