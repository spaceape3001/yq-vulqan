////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MultiplySizeYCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MultiplySizeʸCommand)

namespace yq::tachyon {
    MultiplySizeʸCommand::MultiplySizeʸCommand(const Header& h) : 
        SizeCommand(h)
    {
    }
    
    MultiplySizeʸCommand::MultiplySizeʸCommand(const Header& h, double y) : 
        SizeCommand(h), m_δy(y)
    {
    }

    MultiplySizeʸCommand::MultiplySizeʸCommand(const MultiplySizeʸCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_δy(cp.m_δy)
    {
    }

    MultiplySizeʸCommand::~MultiplySizeʸCommand()
    {
    }

    PostCPtr    MultiplySizeʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new MultiplySizeʸCommand(*this, h);
    }
    
    void MultiplySizeʸCommand::init_meta()
    {
        auto w = writer<MultiplySizeʸCommand>();
        w.description("Multiply Size Command");
        w.property("δy", &MultiplySizeʸCommand::m_δy).tag(kTag_Log).tag(kTag_Save);
    }
}
