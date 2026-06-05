////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/meter/IPosition2M.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddPosition²MCommand;
    class AddPositionˣMCommand;
    class AddPositionʸMCommand;
    class MultiplyPositionDCommand;
    class MultiplyPosition²DCommand;
    class MultiplyPositionˣDCommand;
    class MultiplyPositionʸDCommand;
    class SetPosition²MCommand;
    class SetPositionˣMCommand;
    class SetPositionʸMCommand;

    class APosition²M : public IPosition²M, public virtual Tachyon::Helper {
    public:
    
        //!  Basic position in the 2D space
        Vector2M        position() const override { return m_position; }
        
        Meter           position(x_k) const { return m_position.x; }
        Meter           position(y_k) const { return m_position.y; }

        //!  Set position the position (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    position(set_k, const Vector2M&) override;
        void            position(set_k, x_k, Meter) override;
        void            position(set_k, y_k, Meter) override;
        
        //!  Move the position (ie set to position + delta)
        void            position(add_k, const Vector2M&) override;
        void            position(add_k, x_k, Meter) override;
        void            position(add_k, y_k, Meter) override;

        void            position(multiply_k, double) override;
        void            position(multiply_k, const Vector2D&) override;
        void            position(multiply_k, x_k, double) override;
        void            position(multiply_k, y_k, double) override;
        
        bool            position(disabled_k) const { return false; }
        bool            position(settable_k) const { return true; }
        bool            position(addable_k) const { return true; }
        bool            position(multipliable_k) const { return true; }

        const Vector2M& position(ref_k) const { return m_position; }

    protected:

        Vector2M        m_position = ZERO;
    
        void            position(emit_k);
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        APosition²M(const Vector2M& pos=ZERO);
        virtual ~APosition²M();
        
    private:
        void        on_set_position2(const SetPosition²MCommand&);
        void        on_set_positionX(const SetPositionˣMCommand&);
        void        on_set_positionY(const SetPositionʸMCommand&);

        void        on_add_position2(const AddPosition²MCommand&);
        void        on_add_positionX(const AddPositionˣMCommand&);
        void        on_add_positionY(const AddPositionʸMCommand&);
        
        void        on_multiply_position(const MultiplyPositionDCommand&);
        void        on_multiply_position2(const MultiplyPosition²DCommand&);
        void        on_multiply_positionX(const MultiplyPositionˣDCommand&);
        void        on_multiply_positionY(const MultiplyPositionʸDCommand&);
    };
}
