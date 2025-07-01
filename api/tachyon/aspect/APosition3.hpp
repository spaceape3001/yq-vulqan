////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/interface/IPosition3.hpp>
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddPosition³Command;
    class AddPositionˣCommand;
    class AddPositionʸCommand;
    class AddPositionᶻCommand;
    class MultiplyPositionCommand; 
    class MultiplyPosition³Command;
    class MultiplyPositionˣCommand;
    class MultiplyPositionʸCommand;
    class MultiplyPositionᶻCommand;
    class SetPosition³Command;
    class SetPositionˣCommand;
    class SetPositionʸCommand;
    class SetPositionᶻCommand;

    class APosition³ : public IPosition³, public virtual Tachyon::Helper {
    public:
    
        //!  Basic position in the 3D space
        Vector3D        position() const override { return m_position; }

        double          position(x_k) const { return m_position.x; }
        double          position(y_k) const { return m_position.y; }
        double          position(z_k) const { return m_position.z; }
        
        //!  Set position the position (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    position(set_k, const Vector3D&) override;
        void            position(set_k, x_k, double) override;
        void            position(set_k, y_k, double) override;
        void            position(set_k, z_k, double) override;
        
        //!  Add the position (ie set to position + delta)
        void            position(add_k, const Vector3D&) override;
        void            position(add_k, x_k, double) override;
        void            position(add_k, y_k, double) override;
        void            position(add_k, z_k, double) override;

        void            position(multiply_k, double) override;
        void            position(multiply_k, const Vector3D&) override;
        void            position(multiply_k, x_k, double) override;
        void            position(multiply_k, y_k, double) override;
        void            position(multiply_k, z_k, double) override;
        
        virtual bool    position(disabled_k) const override { return false; }
        virtual bool    position(settable_k) const override { return true; }
        virtual bool    position(addable_k) const override { return true; }
        virtual bool    position(multipliable_k) const override { return true; }

        const Vector3D& position(ref_k) const { return m_position; }

    protected:
        
        Vector3D    m_position = ZERO;

        template <typename C>
        static void init_info(TachyonMeta::Writer<C>&);
        
        APosition³();
        virtual ~APosition³();
        
        void        position(emit_k);

    private:
        void        on_set_position3(const SetPosition³Command&);
        void        on_set_positionX(const SetPositionˣCommand&);
        void        on_set_positionY(const SetPositionʸCommand&);
        void        on_set_positionZ(const SetPositionᶻCommand&);

        void        on_add_position3(const AddPosition³Command&);
        void        on_add_positionX(const AddPositionˣCommand&);
        void        on_add_positionY(const AddPositionʸCommand&);
        void        on_add_positionZ(const AddPositionᶻCommand&);
        
        void        on_multiply_position(const MultiplyPositionCommand&);
        void        on_multiply_position3(const MultiplyPosition³Command&);
        void        on_multiply_positionX(const MultiplyPositionˣCommand&);
        void        on_multiply_positionY(const MultiplyPositionʸCommand&);
        void        on_multiply_positionZ(const MultiplyPositionᶻCommand&);
    };
}
