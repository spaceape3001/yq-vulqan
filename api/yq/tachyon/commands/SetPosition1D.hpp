////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition1D : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetPosition1D, TachyonCommand)
    public:
        SetPosition1D(TachyonID, const Vector1D&, const Param& p={});
        ~SetPosition1D();
    
        const Vector1D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        
    private:
        Vector1D const  m_position;
    };
}
