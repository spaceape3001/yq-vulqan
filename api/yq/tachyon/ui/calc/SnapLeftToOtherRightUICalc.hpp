////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UICalc.hpp>

namespace yq::tachyon {
    class SnapLeftToOtherRightUICalc : public UICalc {
        YQ_OBJECT_DECLARE(SnapLeftToOtherRightUICalc, UICalc)
    public:
    
        SnapLeftToOtherRightUICalc(uint64_t, UIFlags flags={});
        SnapLeftToOtherRightUICalc(const SnapLeftToOtherRightUICalc&);
        virtual ~SnapLeftToOtherRightUICalc();
        SnapLeftToOtherRightUICalc* clone() const override;
        void    calculate() override;
        
        static void init_meta();
        
    private:
        uint64_t        m_bId;
    };
}
