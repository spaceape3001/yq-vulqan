////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/interfaces/IPosition2.hpp>
#include <yt/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddPosition²;
    class AddPositionˣ;
    class AddPositionʸ;
    class MultiplyPosition;
    class MultiplyPosition²;
    class MultiplyPositionˣ;
    class MultiplyPositionʸ;
    class SetPosition²;
    class SetPositionˣ;
    class SetPositionʸ;

    class APosition² : public IPosition², private Tachyon::Helper {
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
        void        on_set_position2(const SetPosition²&);
        void        on_set_positionX(const SetPositionˣ&);
        void        on_set_positionY(const SetPositionʸ&);

        void        on_add_position2(const AddPosition²&);
        void        on_add_positionX(const AddPositionˣ&);
        void        on_add_positionY(const AddPositionʸ&);
        
        void        on_multiply_position(const MultiplyPosition&);
        void        on_multiply_position2(const MultiplyPosition²&);
        void        on_multiply_positionX(const MultiplyPositionˣ&);
        void        on_multiply_positionY(const MultiplyPositionʸ&);
    };
}
