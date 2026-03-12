////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplyMinSizeWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplyMinSizeʷDCommand)

namespace yq::tachyon {
    MultiplyMinSizeʷDCommand::MultiplyMinSizeʷDCommand(const Header&h) : 
        SizeCommand(h)
    {
    }

    MultiplyMinSizeʷDCommand::MultiplyMinSizeʷDCommand(const Header&h, double x) : 
        SizeCommand(h), m_δw(x)
    {
    }

    MultiplyMinSizeʷDCommand::MultiplyMinSizeʷDCommand(const MultiplyMinSizeʷDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δw(cp.m_δw)
    {
    }
    
    MultiplyMinSizeʷDCommand::~MultiplyMinSizeʷDCommand()
    {
    }
    
    PostCPtr    MultiplyMinSizeʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplyMinSizeʷDCommand(*this, h);
    }

    void MultiplyMinSizeʷDCommand::init_meta()
    {
        auto w = writer<MultiplyMinSizeʷDCommand>();
        w.description("MultiplyMin Size DCommand");
        w.property("δw", &MultiplyMinSizeʷDCommand::m_δw).tag(kTag_Log).tag(kTag_Save);
    }
}
