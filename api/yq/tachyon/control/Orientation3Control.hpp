////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yq/tachyon/api/Control.hpp>
#include <yq/units.hpp>
#include <yq/vector/Quaternion3.hpp>

namespace yq::tachyon {
    class POrientation³;
    
    class Orientation³Control : public Control {
        YQ_TACHYON_DECLARE(Orientation³Control, Control)
    public:
    
        //! Constructor
        //! \param[in] tacID  tachyon with the Orientation³ interface/proxy
        Orientation³Control(TachyonID tacID);
        ~Orientation³Control();

        void                set_tachyon(TachyonID);
        TachyonID           tachyon() const { return m_tachyon; }

        virtual void        imgui(ViContext&) override;
        virtual Execution   tick(const Context&) override;

        //! Resets the values (but not the tachyon ID)
        void    reset();
        
        static void init_meta();
        
    private:
        TachyonID           m_tachyon;
        const TachyonMeta*  m_info          = nullptr;
        const TachyonMeta*  m_parInfo       = nullptr;
        
        unit::Degree        m_step          = 1._deg;
        unit::Degree        m_stepFast      = 10._deg;
        
        //POrientation³*  m_proxy;
        //Quaternion3D    m_orientation;
        //unit::Degree    m_heading;
        //unit::Degree    m_pitch;
        //unit::Degree    m_roll;
        bool            m_float = false;
        
        void    imgui_content();
    };
}
