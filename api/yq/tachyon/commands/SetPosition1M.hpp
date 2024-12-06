////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition1M : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetPosition1M, TachyonCommand)
    public:
        SetPosition1M(TachyonID, const Vector1M&, const Param& p={});
        ~SetPosition1M();
    
        const Vector1M&   position() const  { return m_position; }
        
        static void init_info();
        
        Meter  x() const { return m_position.x; }
        
    private:
        Vector1M const  m_position;
    };
}
