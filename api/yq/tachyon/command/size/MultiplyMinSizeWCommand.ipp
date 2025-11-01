////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/MultiplyMinSizeWCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSizeʷCommand)

namespace yq::tachyon {
    MultiplyMinSizeʷCommand::MultiplyMinSizeʷCommand(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplyMinSizeʷCommand::MultiplyMinSizeʷCommand(const Header&h, double x) : 
        SizeCommand(h), m_δw(x)
    {
    }

    MultiplyMinSizeʷCommand::MultiplyMinSizeʷCommand(const MultiplyMinSizeʷCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δw(cp.m_δw)
    {
    }
    
    MultiplyMinSizeʷCommand::~MultiplyMinSizeʷCommand()
    {
    }
    
    PostCPtr    MultiplyMinSizeʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSizeʷCommand(*this, h);
    }

    void MultiplyMinSizeʷCommand::init_meta()
    {
        auto w = writer<MultiplyMinSizeʷCommand>();
        w.description("MultiplyMin Size Command");
        w.property("δw", &MultiplyMinSizeʷCommand::m_δw).tag(kTag_Log).tag(kTag_Save);
    }
}
