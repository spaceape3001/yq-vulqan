////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/OrientationCommand.hpp>
#include <yq/unit/declare.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {

    //! Instructs an object to pitch (ie, around the local body Y-axis) by the given amount
    class PitchByCommand : public OrientationCommand {
        YQ_OBJECT_DECLARE(PitchByCommand, OrientationCommand)
    public:
        PitchByCommand(const Header&, Radian θ);
    
        static void init_meta();
        
        Radian  θ() const { return m_θ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        PitchByCommand(const PitchByCommand&, const Header&);
        ~PitchByCommand();
        
    private:
        Radian const  m_θ;
        
        PitchByCommand(const PitchByCommand&);
        PitchByCommand(PitchByCommand&&);
        PitchByCommand& operator=(const PitchByCommand&);
        PitchByCommand& operator=(PitchByCommand&&);
    };
}
