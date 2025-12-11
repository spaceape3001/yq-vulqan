////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial3.hpp>
#include <yq/tachyon/aspect/ASpatial3.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

#ifdef NAN
#undef NAN
#endif

namespace yq::tachyon {
    class PitchByCommand;
    class RollByCommand;
    class RotateBy³Command;
    class SetHeadingCommand;
    class SetOrientation³Command;
    class SetPitchCommand;
    class SetRollCommand;
    class YawByCommand;
    

    /*! \brief Simple 3D Spatial
    
        This is a simple 3D spatial that has a position, scale, & orientation.
        
        \note The resulting coordinate system is north-east-down!
    */
    class SimpleSpatial³ : public Spatial³, public ASpatial³ {
        YQ_TACHYON_DECLARE(SimpleSpatial³, Spatial³);
    public:
    
        /*
            NOTE:  Scale doesn't really belong in spatials... will move it (belongs in rendereds, for sure)
        */
    
        struct Param : public Spatial³::Param {
            Param(){}
        };
    
        SimpleSpatial³(const Vector3D& pos = NAN, const Quaternion3D& ori = NAN, const Vector3D& scale = NAN, const Param& p=Param());
        ~SimpleSpatial³();
        
        static void init_meta();
        
    protected:
        void        snap(Spatial³Snap&) const;
        
    };
}
