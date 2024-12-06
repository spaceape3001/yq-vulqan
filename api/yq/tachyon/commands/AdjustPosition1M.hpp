////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/vector/Vector1.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AdjustPosition1M : public TachyonCommand {
        YQ_OBJECT_DECLARE(AdjustPosition1M, TachyonCommand)
    public:
        AdjustPosition1M(TachyonID, const Vector1M&, const Param& p={});
        ~AdjustPosition1M();
    
        const Vector1M&   position() const  { return m_position; }
        
        static void init_info();
        
        Meter  x() const { return m_position.x; }
        
    private:
        Vector1M const  m_position;
    };
}
