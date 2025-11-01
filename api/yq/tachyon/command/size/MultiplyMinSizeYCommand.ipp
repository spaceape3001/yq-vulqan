////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/size/MultiplyMinSizeYCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSizeʸCommand)

namespace yq::tachyon {
    MultiplyMinSizeʸCommand::MultiplyMinSizeʸCommand(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplyMinSizeʸCommand::MultiplyMinSizeʸCommand(const Header& h, double y) : 
        SizeCommand(h), m_δy(y)
    {
    }

    MultiplyMinSizeʸCommand::MultiplyMinSizeʸCommand(const MultiplyMinSizeʸCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplyMinSizeʸCommand::~MultiplyMinSizeʸCommand()
    {
    }

    PostCPtr    MultiplyMinSizeʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSizeʸCommand(*this, h);
    }
    
    void MultiplyMinSizeʸCommand::init_meta()
    {
        auto w = writer<MultiplyMinSizeʸCommand>();
        w.description("MultiplyMin Size Command");
        w.property("δy", &MultiplyMinSizeʸCommand::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
