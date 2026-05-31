////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yq/tachyon/api/Control.hpp>
#include <yq/units.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
    class PPosition³;
    
    class Position³Control : public Control {
        YQ_TACHYON_DECLARE(Position³Control, Control)
    public:
    
        //! Constructor
        //! \param[in] tacID  tachyon with the Position³ interface/proxy
        Position³Control(TachyonID tacID);
        ~Position³Control();

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
        
        PPosition³*     m_proxy;
        Vector3D        m_position;
    };
}
