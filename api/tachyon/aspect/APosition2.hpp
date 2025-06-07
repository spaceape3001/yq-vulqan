////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/interface/IPosition2.hpp>
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddPosition²Command;
    class AddPositionˣCommand;
    class AddPositionʸCommand;
    class MultiplyPositionCommand;
    class MultiplyPosition²Command;
    class MultiplyPositionˣCommand;
    class MultiplyPositionʸCommand;
    class SetPosition²Command;
    class SetPositionˣCommand;
    class SetPositionʸCommand;

    class APosition² : public IPosition², public virtual Tachyon::Helper {
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

        Vector2D        m_position = ONE;
    
        void            position(emit_k);
        
        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        APosition²();
        virtual ~APosition²();
        
    private:
        void        on_set_position2(const SetPosition²Command&);
        void        on_set_positionX(const SetPositionˣCommand&);
        void        on_set_positionY(const SetPositionʸCommand&);

        void        on_add_position2(const AddPosition²Command&);
        void        on_add_positionX(const AddPositionˣCommand&);
        void        on_add_positionY(const AddPositionʸCommand&);
        
        void        on_multiply_position(const MultiplyPositionCommand&);
        void        on_multiply_position2(const MultiplyPosition²Command&);
        void        on_multiply_positionX(const MultiplyPositionˣCommand&);
        void        on_multiply_positionY(const MultiplyPositionʸCommand&);
    };
}
