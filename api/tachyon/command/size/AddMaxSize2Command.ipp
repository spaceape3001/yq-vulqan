////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddMaxSize2Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSize²Command)

namespace yq::tachyon {
    AddMaxSize²Command::AddMaxSize²Command(const Header&h) : SizeCommand(h)
    {
    }
    
    AddMaxSize²Command::AddMaxSize²Command(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddMaxSize²Command::AddMaxSize²Command(const AddMaxSize²Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddMaxSize²Command::~AddMaxSize²Command()
    {
    }

    PostCPtr    AddMaxSize²Command::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSize²Command(*this, h);
    }
    
    void AddMaxSize²Command::init_info()
    {
        auto w = writer<AddMaxSize²Command>();
        w.description("AddMax Size Command");
        w.property("Δx", &AddMaxSize²Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddMaxSize²Command::Δy).tag(kTag_Log);
        w.property("Δ",  &AddMaxSize²Command::m_Δ).tag(kTag_Save);
    }
}
