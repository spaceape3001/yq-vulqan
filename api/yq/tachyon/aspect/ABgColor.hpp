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
        
        static constexpr const RGBA4F kDefBgColor = {0., 0., 0., 1.};
        
        struct Param {
            RGBA4F      bgcolor = kDefBgColor;
        };

        RGBA4F  bgcolor() const override { return m_bgcolor; }

        virtual bool    bgcolor(disabled_k) const override { return false; }
        virtual bool    bgcolor(settable_k) const override { return true; }
        
        // override to accept/reject
        virtual void    bgcolor(set_k, const RGBA4F&);
        
    protected:
    
        RGBA4F    m_bgcolor;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ABgColor(const Param&);
        ABgColor(const RGBA4F& bgColor = kDefBgColor);
        virtual ~ABgColor();
        
        virtual void    bgcolor(emit_k);

    private:
        void    on_set_bgcolor(const SetBgColorCommand&);

    };
}
