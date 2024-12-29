////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class SetPositionᶻ : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetPositionᶻ, TachyonCommand)
    public:
        SetPositionᶻ(TachyonID, double, const Param& p={});
        ~SetPositionᶻ();
        
        static void init_info();
        
        double  z() const { return m_z; }
        
    private:
        double const  m_z;
    };
}
