////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yq/tachyon/interface/IDrawMode.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {
    class SetDrawModeCommand;
    
    class ADrawMode : public IDrawMode, public virtual Tachyon::Helper {
    public:

        static constexpr const DrawMode     kDefDrawMode    = DrawMode::Auto;
    
        struct Param {
            DrawMode    draw_mode   = kDefDrawMode;
        };
        
        DrawMode  draw_mode() const override { return m_drawMode; }

        virtual bool    draw_mode(disabled_k) const override { return false; }
        virtual bool    draw_mode(settable_k) const override { return false; }
        
        // override to accept/reject
        virtual void    draw_mode(set_k, DrawMode);
        
    protected:


        DrawMode    m_drawMode  = kDefDrawMode;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ADrawMode(const Param&);
        ADrawMode(DrawMode dm=kDefDrawMode);
        virtual ~ADrawMode();
        
    private:
        void    on_set_draw_mode(const SetDrawModeCommand&);

    };
}
