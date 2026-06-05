////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/centimeter/IPosition2CM.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddPosition²CMCommand;
    class AddPositionˣCMCommand;
    class AddPositionʸCMCommand;
    class MultiplyPositionDCommand;
    class MultiplyPosition²DCommand;
    class MultiplyPositionˣDCommand;
    class MultiplyPositionʸDCommand;
    class SetPosition²CMCommand;
    class SetPositionˣCMCommand;
    class SetPositionʸCMCommand;

    class APosition²CM : public IPosition²CM, public virtual Tachyon::Helper {
    public:
    
        //!  Basic position in the 2D space
        Centimeter2D        position() const override { return m_position; }
        
        Centimeter           position(x_k) const { return m_position.x; }
        Centimeter           position(y_k) const { return m_position.y; }

        //!  Set position the position (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    position(set_k, const Centimeter2D&) override;
        void            position(set_k, x_k, Centimeter) override;
        void            position(set_k, y_k, Centimeter) override;
        
        //!  Move the position (ie set to position + delta)
        void            position(add_k, const Centimeter2D&) override;
        void            position(add_k, x_k, Centimeter) override;
        void            position(add_k, y_k, Centimeter) override;

        void            position(multiply_k, double) override;
        void            position(multiply_k, const Vector2D&) override;
        void            position(multiply_k, x_k, double) override;
        void            position(multiply_k, y_k, double) override;
        
        bool            position(disabled_k) const { return false; }
        bool            position(settable_k) const { return true; }
        bool            position(addable_k) const { return true; }
        bool            position(multipliable_k) const { return true; }

        const Centimeter2D& position(ref_k) const { return m_position; }

    protected:

        Centimeter2D        m_position = ZERO;
    
        void            position(emit_k);
        
        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        APosition²CM(const Centimeter2D& pos=ZERO);
        virtual ~APosition²CM();
        
    private:
        void        on_set_position2(const SetPosition²CMCommand&);
        void        on_set_positionX(const SetPositionˣCMCommand&);
        void        on_set_positionY(const SetPositionʸCMCommand&);

        void        on_add_position2(const AddPosition²CMCommand&);
        void        on_add_positionX(const AddPositionˣCMCommand&);
        void        on_add_positionY(const AddPositionʸCMCommand&);
        
        void        on_multiply_position(const MultiplyPositionDCommand&);
        void        on_multiply_position2(const MultiplyPosition²DCommand&);
        void        on_multiply_positionX(const MultiplyPositionˣDCommand&);
        void        on_multiply_positionY(const MultiplyPositionʸDCommand&);
    };
}
