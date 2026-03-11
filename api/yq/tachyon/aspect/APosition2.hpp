////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IPosition2D.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddPosition²DCommand;
    class AddPositionˣDCommand;
    class AddPositionʸDCommand;
    class MultiplyPositionDCommand;
    class MultiplyPosition²DCommand;
    class MultiplyPositionˣDCommand;
    class MultiplyPositionʸDCommand;
    class SetPosition²DCommand;
    class SetPositionˣDCommand;
    class SetPositionʸDCommand;

    class APosition² : public IPosition²D, public virtual Tachyon::Helper {
    public:
    
        //!  Basic position in the 2D space
        Vector2D        position() const override { return m_position; }
        
        double          position(x_k) const { return m_position.x; }
        double          position(y_k) const { return m_position.y; }

        //!  Set position the position (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    position(set_k, const Vector2D&) override;
        void            position(set_k, x_k, double) override;
        void            position(set_k, y_k, double) override;
        
        //!  Move the position (ie set to position + delta)
        void            position(add_k, const Vector2D&) override;
        void            position(add_k, x_k, double) override;
        void            position(add_k, y_k, double) override;

        void            position(multiply_k, double) override;
        void            position(multiply_k, const Vector2D&) override;
        void            position(multiply_k, x_k, double) override;
        void            position(multiply_k, y_k, double) override;
        
        bool            position(disabled_k) const { return false; }
        bool            position(settable_k) const { return true; }
        bool            position(addable_k) const { return true; }
        bool            position(multipliable_k) const { return true; }

        const Vector2D& position(ref_k) const { return m_position; }

    protected:

        Vector2D        m_position = ZERO;
    
        void            position(emit_k);
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        APosition²(const Vector2D& pos=ZERO);
        virtual ~APosition²();
        
    private:
        void        on_set_position2(const SetPosition²DCommand&);
        void        on_set_positionX(const SetPositionˣDCommand&);
        void        on_set_positionY(const SetPositionʸDCommand&);

        void        on_add_position2(const AddPosition²DCommand&);
        void        on_add_positionX(const AddPositionˣDCommand&);
        void        on_add_positionY(const AddPositionʸDCommand&);
        
        void        on_multiply_position(const MultiplyPositionDCommand&);
        void        on_multiply_position2(const MultiplyPosition²DCommand&);
        void        on_multiply_positionX(const MultiplyPositionˣDCommand&);
        void        on_multiply_positionY(const MultiplyPositionʸDCommand&);
    };
}
