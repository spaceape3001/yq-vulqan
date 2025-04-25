////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/OrientationCommand.hpp>
#include <yq/unit/declare.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {

    //! Instructs an object to pitch (ie, around the local body Y-axis) by the given amount
    class PitchBy : public OrientationCommand {
        YQ_OBJECT_DECLARE(PitchBy, OrientationCommand)
    public:
        PitchBy(const Header&, Radian θ);
    
        static void init_info();
        
        Radian  θ() const { return m_θ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        PitchBy(const PitchBy&, const Header&);
        ~PitchBy();
        
    private:
        Radian const  m_θ;
        
        PitchBy(const PitchBy&);
        PitchBy(PitchBy&&);
        PitchBy& operator=(const PitchBy&);
        PitchBy& operator=(PitchBy&&);
    };
}
