////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <tachyon/interface/IColor.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    class SetColorCommand;
    
    class AColor : public IColor, public virtual Tachyon::Helper {
    public:
        
        RGBA4F  color() const override { return m_color; }

        virtual bool    color(disabled_k) const override { return false; }
        virtual bool    color(settable_k) const override { return false; }
        
        // override to accept/reject
        virtual void    color(set_k, const RGBA4F&);
        
    protected:

        RGBA4F    m_color = { 0., 0., 0., -1.};

        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        AColor();
        virtual ~AColor();
        
        void    color(emit_k);

    private:
        void    on_set_color(const SetColorCommand&);

    };
}
