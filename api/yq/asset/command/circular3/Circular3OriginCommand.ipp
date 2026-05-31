////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Circular3OriginCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Circular³OriginCommand)

namespace yq::tachyon {
    Circular³OriginCommand::Circular³OriginCommand(const Header& h, const Vector3D& _origin) : Circular³Command(h), m_origin(_origin)
    {
    }
    
    Circular³OriginCommand::Circular³OriginCommand(const Circular³OriginCommand&cp, const Header&h) : 
        Circular³Command(cp, h), m_origin(cp.m_origin)
    {
    }

    Circular³OriginCommand::~Circular³OriginCommand()
    {
    }
    
    PostCPtr    Circular³OriginCommand::clone(rebind_k, const Header&h) const
    {
        return new Circular³OriginCommand(*this, h);
    }

    void Circular³OriginCommand::init_meta()
    {
        auto w = writer<Circular³OriginCommand>();
        w.description("Circular³ Origin Command");
        w.property("origin", &Circular³OriginCommand::m_origin);
    }
}
