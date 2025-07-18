////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <tachyon/interface/IDrawMode.hpp>
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {
    class SetDrawModeCommand;
    
    class ADrawMode : public IDrawMode, public virtual Tachyon::Helper {
    public:
        
        DrawMode  draw_mode() const override { return m_drawMode; }

        virtual bool    draw_mode(disabled_k) const override { return false; }
        virtual bool    draw_mode(settable_k) const override { return false; }
        
        // override to accept/reject
        virtual void    draw_mode(set_k, DrawMode);
        
    protected:

        static constexpr const DrawMode     kDefDrawMode    = DrawMode::Auto;

        DrawMode    m_drawMode  = kDefDrawMode;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ADrawMode();
        virtual ~ADrawMode();
        
    private:
        void    on_set_draw_mode(const SetDrawModeCommand&);

    };
}
