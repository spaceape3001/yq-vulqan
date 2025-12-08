////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Circular3LockCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Circular³LockCommand)

namespace yq::tachyon {
    Circular³LockCommand::Circular³LockCommand(const Header& h, bool _lock) : Circular³Command(h), m_lock(_lock)
    {
    }
    
    Circular³LockCommand::Circular³LockCommand(const Circular³LockCommand&cp, const Header&h) : 
        Circular³Command(cp, h), m_lock(cp.m_lock)
    {
    }

    Circular³LockCommand::~Circular³LockCommand()
    {
    }
    
    PostCPtr    Circular³LockCommand::clone(rebind_k, const Header&h) const
    {
        return new Circular³LockCommand(*this, h);
    }

    void Circular³LockCommand::init_meta()
    {
        auto w = writer<Circular³LockCommand>();
        w.description("Circular³ Lock Command");
        w.property("lock", &Circular³LockCommand::m_lock);
    }
}
