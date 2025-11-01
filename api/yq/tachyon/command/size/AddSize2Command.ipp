////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddSize2Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSize²Command)

namespace yq::tachyon {
    AddSize²Command::AddSize²Command(const Header&h) : SizeCommand(h)
    {
    }
    
    AddSize²Command::AddSize²Command(const Header& h, const Vector2D& v) : 
        SizeCommand(h), m_Δ(v)
    {
    }

    AddSize²Command::AddSize²Command(const AddSize²Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }
    
    AddSize²Command::~AddSize²Command()
    {
    }

    PostCPtr    AddSize²Command::clone(rebind_k, const Header&h) const 
    {
        return new AddSize²Command(*this, h);
    }
    
    void AddSize²Command::init_meta()
    {
        auto w = writer<AddSize²Command>();
        w.description("Add Size Command");
        w.property("Δx", &AddSize²Command::Δx).tag(kTag_Log);
        w.property("Δy", &AddSize²Command::Δy).tag(kTag_Log);
        w.property("Δ",  &AddSize²Command::m_Δ).tag(kTag_Save);
    }
}
