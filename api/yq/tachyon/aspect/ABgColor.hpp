////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IBgColor.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    class SetBgColorCommand;
    
    class ABgColor : public IBgColor, public virtual Tachyon::Helper {
    public:
        
        RGBA4F  bgcolor() const override { return m_bgcolor; }

        virtual bool    bgcolor(disabled_k) const override { return false; }
        virtual bool    bgcolor(settable_k) const override { return false; }
        
        // override to accept/reject
        virtual void    bgcolor(set_k, const RGBA4F&);
        
    protected:
    
        static constexpr const RGBA4F kDefBgColor = {0., 0., 0., 1.};
        RGBA4F    m_bgcolor     = kDefBgColor;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ABgColor();
        virtual ~ABgColor();
        
        void    bgcolor(emit_k);

    private:
        void    on_set_bgcolor(const SetBgColorCommand&);

    };
}
